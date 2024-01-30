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
#include <dirent.h>

#define BUFFER_SIZE 128
/* opendir closedir readdir */
int main()
{   
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));
    getcwd(buf, sizeof(buf) - 1);
    
    /* 打开一个目录 */
    DIR * pDir = opendir(buf);
    if (pDir == NULL)
    {
        perror("opendir error");
        return 0;
    }
    
    struct stat statbuf;
    stat("./testDir.c", &statbuf);
    printf("statbuf.mode:%D\n\n", statbuf.st_mode);

    /* 读取目录 */
     struct dirent * pdirent = NULL;
    while ((pdirent = readdir(pDir)) != NULL)
    {   
        if (pdirent->d_type == DT_REG)  
        {
            printf("name:%s\td_type:%d\n", pdirent->d_name, pdirent->d_type);
        }
       
    }
    /* 关闭文件夹 */
    closedir(pDir);


    return 0;
}