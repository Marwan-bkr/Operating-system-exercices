#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int childFork;
    for (int i = 0; i < 3; i++)
    {
        childFork = fork();
        if (childFork > 0 && i == 2){
            sleep(10);
            pid_t w = waitpid(childFork, NULL, 0);
            printf("Parent process PID %d have the return %d of childFork %d\n", getpid(), w, childFork);
            printf("Parent process PID %d died\n", getpid());
            exit(0);
            break;
        } else if(childFork == 0 && i == 0){
            printf("Childfork %d PID %d becomes a zombie\n", i+1, getpid());
            sleep(5);
            exit(0);
            break;
        } else if (childFork == 0 && i == 1){
            sleep(15);
            printf("Childfork %d PID %d becomes a zombie\n", i+1, getpid());
            exit(0);
            break;
        } else if (childFork == 0 && i == 2){
            sleep(1);
            printf("Childfork %d PID %d becomes a zombie\n", i+1, getpid());
            exit(0);
            break;
        } else if (childFork < 0) {
            printf("Error processus creation\n");
        }
    }
    return 0;
}
//
//  exo3.c
//  
//
//  Created by marwan on 17/09/2025.
//

