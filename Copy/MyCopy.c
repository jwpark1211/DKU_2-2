/* mycp program, by parkjw. 1211abc@naver.com*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 64
void perror(const char* s);

int main(int argc, char* argv[])
{
    int i_fd, o_fd, read_size, write_size;
    struct stat sts;
    char buf[MAX_BUF];

    if (argc != 3) {
        printf("USAGE: %s file_name\n", argv[0]); exit(-1);
    }
    if ((access(argv[2], F_OK)) != -1)
    {
        printf("같은 이름의 파일이 이미 존재합니다. \n"); exit(-1);
    }

    i_fd = open(argv[1], O_RDONLY);
    fstat(i_fd, &sts);

    o_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, sts.st_mode);

    //오류처리구간
    if (i_fd < 0) {
        perror("open");
        exit(1);
    }
    if (o_fd < 0) {
        perror("open");
        exit(1);
    }
    while (1) {
        read_size = read(i_fd, buf, MAX_BUF);
        if (read_size == 0)
            break;
        write_size = write(o_fd, buf, read_size);
    }

    close(i_fd);
    close(o_fd);
}
