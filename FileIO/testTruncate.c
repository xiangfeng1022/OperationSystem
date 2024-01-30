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


int main()
{
    /* 文件变为10个字节 */
    int ret = truncate("./xixixix.c", 10);
    if (ret == -1)
    {
        perror("truncate error");
        return 0;
    }

    return 0;
}