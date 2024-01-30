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
        /* FIFO文件 不存在 */
        /* 有名管道 */
        ret = mkfifo("./testfifo", 0644);
        if (ret == -1)
        {
            perror("mkfifo error");
            _exit(-1);
        }
    }

    int fd = open("./testfifo", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
        _exit(-1);
    }

    char buf[BUFFER_SIZE];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        strncpy(buf, "helloworld", sizeof(buf) - 1);
        /* 调用 write() 函数将数组 buf 中的内容写入文件描述符 fd 所代表的文件 */
        write(fd, buf, strlen(buf));
        sleep(3);
    }

    close(fd);

    return 0;
}