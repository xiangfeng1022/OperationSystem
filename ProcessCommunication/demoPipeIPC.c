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
 
    int pipefd[PIPE_SIZE];
    memset(pipefd, 0, sizeof(int) * PIPE_SIZE);

    /* 创建管道  无名管道 只能在具有公共祖先的进程之间使用
    (父进程与子进程 两个兄弟进程 具有亲缘关系)*/
    pipe(pipefd);

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        _exit(-1);
    }

    if (pid == 0)
    {
        /* 子进程写  关闭子进程的读端 */
        close(pipefd[0]);

        /* 子进程fd[1]写端  父进程fd[0]读端 */
        sleep(5);
        int num = 200;
        write(pipefd[1], (void *)&num, sizeof(int));
        
#if 0
        /* 这个用法不对 */
        int childReadNum = 0;
        read(pipefd[0], (void *)&childReadNum, sizeof(int));
        printf("child process : childReadNum : %d\n", childReadNum);
#endif
        /* 关闭写端 */
        close(pipefd[1]);
    }

    else if (pid > 0)
    {   
        sleep(1);

        /* 父进程读 关闭父进程的写端 */
        close(pipefd[1]);

        /* 父进程 fd[0]读端 */

        /* 把read设置为非阻塞 */
        /*1、 拿到当前文件描述符的标记 */
        int flag = fcntl(pipefd[0], F_GETFL);

        /* 2、或上O_NONBLOCK */
        flag |= O_NONBLOCK;

        /* 3、用新的标记设置文件描述符 */
        fcntl(pipefd[0], F_GETFL, flag);

        int readNum = 0;
        read(pipefd[0], (void *)&readNum, sizeof(int));
        printf("parent process : readNum : %d\n", readNum);

        /* 关闭读端 */
        close(pipefd[0]);
        _exit(0);
    }
        
    while (1)
    {
        sleep(3);
    }
}