#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc < 2){
        printf("No argmuent\n");
    } else {
        int childFork;
        int execError = 0;
        for (int i = 1; i < argc; i++)
        {
            childFork = fork();
            if (childFork == 0){
                printf("Execution of %s : \n", argv[i]);
                execlp(argv[i], argv[i], (char *)NULL);
                perror("Execution error\n");
                exit(-1);
                break;
            } else if (childFork > 0) {
                int status;
                if (waitpid(childFork, &status, 0) == -1) {
                    execError++;
                } else {
                    if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                        execError++;
                    } else if (WIFSIGNALED(status)) {
                        execError++;
                    }
                }
            } else {
                execError++;
            }
            printf("%d exec file error(s)\n", execError);
        }
    }
    return 0;
}
//
//  exo6.c
//  
//
//  Created by marwan on 17/09/2025.
//

