#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int fd;
    char info[128]={0};
    fd=open("file.fifo",O_RDWR);
    if (fd==1)
    {
        /* code */perror("open");
        exit(1);
    }
    read(fd,info,sizeof(info));
    printf("%s",info);
    return 0;
}