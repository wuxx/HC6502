import sys
import time
import serial
total_size = 32768  # 输入文件大小
block_size = 64     # 分块大小，应能整除输入文件大小
try_num = 4         # 单块重试最大次数


def receive_message(ser):
    buffer = bytearray()
    rec = b''
    # 接收字符直到遇到'#'
    while rec != b'#':
        rec = ser.read()
        buffer.append(rec[0])
    # 解码并分行
    ret = buffer.decode("ascii").splitlines()
    # 去掉第一行命令回显、倒数第二行空行、倒数第一行"pos#"
    return ret[1:-2]


def dump_bytes(ser, addr, size):
    send_str = "at28 dump 0x{0:0>4x} {1:d}\r\n".format(addr, size)
    # 计算出的校验和与接收到的校验和
    clac_sum, recv_sum = 233, 666
    ret_bytes = bytes()
    # 若两者不同，则认为接收过程出现问题，重新接收
    while clac_sum != recv_sum:
        ser.write(send_str.encode("ascii"))
        recv = receive_message(ser)
        ret_bytes = bytes()
        # 一行有8个数据，所以循环size/8的上取整次
        for i in range(0, (size + 7) // 8):
            # 取":'右边的内容，去除所有"0x"，将十六进制字符串转为字节串
            ret_bytes += bytes.fromhex(recv[i].split(":")[1].replace("0x", ""))
        clac_sum = sum(ret_bytes) & 0xFFFF
        # 倒数第二行为接收到的校验和，倒数一行为"return 0x0"
        recv_sum = int(recv[-2].split(":")[1], 16)
    return ret_bytes


def prog_bytes(ser, addr, size, data):
    send_str = "at28 prog 0x{0:0>4x} {1:d} {2:s} 0x{3:0>4x}\r\n".format(addr, size, data.hex(), sum(data) & 0xFFFF)
    #print(send_str)
    ser.write(send_str.encode("ascii"))
    recv = receive_message(ser)
    return recv[0] == "prog succ!"


# 检查输入参数
if len(sys.argv) != 3:
    print("Usage: python {0:s} FILE PORT".format(sys.argv[0].split("/")[-1]))
    exit(1)
# 读取文件并检查大小
with open(sys.argv[1], "rb") as file:
    firmware = file.read()
    if len(firmware) != total_size:
        print("Input file size != {0:d}, now exit...".format(total_size))
        exit(1)
time_start = time.time()
succ_cnt, fail_cnt, skip_cnt = 0, 0, 0
ser_port = serial.Serial(sys.argv[2], 115200, timeout=None)
for i in range(total_size // block_size):
    print(i)
    address = block_size * i
    block = firmware[address: address + block_size]
    old_block = dump_bytes(ser_port, address, block_size)
    if old_block != block:
        try_cnt = 0
        succ_flag = False
        while (not succ_flag) and try_cnt < try_num:
            succ_flag = prog_bytes(ser_port, address, block_size, block)
            try_cnt += 1
        if succ_flag:
            succ_cnt += 1
        else:
            fail_cnt += 1
            print("Failed in program address: 0x{0:0>4x}".format(address))
    else:
        skip_cnt += 1
ser_port.close()
using_time = time.time() - time_start
print("Total: {0:d}, Succ: {1:d}, Fail: {2:d}, Skip: {3:d}".
      format(succ_cnt + fail_cnt + skip_cnt, succ_cnt, fail_cnt, skip_cnt))
print("Using time: {0:d}min {1:d}sec".format(int(using_time / 60), int(using_time % 60)))
