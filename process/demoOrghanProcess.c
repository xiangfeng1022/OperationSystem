/* 孤儿进程: 父进程运行结束，但子进程还在运行（未运行几位数)的子进程就称为孤儿进程*/
/* 僵尸进程: 进程终止，父进程尚未回收， 子进程残留资源(pcb)存放于内核中，变成僵尸进程 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <wait.h>

/* 阻塞: 后面的程序就执行不了
    wait()函数的主要功能为回收已经结束子进程的资源 
    waitpid()函数等待子进程终止，如果子进程终止了， 此函数会回收子进程的资源 */

/* 父子进程的地址空间是独立的 通信不起来 如果想要建立通信 就得借助其他方式 */
int main()
{
#if 0
    printf("hello world\n");
  
    /* 当进程没有子进程的时候 */
    wait(NULL);
    printf("hello world\n");
#endif
    int num = 100;
    /* 创建一个子进程 */
    pid_t pid = fork();
    /* 创建完子进程后，父进程不会自杀 */

    if (pid < 0)
    {
        perror("fork error");
        // return 0;
        _exit(0); //进程退出函数
    }
    if (pid == 0)
    {
        /* 子进程 */
        pid_t childPid = getpid();
        printf("child process: childPid: %d, num:%d\n", childPid, num);
        
        while (1)
        {
           sleep(2);
           printf("orphan process\n");
        }
        
        /* 进程退出 */
        int childStae = 1;
        _exit(0);
    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parent process: parentPid: %d, num:%d\n", parentPid, num);
    }

    printf("hello world\n");
    return 0;
}