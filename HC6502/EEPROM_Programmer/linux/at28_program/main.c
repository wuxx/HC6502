#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <assert.h>
#include <getopt.h>

extern int serial_init();
extern int32_t serial_send(char *buf, uint32_t len);
extern int32_t serial_recv(char *buf, uint32_t len);

void usage(char *program_name)
{
    printf("usage: %s [OPTION] \n", program_name);
    fputs (("\
             -a | --target-addr             target addr                                  \n\
             -c | --block-count             write block-count                            \n\
             -d | --device                  serial device                                \n\
             -g | --group-size              write group size                             \n\
             -i | --input                   input binary file                            \n\
             -n | --recon                   just print                                   \n\
             -t | --test                    test                                         \n\
             -h | --help                    display help info                            \n\n\
"), stdout);
    exit(0);
}

static struct option const long_options[] =
{
  {"block-count", required_argument,        NULL, 'c'},
  {"device",      required_argument,        NULL, 'd'},
  {"input",       required_argument,        NULL, 'i'},
  {"target-addr", required_argument,        NULL, 'a'},
  {"group-size",  required_argument,        NULL, 'g'},
  {"recon",       required_argument,        NULL, 'n'},
  {"test",        no_argument,              NULL, 't'},
  {"help",        no_argument,              NULL, 'h'},
};

char sys_banner[] = {"buildtime [" __TIME__ " " __DATE__ "] "};

char ser_recv_buf[2048];
char ser_send_buf[1024];

uint16_t cksum(uint8_t *buf, uint32_t size)
{
    uint32_t i;
    uint16_t sum = 0;
    for(i = 0; i < size; i++) {
        sum += buf[i];
    }

    return sum;
}

int main(int argc, char **argv)
{
    int i, x, count, r;
    uint32_t len = 0;
    int32_t c;
    int32_t option_index;
    char *device = "/dev/ttyS0";
    char *ifile = NULL;

    int ifd;
 	struct stat ist;
    uint8_t *ibuf;

    uint32_t target_addr = 0;

    int test = 0;
    int justprint = 0;

    uint32_t group_size = 256;

    uint32_t bc = 0, write_block_count = 0;
    uint32_t total = 0, succ = 0, fail = 0, skip = 0;

    while ((c = getopt_long (argc, argv, "a:c:d:g:i:hnt",
                long_options, &option_index)) != -1) {
        switch (c) {
            case ('a'):
                target_addr = strtoul(optarg, NULL, 0);
                break;
            case ('c'):
                write_block_count = strtoul(optarg, NULL, 0);
                break;
            case ('d'):
                device = optarg;
                break;
            case ('i'):
                ifile = optarg;
                break;
            case ('t'):
                test = 1;
                break;
            case ('n'):
                justprint = 1;
                break;
            case ('g'):
                group_size = strtoul(optarg, NULL, 0);
                break;
            case ('h'):
                usage(argv[0]);
                break;
            default:
                usage(argv[0]);
                break;
        }
    }

    printf("%s\n", sys_banner);

    if (argc == 1) {
        usage(argv[0]);
        exit(0);
    }

    if (!justprint) {
        if(serial_init(device) == -1)
        {
            printf("serialinit fail!\n");
            exit(0);
        }

    }

    if (test) {
        len += sprintf(ser_send_buf, "\r\nhelp\r\n");

        printf("send [%s]\n", ser_send_buf);

        serial_send(ser_send_buf, len);

        serial_recv(ser_recv_buf, sizeof(ser_recv_buf));

        printf("recv [%s]\n", ser_recv_buf);

        exit(0);
    }

#if 0
    char *cmd = "help\r\n";
    serial_send(cmd, strlen(cmd));

    serial_recv(ser_recv_buf, sizeof(ser_recv_buf));
    printf("recv [%s]\n", ser_recv_buf);

#endif
    if ((ifd = open(ifile, O_RDWR)) == -1) {
        perror("open");
        exit(-1);
    }

    if ((fstat(ifd, &ist)) == -1) {
        perror("fstat");
        exit(-1);
    }

    if (ist.st_size > (32 * 1024)) {
        printf("ifile must less than 32K\n");
        exit(-1);
    }

    if ((ibuf = mmap(0, ist.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, ifd, 0)) == MAP_FAILED) {
        perror("mmap");
        exit(-1);
    }

//#define GROUP_SIZE  (64)

    count = ist.st_size / group_size;
    r = ist.st_size % group_size;

    assert(r == 0);

    if (write_block_count == 0) {
        write_block_count = count;
    }


    for(i = 0; i < (count * group_size); i += group_size) {

        len = 0;
        memset(ser_send_buf, 0, sizeof(ser_send_buf));

        len += sprintf(ser_send_buf, "at28 prog 0x%04x %d ", target_addr + i, group_size);

        for(x = 0; x < group_size; x++) {
            len += sprintf(&ser_send_buf[len], "%02x", ibuf[i + x]);
        }

        len += sprintf(&ser_send_buf[len], " 0x%04x\r\n", cksum(&ibuf[i], group_size));

        if (justprint) {
            printf("%s", ser_send_buf);
        } else {
             
            /* need to write the last block */
            if ((bc < write_block_count) || (bc == (count - 1))) {

                printf("cmd [%s]\n", ser_send_buf);
                serial_send(ser_send_buf, len);
                usleep(4000000);
                serial_recv(ser_recv_buf, sizeof(ser_recv_buf));

                printf("recv [%s]\n", ser_recv_buf);
                if (strstr(ser_recv_buf, "prog succ!") != NULL) {
                    printf("__SUCC__\n");
                    succ++;
                } else {
                    printf("__FAIL__\n");
                    fail++;
                    exit(-1);
                }

            } else {
                printf("skip [%s]\r\n", ser_send_buf);
                skip++;
            }

        }

        bc++;
        total++;

    }
    printf("PROG DONE: total [%d]; succ [%d]; fail [%d] skip [%d]\n", total, succ, fail, skip);

#if 0
    if (r != 0) {
        len = 0;
        memset(ser_send_buf, 0, sizeof(ser_send_buf));

        len += sprintf(ser_send_buf, "at28 prog 0x%04x %d ", target_addr + i, r);

        for(x = 0; x < r; x++) {
            len += sprintf(&ser_send_buf[len], "%02x", ibuf[i + x]);
        }

        len += sprintf(&ser_send_buf[len], " 0x%04x\r\n", cksum(&ibuf[i], group_size));

        if (justprint) {
            printf("%s\n", ser_send_buf);
        } else {
            printf("cmd [%s]\n", ser_send_buf);
            serial_send(ser_send_buf, len);

            serial_recv(ser_recv_buf, sizeof(ser_recv_buf));

            printf("recv [%s]\n", ser_recv_buf);

        }


    }
#endif

    

    munmap(ibuf, ist.st_size);
    close(ifd);

    return 0;
}

