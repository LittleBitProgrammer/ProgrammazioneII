/**
 * @file riga_aggiunta.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Aggiunta di una riga vuota in una matrice RxC
 * @version 1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define R 8
#define C 5

int main(int argc, char const *argv[])
{
    int A[R][C], *matrix, *row;
    short i, j, irow;

    row = (int *) calloc(C, sizeof(int));

    puts("Numero riga da inserire tra 1 e 8 :\n");
    scanf("%d", &irow);
    irow--;
    srand(time(NULL));

    /* Creazione matrice A*/
    for ( i = 0; i < R; i++)
    {
        for ( j = 0; j < C; j++)
        {
            A[i][j] = rand()*100/RAND_MAX;
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    
    matrix = malloc(R*C*sizeof(int));
    
    /* Copia della matrice A in matrix*/
    for ( i = 0; i < R; i++)
    {
        for ( j = 0; j < C; j++)
        {
            *(matrix + i*C + j) = A[i][j];
        }
    }

    matrix = realloc(matrix, (R+1)*C*(sizeof(int)));

    /* Sposta la sottomatrice inferiore di 1 riga rispetto alla riga irow*/
    memmove(matrix + (irow + 1) * C, matrix + irow * C, (R - irow) * C * sizeof(int));
    
    /* Copia la riga row nella riga di indice irow */
    memcpy(matrix + irow * C, row, C * sizeof(int));

    puts("\nMatricce matrix traslata\n");
    for ( i = 0; i <= R; i++)
    {
        for ( j = 0; j < C; j++)
        {
            printf("%d\t", *(matrix + i*C + j));
        }
        puts("\n");
    }
    
    return 0;
}
