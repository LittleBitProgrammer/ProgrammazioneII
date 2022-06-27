#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char DATA;
struct nodo{
            DATA d;
            struct nodo *sx;
            struct nodo *dx;
            };
typedef struct nodo NODO;
typedef NODO *ALBERO;

ALBERO iniz_nodo(char d1, ALBERO p1, ALBERO p2);
ALBERO crea_albero(char a[], int i, int size);
void inorder(ALBERO pisello);
void preorder(ALBERO pisello);
void postorder(ALBERO pisello);

int main()
{
    ALBERO pisello;
    char array[]="GDIBFHJACE";
    short i=0;
    printf("\t<---VISITA ALBERO BINARIO CON LISTE MULTIPLE--->\n");
    printf("\nARRAY DI PARTENTA--->\n");
    for(i=0;i<strlen(array);i++)
        printf("ELEMENTO %hd ->> %c\n", i, array[i]);
    i=0;
    pisello=crea_albero(array,i,strlen(array));
    printf("\n\t<---VISITA ALBERI BINARI CREATI--->\n\n");
    printf("\n\t\t  <---INORDER--->\n\t\t");
    inorder(pisello);
    printf("\n\t\t <---PREORDER--->\n\t\t");
    preorder(pisello);
    printf("\n\t\t  <---POSTORDER--->\n\t\t");
    postorder(pisello);
return 0;
}

ALBERO iniz_nodo(char d1, ALBERO p1, ALBERO p2)
{
    ALBERO ptr;
    ptr=malloc(sizeof(NODO));
    ptr->d=d1;
    ptr->sx=p1;
    ptr->dx=p2;
return ptr;
}

ALBERO crea_albero(char a[],int i, int size)
{
    if(i>=size)
        return NULL;
    else
    {
        return (iniz_nodo(a[i],crea_albero(a,2*i+1,size), crea_albero(a,2*i+2,size)));
    }
}

void inorder(ALBERO pisello)
{
    if(pisello!=NULL)
    {
        inorder(pisello->sx);
        printf("%c ", pisello->d);
        inorder(pisello->dx);
    }
}

void preorder(ALBERO pisello)
{
    if(pisello!=NULL)
    {
        printf("%c ", pisello->d);
        preorder(pisello->sx);
        preorder(pisello->dx);
    }
}

void postorder(ALBERO pisello)
{
    if(pisello!=NULL)
    {
        postorder(pisello->sx);
        postorder(pisello->dx);
        printf("%c ",pisello->d);
    }
}
