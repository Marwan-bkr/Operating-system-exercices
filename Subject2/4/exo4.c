#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    int childFork;
    for (int i = 0; i < 4; i++)
    {
        childFork = fork();
        if (childFork > 0 && i == 3){
            int killedChildPID;
            while((killedChildPID = waitpid(-1, NULL, WNOHANG)) != 0) {
                printf("Parent killed zombie Childfork PID %d\n", killedChildPID);
            }
            break;
        } else if(childFork == 0 && i < 3){
            printf("Childfork PID %d becomes a zombie\n", getpid());
            exit(0);
            break;
        } else if (childFork < 0) {
            printf("Error processus creation\n");
        }
    }
    return 0;
}
//
//  exo4.c
//  
//
//  Created by marwan on 17/09/2025.
//

