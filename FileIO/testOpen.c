#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>  三个是man open 的头文件

int main()
{
    /* 返回值文件描述符 */
    /* 打开文件 */
    /* 加O_CREAT */
    int fd1 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd1 == -1)
    {
        perror("open error");
    }
    /* 验证描述符 */
    printf("fd1 = %d\n", fd1);

    int fd2 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd2 == -1)
    {
        perror("open error");
    }
    printf("fd2 = %d\n", fd2);

    int fd3 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd3 == -1)
    {
        perror("open error");
    }
    printf("fd3 = %d\n", fd3);

    int fd4 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd4 == -1)
    {
        perror("open error");
    }
    printf("fd4 = %d\n", fd4);

    /* 关闭文件 */
    close(fd1);

    int fd5 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd5 == -1)
    {
        perror("open error");
    }
    printf("fd5 = %d\n", fd5);
    return 0;
}