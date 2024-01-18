#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main()
{   
#if 0
    pid_t currentPid = getpid();
    pid_t parentPid = getppid();

    printf("currentPid:%d\n", currentPid);
    printf("parentPid:%d\n", parentPid);

    pid_t process = fork();
    while (1)
    {
        printf("hello world\n"); /* 要加 \n 因为输出有行缓存 */

        sleep(3);
    }
#endif

    int num = 100;
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        return 0;
    }
    if (pid == 0)
    {   
        /* 休眠1s 让出CPU 目的是：让父进程先执行完 num */
        sleep(1);

        /* 子进程 */
        pid_t childPid = getpid();
        printf("child process: childPid: %d, num:%d\n", childPid, num);

        // pid_t parentPid = getppid();
        // printf("child process: parentPid: %d\n", parentPid);
    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parent process: parentPid: %d, num:%d\n", parentPid, num);
        num += 100;
         printf("parent process: parentPid: %d, num:%d\n", parentPid, num);
    }



    return 0;
}