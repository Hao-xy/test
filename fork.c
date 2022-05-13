#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    pid_t pid;
    pid=fork();
    if(pid<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid==0)
    {
        printf("I am a child ,my pid is =%d\n",getpid());
    }
    else
    {
        printf("I am a parent ,my pid is =%d\n",getpid());
    }
    printf("%d print this sentence\n",getpid());

}