#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

struct sigaction action;

void hand(int sig){
    printf("Parent received SIGCHLD\n");
    while(!waitpid(-1,NULL,WNOHANG));
    printf("childFork died\n");
}

int main(int argc, char *argv[]){

    action.sa_handler=hand;
    sigaction(SIGCHLD,&action,NULL);

    if (!fork()){
        for (int i = 0 ; i <10 ; i++) ; //simule un petit calcul
        printf("childFork finished compute\n");
        exit(1) ;
    }

    while(1); //Simule un calcul infini
    return 0;
}