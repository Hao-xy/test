#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#define MAXLINE 4096
int parse(char * , char * * );
int main(void)
{
	pid_t pid;
	char *rt;
	char buf[MAXLINE];
	int status;
	char *args[64];
	int argnum=0;
	while(1)
	{
		printf("%% ");
		rt=fgets(buf,MAXLINE,stdin);
		if(rt==NULL)
		{
			printf("fgets error\n");
			exit(1);
		}
		if(!strcmp(buf,"\n"))
		{
			printf("%%");
			continue;
		}
		if(buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]=0;
		argnum=parse(buf,args);
		if((strcmp(args[0],"logout")==0)||(strcmp(args[0],"exit")==0))
			exit(0);
		else
		{
			if((pid =fork())<0)
			{
				printf("fork error,please reput command\n" );
				continue; 
			}
			else if(pid==0)
			{
				execvp(*args,args);
				printf("couldn't execute:%s\n",buf);
				exit(127);
			}
			if((pid=waitpid(pid,&status,0))<0)
				printf("waitpid error\n");
		}
	}
	exit(0);
}

int parse(char *buf,char * * args)
{
	int num=0;
	while(*buf!='\0')
	{
		while((* buf==' ')||(*buf=='\t'||(*buf=='\n')))
		*buf++='\0';
		*args++=buf;
		++num;
	while((*buf!='\0')&&(*buf!=' ')&&(*buf!='\t')&&(*buf!='\n'))
		buf++;
	}
	*args='\0';
return num;
}
