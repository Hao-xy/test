#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int main(int argc,char const *argv[])
{
  int second=0;
  signal(SIGINT,SIG_IGN);
  while(1){
      printf("%d\n", second++ );
      sleep(1);
    }
    return 0; 
 }
