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


#define BUFFER_SIZE 128

int main()
{   
    /* getcwd 获取当前进程的工作目录 */
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    char * ptr = getcwd(buf, sizeof(buf) - 1);
    printf("buf:%s\n", buf);
    printf("ptr:%s\n", ptr);

    
}