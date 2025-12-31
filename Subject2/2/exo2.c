#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int childFork;
    for (int i = 0; i < 2; i++)
    {
        childFork = fork();
        if (childFork == 0 && i == 0){
            for (int j = 1; j < 51 ; j++){
                printf("Childfork %d PID %d count : %d\n", i+1, getpid(), j);
            }
            break;
        } else if (childFork == 0 && i == 1){
            for (int j = 51; j < 101 ; j++){
                printf("Childfork %d PID %d count : %d\n", i+1, getpid(), j);
            }
            break;
        } else if (childFork < 0) {
            printf("Error processus creation\n");
        } else {
            printf("Parent process PID : %d\n", getpid());
        }
    }
    return 0;
}
//
//  exo2.c
//  
//
//  Created by marwan on 17/09/2025.
//

