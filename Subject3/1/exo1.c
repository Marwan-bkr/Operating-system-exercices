#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    int childFork = fork();
    if (childFork == 0){
        sleep(200);
    } else if (childFork > 0) {
        pid_t pidChild = childFork;
        if (!(kill(pidChild, 0))){
            printf("Child exists\n");
            kill(pidChild, 9);
            printf("Child have been killed\n");
        } else {
            printf("Child doen't exist\n");
        }
    }
}