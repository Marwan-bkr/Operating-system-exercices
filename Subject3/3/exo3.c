#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

struct sigaction action;

void hand_sigpipe(int sig){
    printf("Signal SIGPIPE recu\n");
}

int main(){

    int nb_ecrit, p[2];

    action.sa_handler=hand_sigpipe;

    sigaction(SIGPIPE,&action,NULL);
    
    pipe(p);

    close(p[0]);

    if((nb_ecrit=write(p[1],"A",1))== -1)
        perror("Write");
    else
    printf("Retour du write : %d\n",nb_ecrit);
    return 0;
}