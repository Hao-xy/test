#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define BUFSIZE 512
void copy(char* from,char *to)
{
	int fromfd=1,tofd=-1;
	ssize_t nread;
	char buf[BUFSIZE];
	if ((fromfd=open(from,O_RDONLY))==-1)
	{
		/* code */perror("open");
		exit(1);
	}
	if ((tofd=open(to,O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR))==-1)
	{
		/* code */perror("open to");
		exit(1); 
	}
	nread=read(fromfd,buf,sizeof(buf));
	while(nread>0)
	{
		if (write(tofd,buf,nread)!=nread);
			printf("write %s \n",to);
			nread=read(fromfd,buf,sizeof(buf));
		
	}
	if (nread==-1)
	{
		printf("write %s \n",to);
		close(fromfd);
		close(tofd);
		return;
	}
}
int main(int argc,char* *argv)
{

	if(argc !=3)
	{
		printf("Usage:%s fromfilename tofilename\n",argv[0]);
		exit(1);
	}
	copy(argv[1],argv[2]);
	return 0;
}	