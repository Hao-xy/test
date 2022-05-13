#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    
    pid_t pid;
    for(int i=0;i<2;++i)
    {
        pid=fork();
        if(pid<0)
        {
            perror("fork");
            exit(1);
            
        }
        else if(pid==0)
        {
             printf(" hello child %d \n",getpid());
        }
        else
        {
            printf("  word parent %d \n",getpid());  
        }
    }
   
}