#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
        short dato;
        struct nodo *dx;
        struct nodo *sx;
        };
typedef struct nodo NODO;
void inorder(NODO *albero);
NODO *crea_nodo(short d1, NODO *p1, NODO *p2);
NODO *ricerca(NODO *albero, short array[]);
int main()
{
    NODO *albero;
    short array[]={5,7,8,1,6,0,3,4,9,2}, i=0;
    albero=malloc(sizeof(NODO));
    printf("\t\t<---ALBERO DI RICERCA BINARIO CON LISTE MULTIPLE--->\n");
    printf("<---ARRAY INPUT--->\n");
    for(i=0;i<10;i++)
        printf("ELEMENTO %hd ->> %hd\n", i, array[i]);
    albero=ricerca(albero,array);
    printf("\n\t\t<--VISITA INORDER DELL'ALBERO BINARIO DI RICERCA--->\n\t\t\t   ");
    inorder(albero);
    printf("\n\n");
return 0;
}

NODO *crea_nodo(short d1, NODO *p1, NODO *p2)
{
    NODO *ptr;
    ptr=malloc(sizeof(NODO));
    ptr->dato=d1;
    ptr->sx=p1;
    ptr->dx=p2;
return ptr;
}

NODO *ricerca(NODO *albero, short array[])
{
    short i=0, nuovo_nodo;
    albero=crea_nodo(array[0],NULL,NULL);
    NODO *tmp=albero;
    while(1)
    {
        i++;
        nuovo_nodo=array[i];
        while(nuovo_nodo <= tmp->dato && tmp->sx != NULL)
            tmp=tmp->sx;
        while(nuovo_nodo >= tmp->dato && tmp->dx != NULL)
            tmp=tmp->dx;
        if(nuovo_nodo<=tmp->dato)
            tmp->sx=crea_nodo(nuovo_nodo,NULL,NULL);
        else
            tmp->dx=crea_nodo(nuovo_nodo,NULL,NULL);
        if(i==9)
            break;
    }
return albero;
}

void inorder(NODO *albero)
{
    if(albero==NULL)
        return;
    inorder(albero->sx);
    printf("%hd ", albero->dato);
    inorder(albero->dx);
}
