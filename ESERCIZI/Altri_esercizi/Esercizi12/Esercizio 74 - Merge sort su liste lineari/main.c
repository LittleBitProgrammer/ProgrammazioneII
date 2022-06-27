/*Scrivere una function C per implementare l’algoritmo Merge Sort su una lista lineare.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    short dato;
    struct nodo *pnext;
}NODO;

int main()
{
    NODO *head_lista1, *head_lista2;

    crea_lista1(&head_lista1, 1);

    NODO *nodo_corr=malloc(sizeof(NODO));
    nodo_corr=head_lista1;

    do
    {
        printf("dato= %hd\n", nodo_corr->dato);
        nodo_corr=nodo_corr->pnext;
    }while(nodo_corr!=NULL);

    crea_lista2(&head_lista2, 2);

    nodo_corr=head_lista2;

    do
    {
        printf("dato= %hd\n", nodo_corr->dato);
        nodo_corr=nodo_corr->pnext;
    }while(nodo_corr!=NULL);

    system("PAUSE");
    system("cls");

    lists_merge_sort(&head_lista1, &head_lista2, 3, 3);


}

void crea_lista1(NODO **nodo, short i)
{
    if(i<=6)
    {
        *nodo=malloc(sizeof(NODO));
        (*nodo)->dato=i;

        crea_lista1(&(*nodo)->pnext, i+2);
    }
    else *nodo=NULL;

}

void crea_lista2(NODO **nodo, short i)
{
    if(i<=6)
    {
        *nodo=malloc(sizeof(NODO));
        (*nodo)->dato=i;

        crea_lista2(&(*nodo)->pnext, i+2);
    }
    else *nodo=NULL;

}

void lists_merge_sort(NODO **head1, NODO **head2, short size1, short size2)
{
    NODO *nodoL1=malloc(sizeof(NODO)), *nodoL2=malloc(sizeof(NODO));
    NODO *nodo_buffer=malloc(sizeof(NODO));
    nodoL1=*head1; nodoL2=*head2;

    while(nodoL1!=NULL && nodoL2!=NULL)
    {
        if(nodoL1->dato<nodoL2->dato)
        {
            nodo_buffer=nodoL1->pnext;
            nodoL1->pnext=nodoL2;
            nodoL1=nodo_buffer;
        }
        else
        {
            nodo_buffer=nodoL2->pnext;
            nodoL2->pnext=nodoL1;
            nodoL2=nodo_buffer;
        }
    }

    printf("fatto\n");


    while(nodoL1!=NULL)
    {
        nodoL2->pnext=nodoL1->pnext;
        nodoL1=nodoL2;
    }
    nodoL2=nodoL2->pnext;

    while(nodoL2!=NULL)
    {
        nodoL1->pnext=nodoL2->pnext;
        nodoL2=nodoL1;
    }
}
