#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{   
    /* 创建一个进程 */
    pid_t pid = fork();
    if (pid < 0)
    {
        perror ("fork error");
        exit(-1); /* 库函数  在<stdlib.h>  _exit()系统调用 在<unistd.h>里 */
    } 
    if (pid == 0)
    {
        /* 子进程 */
        pid_t childPid = getpid();
        printf("child process : %d\n", childPid);

        /* 子进程退出 */
        _exit(0);
    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parent process : %d\n", parentPid);

    }

    printf("hello world\n");
    return 0;
}