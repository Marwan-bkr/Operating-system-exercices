#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int N, B[10];
pthread_mutex_t mutex;

void* philosopher(void* i)
{
    while (1){
        printf("Philosophe %d pense\n", (int)(long)i);
        for (int j = 0; j < 1000000; j++); // Penser
        pthread_mutex_lock(&mutex);
        if (B[N+(int)(long)i-1%N]==0 && B[(int)(long)i]==0){
            B[N+(int)(long)i-1%N] = 1;
            B[(int)(long)i] = 1;
            pthread_mutex_unlock(&mutex);
            printf("Philosophe %d mange\n", (int)(long)i);
            for (int j = 0; j < 1000000; j++); // Manger
            pthread_mutex_lock(&mutex);
            B[N+(int)(long)i-1%N] = 0;
            B[(int)(long)i] = 0;
            pthread_mutex_unlock(&mutex);
        } else {
            pthread_mutex_unlock(&mutex);
        }
    }
}

int main()
{
    printf("Saisir le nombre de philosophes (max 10) : ");
    scanf("%d", &N);
    pthread_mutex_init(&mutex, NULL);
    pthread_t pth_id[N];
    for (int i = 0; i < N; i++)
        B[i] = 0;
    for (int i = 0; i < N; i++)
        pthread_create(&pth_id[i], NULL, philosopher, (void*)(long)i);
    for (int i = 0; i < N; i++)
        pthread_join(pth_id[i], NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}