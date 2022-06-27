/*Scrivere una function C per implementare l’algoritmo Selection Sort su una lista bidirezionale. */

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    short dato;
    struct nodo *p_next, *p_prev;
}NODO;


short search_min_ind(NODO *head_lista);
void min_sel_sort(NODO **nodo);

int main()
{
    NODO *head_lista, *nodo;
    nodo=malloc(sizeof(NODO));

    crea_lista_bidi(NULL, &head_lista);
    nodo=head_lista;

    do
    {
        printf("%hd ", nodo->dato);
        nodo=nodo->p_next;
    }while(nodo!=NULL);

    min_sel_sort(&head_lista);

    do
    {
        printf("%hd ", nodo->dato);
        nodo=nodo->p_next;
    }while(nodo!=NULL);

    return 0;
}

void crea_lista_bidi(NODO *nodo_prec, NODO **nodo_corr)
{
    *nodo_corr=malloc(sizeof(NODO));
    (*nodo_corr)->p_prev=nodo_prec;

    printf(">> INSERISCI DATO NODO CORRENTE <<\n[Se uguale a 0, sara' nodo finale] -> ");
    scanf("%hd", &(*nodo_corr)->dato); printf("\n");

    if((*nodo_corr)->dato==0)
    {
        (*nodo_corr)->p_next=NULL;
        return;
    }

    crea_lista_bidi(nodo_corr, &(*nodo_corr)->p_next);
}

short search_min_ind(NODO *head_lista)
{
    short ind_min=1, i=1, dato_min=head_lista->dato;
    head_lista=head_lista->p_next;

    do
    {
        if(dato_min>head_lista->dato)
        {
            dato_min=head_lista->dato;
            ind_min=i;
        }

        i++;

        head_lista=head_lista->p_next;
    }while(head_lista!=NULL);

    return ind_min;
}

void min_sel_sort(NODO **nodo)
{

    if((*nodo)->p_next!=NULL)
    {
        NODO *nodo_min=malloc(sizeof(NODO));
        printf("min= %hd\n", search_min_ind(*nodo));
        for(short i=0; i<search_min_ind(*nodo); i++)
        {
            nodo_min=nodo_min->p_next;
        }

        short temp;

        temp=(*nodo)->dato;
        (*nodo)->dato=nodo_min->dato;
        nodo_min->dato=temp;

        min_sel_sort(&(*nodo)->p_next);
    }
    else
        return;

}
