#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t pth_id[9];
int A[3][3], B[3][3];
int i,j;
int C[3][3];

/* Fonction pour la multiplication de deux matrices carrées (3x3) */
void* multipl_thr(void* i)
{
    int j;
    printf("Thread numero = %d\n", (int)(long)i);
    for (j = 0; j < 3 ; j++)
    {
        C[(int)(long)i / 3][(int)(long)i % 3] =
            C[(int)(long)i / 3][(int)(long)i % 3] +
            A[(int)(long)i / 3][j] * B[j][(int)(long)i % 3];
    }
    pthread_exit(0);
}

int main()
{
    // le format des matrices doit être deux listes de la forme {{0, 1}, {2, 3}} de maximm 5x5
    printf("Saisir deux matrices 3x3 un chiffre par saisie \n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++){
            printf("A[%d][%d] : ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++){
            printf("B[%d][%d] : ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    void* statut = NULL;

    for (int i = 1; i < 3; i++) 
    {
        //argv[i]

        for (i = 0; i < 9; i++)
        {
            if (pthread_create(&pth_id[i], 0, multipl_thr, (void*)(long)i) == -1)
            {
                fprintf(stderr, "Erreur de creation du thread\n");
            }
        }

        printf("Join des threads crees\n");
        for (i = 0; i < 9 && pthread_join(pth_id[i], NULL) == 0; i++);
        printf("Fin des threads\n");

        printf("Affichage de la matrice produit\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }
    }
    return 0;
}
