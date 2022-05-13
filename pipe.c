#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<error.h>
#include<linux/limits.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
     pid_t pid;
     const char data[32]= "read:I come from NEU! ";
     char buf[32] = {0};
     int fds[2];
     printf("PIPE_BUF:%d( bytes )\n",PIPE_BUF);
	if(pipe(fds ) == 0){
        pid = fork();
        if(pid == 0){
            close(fds[0]);int count = 5;
            while(count--){
              write(fds[1],data,strlen(data));sleep(1);
        }
         close( fds[1]);
         exit(0);
}else if(pid > 0){
close(fds[1]);
int count = 5;
while(count -- ){
ssize_t num = read( fds[0],buf ,sizeof(buf)-1);
if(num > 0)
{
buf[num]='\0';
printf( "%s\n" ,buf );
}else{
perror( " read error " );
exit(1);
}
}
close( fds[0]);
wait(NULL);
}
}
return 0;
}
