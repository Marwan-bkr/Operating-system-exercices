#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define NMAX 4

struct sigaction action;
int i;

void hand(int sig){
    i++;
}

int main(){
    action.sa_handler=hand;
    sigaction(SIGQUIT, &action, NULL);
    sigaction(SIGINT, &action, NULL);
    
    while(1){
        if (i == NMAX ){
            return 0;
        }
    }
}