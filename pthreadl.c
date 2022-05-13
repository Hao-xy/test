#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *fun()
{
    printf("in thread %ld\n",pthread_self());
    pthread_exit(NULL);
}
int main()
{
    pthread_t tid;
    int rt;
    rt=pthread_create(&tid,NULL,fun,NULL);
    if(rt!=0)
        {
            printf("create failed\n");
            exit(1);
        }
    printf("int main %ld\n",pthread_self());
    pthread_join(tid,NULL);
    return 0;
}