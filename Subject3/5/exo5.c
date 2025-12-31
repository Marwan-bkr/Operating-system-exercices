#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include <signal.h>

#define N 5

pid_t pid[N];

void hand(int sig){
    printf("ChildFork captured SIGCONT\n");
}

void handParent(int sig){
    for (int i = 0; i< N; i++){
        kill(pid[i], SIGKILL);
    }
    raise(SIGKILL);
}

int main( ) {
    int i ;
    for ( i=0; i<N;i++){
        if ((pid[i]=fork())==0) { 
            struct sigaction action;
            action.sa_handler=hand;
            sigaction(SIGCONT,&action,NULL);
            raise(SIGSTOP);
            while(1){
                printf("ici fils %d \n", i);
                sleep(1);
            }
            if((kill(getppid(),0))<0){
                raise(SIGKILL);
            }
        } 
    }
    if (pid[4] > 0) {
            
            struct sigaction action;
            action.sa_handler=handParent;
            sigaction(SIGINT,&action,NULL);

            int j = 0;
            while(1){
                pid_t pidChildCurrent = pid[j];
                if (j==4){
                    j = -1;
                }
                pid_t pidChildNext = pid[j+1];
                j++;
                kill(pidChildCurrent, SIGCONT);
                sleep(1);
                kill(pidChildCurrent, SIGSTOP);
                kill(pidChildNext, SIGCONT);
            }
        }
    return 0;
}
