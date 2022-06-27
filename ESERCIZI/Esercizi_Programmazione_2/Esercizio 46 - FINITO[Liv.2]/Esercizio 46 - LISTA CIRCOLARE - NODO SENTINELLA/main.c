#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct info{
        short cnt;
        char stringa[25];
        };
typedef struct info INFO_FIELD;
struct nodo{
        INFO_FIELD dato;
        struct nodo *p_next;
        };
typedef struct nodo NODO;
void crea_lista(NODO **head, INFO_FIELD **list);
void inserimento(NODO **head, INFO_FIELD **list, INFO_FIELD inserire);
void eliminazione(NODO **head, INFO_FIELD **list);
void visita(NODO **head, INFO_FIELD **list);
int main()
{
    short scelta=0;
    NODO *head;
    INFO_FIELD *list, inserire;
    head=malloc(sizeof(NODO));
    list=malloc(sizeof(INFO_FIELD));
    crea_lista(&head,&list);
    do{
        printf("\n\t<---GESTIONE LISTA CIROCLARE CON NODO SENTINELLA--->\n");
        printf("INSERIRE:\n[1] VISITA\n[2] INSERIMENTO\n[3] ELIMINAZIONE\n[4] EXIT\n>>");
        fflush(stdin);
        scanf("%hd", &scelta);
        switch(scelta){
                case 1: printf("\n\t<---VISITA LISTA---->\n");
                        visita(&head,&list);
                        system("PAUSE");system("cls");break;
                case 2: printf("\n\t<---INSERIMENTO--->\n");
                        printf("Inserire NOME NODO\n>>");
                        fflush(stdin);
                        gets(inserire.stringa);
                        inserimento(&head,&list,inserire);
                        system("PAUSE");system("cls");break;
                case 3: printf("\n\t<---ELIMINAZIONE---->\n");
                        eliminazione(&head,&list);
                        system("PAUSE");system("cls");break;
                case 4: printf("\n\t<----EXIT---->\n");
                        scelta=5;break;
                default:printf("\n\t<----INPUT ERROR---->\n");
                        system("PAUSE");system("cls");break;
                        }
    }while(scelta!=5);
return 0;
}

void crea_lista(NODO **head, INFO_FIELD **list)
{
    strcpy((*head)->dato.stringa, "NODO SENTINELLA");
    (*head)->p_next=NULL;
    (*list)->cnt=0;
}

void visita(NODO **head, INFO_FIELD **list)
{
    NODO *tmp;
    short i=0;
    tmp=malloc(sizeof(NODO));
    if(tmp!=NULL)
    {
        if((*head)->p_next==NULL)
            printf("\n<---LISTA VUOTA--->\n");
        else
        {
            printf("\n<---LISTA CIRCOLARE--->\n");
            tmp=(*head);
            for(i=0;i<(*list)->cnt;i++)
            {
                printf("NODO>> %hd - NOME>>%s\n", i, tmp->dato.stringa);
                tmp=tmp->p_next;
            }
        }
    }
}

void inserimento(NODO **head, INFO_FIELD **list, INFO_FIELD inserire)
{
    NODO *ptr;
    ptr=malloc(sizeof(NODO));
    if(ptr!=NULL)
    {
        strcpy(ptr->dato.stringa,inserire.stringa);
        ptr->p_next=(*head);
        (*head)=ptr;
        (*list)->cnt++;
    }
}

void eliminazione(NODO **head, INFO_FIELD **list)
{
    NODO *ptr;
    ptr=malloc(sizeof(NODO));
    if(ptr!=NULL)
    {
        if((*head)->p_next==NULL)
        {
            free(*head);
            (*head)=NULL;
            (*list)->cnt--;
        }
        else
        {
            ptr=(*head)->p_next;
            free(*head);
            (*head)=ptr;
            (*list)->cnt--;
        }
    }
}
