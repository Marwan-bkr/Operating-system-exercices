#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>
#include <sys/wait.h>
void jouer(int NumJoueur){
    //NumJoueur est le numero du joueur 0..MaxJoueurs-1
    printf("Le numéro %d joue\n", NumJoueur);
    sleep(2);
}
#define MaxJoueurs 4
/*0*/
int main( )
{
    // creer MaxJoueurs processus fils du processus principal
    int childFork;
    for (int i = 0; i < MaxJoueurs; i++)
    {
        childFork = fork();
        if (childFork == 0){
            jouer(i+1); // chaque joueur execute la fonction jouer puis se termine
            printf("ChildFork PID %d numéro %d arrête de jouer\n", getpid(), i+1);
            exit(i+1);
            break;
        } else if (childFork < 0) {
            printf("Error processus creation\n");
        }
    }
        
    /*1*/
    int joueurSortant;
    while(1)
    {
        // attendre la fin d’un joueur
        int status;
        pid_t pid = waitpid(-1, &status, WNOHANG);
        if (pid > 0 && WIFEXITED(status)) {
            int sortant = WEXITSTATUS(status);
            //lorsqu’un joueur se termine, un autre joueur de meme numero est cree
            /*3*/
            childFork = fork();
            if (childFork == 0){
                printf("ChildFork PID %d numéro %d rentre en jeu\n", getpid(), sortant);
                jouer(sortant); // chaque joueur execute la fonction jouer puis se termine
                printf("ChildFork PID %d numéro %d arrête de jouer\n", getpid(), sortant);
                exit(sortant);
                break;
            } else if (childFork < 0) {
                printf("Error processus creation\n");
            }
        }
        
    }
    return 0;
}
//
//  exo5.c
//  
//
//  Created by marwan on 17/09/2025.
//

