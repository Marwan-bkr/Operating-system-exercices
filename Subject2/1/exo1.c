#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main( int argc, char *argv[])
{
    if (argc == 2){
        int n = atoi(argv[1]);
        int childFork;
        for (int i = 0; i < n; i++)
        {
            childFork = fork();
            if (childFork == 0) {
                printf("Childfork %d PID : %d\n", i+1, getpid());
                break;
            } else if (childFork > 0) {
                printf("Parent process PID : %d\n", getpid());
            } else if (childFork < 0) {
                printf("Error processus creation\n");
            }
        }
    } else {
        printf("Not the right number of argument\n");
    }
    return 0;
}
