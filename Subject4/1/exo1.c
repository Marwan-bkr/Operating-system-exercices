#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#define _GNU_SOURCE

void *thread(void *inutilise)
{
    pthread_t tid = pthread_self();
    printf("TID : %lu, and PID : %d\n", (unsigned long)tid, getpid());
    pthread_exit(NULL);
}

int main()
{
    pthread_t th1, th2, th3;
    pthread_create(&th1, NULL, thread, NULL);
    pthread_create(&th2, NULL, thread, NULL);
    pthread_create(&th3, NULL, thread, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);

    exit(0);
}