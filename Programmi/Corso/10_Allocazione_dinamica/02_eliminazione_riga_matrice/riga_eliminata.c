/**
 * @file riga_eliminata.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Eliminazione di una riga all' indice irow di una matrice RxC
 * @version 1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define R 6
#define C 8

int main(int argc, char const *argv[])
{
    int *matrix;
    short i, j, irow;
    int A[R][C];
    
    puts("inserire la riga da eliminare tra 1 e 8:  \n");
    scanf("%d", &irow); 
    irow--; 
    
    matrix = malloc(R*C*sizeof(int));

    srand(time(NULL));

    for ( i = 0; i < R; i++)
    {
        for ( j = 0; j < C; j++)
        {
            *(matrix + i*C +j) = rand()*100/RAND_MAX;
            printf("%d\t", *(matrix + i*C + j));
        }
        printf("\n");
    }

    /* Spostamento della matrice di un posto verso l' alto rispetto alla posizione irow */
    memmove(matrix + irow * C, matrix + (irow + 1) * C, (R - irow) * C * sizeof(int));
    
    matrix = realloc(matrix, (R - 1) * C * sizeof(int));

    puts("\nMatricce matrix traslata\n");
    for ( i = 0; i < R-1; i++)
    {
        for ( j = 0; j < C; j++)
        {
            printf("%d\t", *(matrix + i*C + j));
        }
        puts("\n");
    }

    return 0;
}