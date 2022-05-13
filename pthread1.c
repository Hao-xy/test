#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
typedef struct threadarg
{
    int length;
    char *arr;
}  DATA;
void  *func(void *query)
{
    int i;  
    DATA* data=(DATA*)query;
    for(i=0;i<data->length;++i)
    {
        printf("in thread %ld %s\n",pthread_self(),data->arr);
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t pid;
    int rt;
    char *n="hello";
    DATA data[2];
    data[1].length=4;
    data[1].arr=n;
    rt=pthread_create(&pid,NULL,func,(void *)&data[1]);
    if(rt!=0)
    {
        printf("create failed\n");
        exit(1);
    }
    printf("in main %ld\n",pthread_self());
    pthread_join(pid,NULL);
}