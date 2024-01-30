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

#define PIPE_SIZE 2
int main()
{   
    /* pipefd是一个整型数组，用于存储管道的文件描述符 */
    int pipefd[PIPE_SIZE];
    memset(pipefd, 0, sizeof(pipefd));
    /* 创建管道  pipefd[0] 表示管道的读端文件描述符，
                pipefd[1] 表示管道的写端文件描述符。*/
    pipe(pipefd);
    
    /* 查看管道缓冲区函数 fpathconf*/
    long bufferSize = fpathconf(pipefd[0], _PC_PIPE_BUF);
    printf("bufferSize:%ld\n", bufferSize);
    
    bufferSize = fpathconf(pipefd[1], _PC_PIPE_BUF);
    printf("bufferSize:%ld\n", bufferSize);
    
    return 0;
}