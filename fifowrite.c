#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main(int argc, char const *argv[])
{
    int fd, rt;
    if (argc < 2)
    {
        printf("need a string\n");
        exit(1);
    }
    //创建fifo mkfifo
    rt = mkfifo("file.fifo", 0644);
    if (rt == -1)
    {
        perror("mkfifo");
        if (errno != EEXIST)
            exit(2);
    }
    //打开fifo open
    fd = open("file.fifo", O_RDWR);
    if (fd == -1)
    {
        perror("open");
        exit(2);
    }
    //写fifo write
    write(fd, argv[1], strlen(argv[1]) + 1);
    pause(); //等待
    return 0;
}
