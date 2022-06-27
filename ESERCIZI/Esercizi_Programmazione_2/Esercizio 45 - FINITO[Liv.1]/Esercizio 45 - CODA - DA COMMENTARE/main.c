#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct info{
        char stringa[10];
        };
typedef struct info INFO_FIELD;
struct nodo{
        INFO_FIELD dato;
        struct nodo *p_next;
        };
typedef struct nodo NODO;
void crea_lista(NODO **testa, NODO **coda);
void visita(NODO *testa);
void enqueue(NODO **testa, NODO **coda, INFO_FIELD inserimento);
void dequeue(NODO **testa);
int main()
{
    INFO_FIELD inserimento;
    NODO *testa, *coda;
    short scelta=0;
    coda=(NODO *) calloc(1,sizeof(NODO));
    testa=(NODO *) calloc(1,sizeof(NODO));
    crea_lista(&testa,&coda);
    do{
        printf("\t<----GESTIONE CODA TRAMITE LISTA---->\n");
        printf("INSERIRE:\n[1] VISITA CODA\n[2] ENQUEUE\n[3] DEQUEUE\n[4] EXIT\n>>");
        fflush(stdin);
        scanf("%hd",&scelta);
        switch(scelta){
                case 1: printf("\n\t<---VISITA CODA--->\n");
                        visita(testa);
                        system("PAUSE");system("cls");break;
                case 2: printf("\n\t<---ENQUEUE--->\n");
                        printf("Inserire NOME NODO\n>>");
                        fflush(stdin);
                        gets(inserimento.stringa);
                        enqueue(&testa,&coda,inserimento);
                        system("PAUSE");system("cls");break;
                case 3: printf("\n\t<---DEQUEUE--->\n");
                        dequeue(&testa);
                        system("PAUSE");system("cls");break;
                case 4: scelta=4;
                        printf("\n\t<---EXIT--->\n");break;
                default:printf("\n\t<----INPUT ERROR---->\n");break;
                        }


    }while(scelta!=4);

return 0;
}

void crea_lista(NODO **testa, NODO **coda)
{
    (*testa)->p_next=NULL;
    (*testa)=NULL;
    (*coda)=(*testa);
}

void visita(NODO *testa)
{
    short i=0;
    NODO *tmp;
    tmp=(NODO *)calloc(1,sizeof(NODO));
    tmp=testa;
    if((testa)==NULL)
        printf("\n<----CODA VUOTA---->\n");
    else
    {
        while(tmp!=NULL)
        {
            printf("NODO>> %hd - NOME>> %s\n",i, tmp->dato.stringa);
            tmp=tmp->p_next;
            i++;
        }
    }
}

void enqueue(NODO **testa, NODO **coda, INFO_FIELD inserimento)
{
    NODO *ptr;
    ptr=(NODO *) calloc(1,sizeof(NODO));
    if((*testa)==NULL)
    {
        strcpy(ptr->dato.stringa,inserimento.stringa);
        ptr->p_next=NULL;
        (*testa)=ptr;
        (*coda)=(*testa);
    }
    else
    {
        strcpy(ptr->dato.stringa,inserimento.stringa);
        ptr->p_next=NULL;
        (*coda)->p_next=ptr;
        (*coda)=ptr;
    }
}

void dequeue(NODO **testa)
{
    NODO *ptr;
    if((*testa)==NULL)
        printf("\n<----CODA VUOTA---->\n");
    else
    {
        ptr=(NODO *) calloc(1,sizeof(NODO));
        ptr=(*testa)->p_next;
        free(*testa);
        (*testa)=ptr;
    }
}
