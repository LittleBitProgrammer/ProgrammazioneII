#include <stdio.h>
#include <stdlib.h>

int main()
{
    short *a[10];

    create_adj_mtx_grafo(&a, 5);

    for(short i=0; i<5; i++)
    {
        printf("\n");
        for(short k=0; k<5-(5-i); k++)
                printf(" ");
        for(short j=0; j<(5-i); j++)
        {


            printf("%hd", *a[i]);
        }
    }
}



void create_adj_mtx_grafo(short **a[], short n_nodi)
{
    for(short i=0; i<n_nodi; i++)
    {
        *(a+i)=calloc((n_nodi-i), sizeof(short));
    }
}
