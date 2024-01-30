#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <wait.h>

/* 阻塞: 后面的程序就执行不了
    wait()函数的主要功能为回收已经结束子进程的资源 
    waitpid()函数等待子进程终止，如果子进程终止了， 此函数会回收子进程的资源 */

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
        _exit(0);
    }
    if (pid == 0)
    {
        /* 子进程 */
        pid_t childPid = getpid();
        printf("child process: childPid: %d, num:%d\n", childPid, num);

        sleep(1);

        int childStae = 1;
        _exit(childStae);
    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parent process: parentPid: %d, num:%d\n", parentPid, num);
    }
    
    /* 父进程阻塞等待回收子进程的资源 */
    /* 返回值是: 回收的子进程ID号 */
    int status = 0;
    pid_t waitPid = wait(&status);
    int ret = WEXITSTATUS(status);
    printf("pidd:%d\n", waitPid);
    printf("status:%d\n", status);
    printf("ret:%d\n", ret);

    printf("hello world\n");
    return 0;
}
