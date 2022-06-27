#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    char d;
    struct nodo *p_next;
};
typedef struct nodo NODO;


NODO *init()
{
    NODO *testa;
    testa=malloc(sizeof(NODO));
    testa->p_next=NULL;
    return testa;
}

void ins_head(NODO **head, char dato)
{
    NODO *new_nodo;
    new_nodo=malloc(sizeof(NODO));

    new_nodo->d=dato;
    new_nodo->p_next=*head;
    *head=new_nodo;
}

void vis_list(NODO **head)
{
    NODO *punt;
    punt=malloc(sizeof(NODO));
    punt=*head;
    while(punt->p_next != NULL)
    {
        printf("\nLettera: %c",punt->d);
        punt=punt->p_next;
    }
}


int main()
{
    char dato;
    NODO *p_head;
    p_head=malloc(sizeof(NODO));
    p_head=init();
    printf("\nInserisci lettera: ");
    scanf("%c",&dato);
    ins_head(&p_head,dato);
    vis_list(&p_head);
    return 0;
}
