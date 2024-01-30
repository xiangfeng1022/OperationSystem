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
        /* 休眠1s 让出CPU 目的是：让父进程先执行完 num */
        sleep(1);

        /* 子进程 */
        pid_t childPid = getpid();
        printf("child process: childPid: %d, num:%d\n", childPid, num);
        
        /* 父进程 */
        pid_t parentPid = getppid();
        printf("child process: parentPid: %d\n", parentPid);
        
        int childA = 666;
        //  while (1)
        //  {
        //     sleep(3);
        //  }
    }
    else if (pid > 0)
    {
        /* 父进程 */
        pid_t parentPid = getpid();
        printf("parent process: parentPid: %d, num:%d\n", parentPid, num);
        num += 100;
         printf("parent process: parentPid: %d, num:%d\n", parentPid, num);
        
        /* 拿不到 因为父子进程都是独立的地址空间 */
        // printf("parent process : childA: %d\n", childA);
        //  while (1)
        //  {
        //     sleep(3);
        //  }
    }
    
    

    /* 父子进程都会到达这个地方 */
    printf("hello world\n");
    
    
    return 0;
}