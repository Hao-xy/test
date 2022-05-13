#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int main(int argc,char const *arg[])
{
int second=0;
while(1)
{
printf("%d\n",second++ );
sleep(1);
}
return 0;
}
