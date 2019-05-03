#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

//#define WAIT_TIMEOUT    (5 * 60)
#define WAIT_TIMEOUT    (2)

#define BAUDRATE B115200 ///Baud rate : 115200
//#define BAUDRATE B460800
//#define DEVICE "/dev/ttyUSB0"
#define DEVICE "/dev/ttyS1"
#define RSIZE 1024

void dump_byte(char *buf, uint32_t len)
{
    int i = 0;
    printf("[0x%08x]: ", i);
    for(; i < len; i++) {

        if (i != 0 && (i % 8 == 0)) {
            printf("\n[0x%08x]: ", i);
        }

        printf("0x%02x ", buf[i]);
    }
    printf("\n");
}

void cfmakeraw(struct termios *termios_p);

int bindex = 0;
char buffer_cache[4096] = {0};

int sfd = 0;

struct termios st_new;
struct termios st_old;

/* block send */
int32_t serial_send(char *buf, uint32_t len)
{
    uint32_t i;
    uint32_t count = 0;

    if((fcntl(sfd, F_SETFL, 0)) < 0 )
    {
        printf("fcntl F_SETFL fail!\n");
        return -1;
    }

#if 0
    printf("%s:\n", __func__);
    for(i = 0; i < len; i++) {
        printf("[%d]: %02x [%c]\n", i, buf[i], buf[i]);
    }
#endif

    for(i = 0; i < len; i++) {
        count = write(sfd, &buf[i], 1);
        usleep(10000);
    }

    return count;
}

int32_t serial_recv(uint8_t *buf, uint32_t len)
{

#if 0
    if( (fcntl(sfd, F_SETFL, O_NONBLOCK)) < 0 )
    {
        perror("fcntl F_SETFL fail!\n");
        return -1;
    }
#endif

    fd_set rfds;
    struct timeval timeout;

    memset(buf, 0, len);
    timeout.tv_sec  = WAIT_TIMEOUT;
    timeout.tv_usec = 0;

    FD_ZERO(&rfds);

    FD_SET(sfd, &rfds);

    switch(select(sfd + 1, &rfds, NULL, NULL, &timeout)) {
        case -1:
            printf("fail: select error!\n");
            return -1;
            break;
        case 0: /* timeout */
            printf("select timeout!\n");
            printf("wait serial recv timeout, ignore.\n");
            return -1;
            break;
        default:
            //printf("select succ\n");
            break;
    }


    usleep(300 * 1000); /* wait  for driver to recv the total data */

    return read(sfd, buf, len);
}

//open port & set port
int serial_init(char *dev)
{
    printf("%s [%s]...\n", __func__, dev);

    sfd = open(dev, O_RDWR|O_NOCTTY|O_NDELAY);
    if(sfd == -1)
    {
        perror("open serial port fail!\n");
        return -1;
    }

    if( (fcntl(sfd, F_SETFL, O_NONBLOCK)) < 0 )
    {
        perror("fcntl F_SETFL fail!\n");
        return -1;
    }

    if(tcgetattr(sfd, &st_old) != 0)
    {
        perror("tcgetattr fail!\n");
        return -1;
    }

    st_new = st_old;
    cfmakeraw(&st_new);//将终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理

    //set speed
    cfsetispeed(&st_new, BAUDRATE);//115200
    cfsetospeed(&st_new, BAUDRATE);

    //set databits
    st_new.c_cflag |= (CLOCAL|CREAD);
    st_new.c_cflag &= ~CSIZE;
    st_new.c_cflag |= CS8;

    //set parity
    st_new.c_cflag &= ~PARENB;
    st_new.c_iflag &= ~INPCK;

    //set stopbits
    st_new.c_cflag &= ~CSTOPB;
    st_new.c_cc[VTIME]=0;    //指定所要读取字符的最小数量
    st_new.c_cc[VMIN]=1;     //指定读取第一个字符的等待时间，时间的单位为n*100ms
                            //如果设置VTIME=0，则无字符输入时read（）操作无限期的阻塞
    tcflush(sfd,TCIFLUSH);  //清空终端未完成的输入/输出请求及数据。
    if( tcsetattr(sfd,TCSANOW,&st_new) != 0 )
    {
        perror("tcsetattr fail!\n");
        return -1;
    }

    return 0;
}

#if 0
int main(int argc, char **argv)
{
    int nret = 0;
    int count = 0;
    char recv_buf[RSIZE];
    struct tlv *ptlv;

    int buf[16] = {0x1, 0x4, 0x12345678, 0x12345678};

    int i;
    int ifd;
    struct stat st;
    uint8_t *mbuf;

    uint32_t crc0, crc1;

    if(serial_init() == -1)
    {
        error("serialinit fail!\n");
    }

    serial_send((uint8_t *)buf, 16);

    //close(sfd);
    return 0;

}
#endif
