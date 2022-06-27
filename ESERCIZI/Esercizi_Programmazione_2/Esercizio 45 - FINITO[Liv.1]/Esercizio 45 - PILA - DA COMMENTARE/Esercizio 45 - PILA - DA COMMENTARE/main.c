#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct INFO{
                char nome[10];
                };
typedef struct INFO INFO_FIELD;
struct nodo{
                INFO_FIELD info;
                struct nodo *p_next;
                };
typedef struct nodo NODO;
NODO *crea_pila();
void visita_pila(NODO *);
void push(NODO **, INFO_FIELD);
void pop(NODO ** );
int main()
{
    short scelta;
    INFO_FIELD inserimento;
    NODO *head;
    head=crea_pila();
    do{
    printf("<---GESTIONE PILA--->\n");
    printf("\t<--MENU'-->\n");
    printf("Inserire:\n[0] VISITA PILA\n[1] PUSH\n[2] POP\n[5] EXIT\n>>");
    fflush(stdin);
    scanf("%hd", &scelta);
    switch(scelta){
        case 0: printf("\n<--VISITA PILA-->\n");
                visita_pila(head);
                system("PAUSE"); system("cls"); break;
        case 1: printf("\n<--PUSH-->\n");
                printf("Inserisci NOME NODO:\n>>");
                fflush(stdin);
                gets(inserimento.nome);
                push(&head,inserimento);
                system("PAUSE"); system("cls"); break;
        case 2: printf("\n<--POP-->\n");
                pop(&head);
                system("PAUSE"); system("cls"); break;
        case 5: printf("\n<--EXIT-->\n"); break;
        default:printf("\n<--ERROR INPUT-->\n");
                system("PAUSE"); system("cls"); break;
                }
    }while(scelta!=5);
return 0;
}

NODO *crea_pila()
{
    NODO *testa;
    testa=NULL;
    return testa;
}

void visita_pila(NODO *head)
{
    short i=0;
    if(head==NULL)
        printf("\n\t<--PILA VUOTA-->\n");
    while(head!=NULL)
    {
        printf("\tNODO->>%hd - NOME->>%s\n", i, head->info.nome);
        head=head->p_next;
        i++;
    }
}

void push(NODO **head, INFO_FIELD inserimento)
{
    NODO *ptr;
    ptr=(NODO *) calloc(1,sizeof(NODO));
    if(ptr!=NULL)
    {
        strcpy(ptr->info.nome,inserimento.nome);
        ptr->p_next=*head;
        *head=ptr;
    }
    printf("\n\t<--PUSH RIUSCITO-->\n");
}

void pop(NODO **head)
{
    NODO *ptr;
    ptr=(NODO *) calloc(1,sizeof(NODO));
    if((*head)->p_next==NULL)
    {
        free(*head);
        (*head)=NULL;
    }
    else
    {
        ptr=(*head)->p_next;
        free(*head);
        (*head)=ptr;
    }
    printf("\n\t<--POP RIUSCITO-->\n");
}
