#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct info{
        char nome[15];
        };
typedef struct info INFO_FIELD;
struct nodo{
        INFO_FIELD stringa;
        struct nodo *p_next;
        };
typedef struct nodo NODO;
NODO *crea_lista();
void visita(NODO *sentinella);
void push(INFO_FIELD inserimento, NODO **sentinella);
void pop(NODO **sentinella);
int main()
{
    short scelta;
    INFO_FIELD inserimento;
    NODO *sentinella;
    sentinella=(NODO *) malloc(sizeof(NODO));
    sentinella=crea_lista();
    do{
            printf("\t<--GESTIONE PILA CON NODO SENTINELLA-->\n");
            printf("Inserisci:\n[0] PUSH\n[1] POP\n[2] VISITA\n[5] EXIT\n>>");
            fflush(stdin);
            scanf("%hd",&scelta);
    switch(scelta){
    case 0: printf("\t<--PUSH-->\n");
            printf("Inserisci NOME\n>>");
            fflush(stdin);
            gets(inserimento.nome);
            push(inserimento,&sentinella);
            system("PAUSE");system("cls");break;
    case 1: printf("\t<--POP-->\n");
            pop(&sentinella);
            system("PAUSE");system("cls");break;
    case 2: printf("\n\t<--VISITA DELLA PILA -->\n");
            visita(sentinella);
            system("PAUSE");system("cls");break;
    case 5: scelta=5;break;
    default:printf("\n\t<--INPUT ERROR-->\n");
            system("PAUSE");system("cls");break;
            }
    }while(scelta!=5);
return 0;
}

void push(INFO_FIELD inserimento, NODO **sentinella)
{
    NODO *ptr;
    ptr=(NODO *)calloc(1,sizeof(NODO));
    if(ptr!=NULL)
    {
        strcpy(ptr->stringa.nome,inserimento.nome);
        ptr->p_next=(*sentinella);
        (*sentinella)=ptr;
    }
    printf("\n<---PUSH RIUSCITO--->\n");
}

void visita(NODO *sentinella)
{
    short i=0;
    if(sentinella==NULL)
        printf("\t\n<--PILA VUOTA-->\n");
    while(sentinella!=NULL)
    {
        fflush(stdout);
        printf("ELEMENTO->>%hd - NOME->>%s\n", i, sentinella->stringa.nome);
        sentinella=sentinella->p_next;
        i++;
    }
}

void pop(NODO **sentinella)
{
    NODO *ptr;
    ptr=(*sentinella)->p_next;
    free(*sentinella);
    (*sentinella)=ptr;
    printf("\n<--POP RIUSCITO-->\n");
}

NODO *crea_lista()
{
    NODO *testa;
    testa=NULL;
    return testa;
}
