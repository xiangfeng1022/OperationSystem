#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <wait.h>

#define BUFFER_SIZE 32
int main()
{
    int ret = access("./testfifo", F_OK);
    if (ret == -1)
    {
        perror("access error");
        exit(-1);
    }

    /* 程序执行到这里，说明fifo文件一定存在 */
    int fd = open("./testfifo", O_RDWR | O_NONBLOCK); /* 设置非阻塞 */
    if (fd == -1)
    {
        perror("open error");
        _exit(-1);
    }

    char buf[BUFFER_SIZE];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        int bytes = read(fd, buf, sizeof(buf) - 1);
        if (bytes < 0)
        {
            perror("read error");
            close(fd); /* 读失败也要关闭文件 不能直接exit退出 */
            _exit(-1);
        }
        printf("buf:%s\n", buf);
        sleep(4);
    }
    close(fd);

    return 0;
}