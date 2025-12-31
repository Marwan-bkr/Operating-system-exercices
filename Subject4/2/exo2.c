#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#define _GNU_SOURCE

void* tache(void *i)
{
    int arg = (int)(long)i;
    int j;
    pthread_t tid = pthread_self();
    for (j=0;j<1000;j++);
    printf("Fin de la boucle de 1000 de la fonction tache du thread %ld %lu.\n", (long)arg, (unsigned long)tid);    
    pthread_exit(NULL);
}

int main()
{
    int i;
    pthread_t th[5]; 
    for (i=0;i<5;i++)
    {
        pthread_create(&th[i], NULL, tache, (void*)(long)(i+1));
    }
    tache((void*)(long)(0));
    for (i=0;i<5;i++)
    {
        pthread_join(th[i], NULL);
    }
    exit(0);
}