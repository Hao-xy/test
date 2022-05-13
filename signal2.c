#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void fun(int sig){
switch(sig){
case SIGINT:printf("SIGINT caught!\n");
break;
default:printf( "other\n");
}
}
int main(int argc,char const *argv[])
{
  int second=0;
  signal(SIGINT, fun);
  while(1){
   printf("%d\n" , second++ );
   sleep(1);
  }
  return 0;
}
