#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct info{
        short cnt;
        char stringa[15];
        };
typedef struct info INFO_FIELD;
struct nodo{
        INFO_FIELD data;
        struct nodo *p_next;
        };
typedef struct nodo NODO;
void crea_lista(NODO **head, INFO_FIELD **list);
void ins_testa(NODO **head, INFO_FIELD **list, INFO_FIELD inserire);
void elim_testa(NODO **head, INFO_FIELD **list);
void ins_nodo(NODO **head, INFO_FIELD **list, INFO_FIELD inserire);
void elim_nodo(NODO **head, INFO_FIELD **list);
void visita(NODO **head, INFO_FIELD **list);
int main()
{
    short scegli;
    NODO *head;
    INFO_FIELD *list, inserire;
    head=malloc(sizeof(NODO));
    list=malloc(sizeof(INFO_FIELD));
    crea_lista(&head,&list);
    do{
        printf("\t<---GESTIONE LISTA CIRCOLARE--->\n");
        printf("INSERIRE:\n[1] VISITA LISTA\n[2] INSERISCI TESTA\n[3] INSERIRE IN MEZZO\n[4] ELIMINA TESTA\n[5] ELIMINA NODO\n[6] NUMERO NODI INSERITI\n[7] EXIT\n>>");
        fflush(stdin);
        scanf("%hd",&scegli);
        switch(scegli){
                case 1: printf("\n\t<---VISITA LISTA--->\n");
                        visita(&head,&list);
                        system("PAUSE");system("cls");break;
                case 2: printf("\n\t<---INSERIMENTO TESTA--->\n");
                        printf("Inserire NOME NODO\n>>");
                        fflush(stdin);
                        gets(inserire.stringa);
                        ins_testa(&head,&list,inserire);
                        system("PAUSE");system("cls");break;
                case 3: printf("\n\t<---INSERIRE IN MEZZO--->\n");
                        printf("Inserire NOME NODO\n>>");
                        fflush(stdin);
                        gets(inserire.stringa);
                        ins_nodo(&head,&list,inserire);
                        system("PAUSE");system("cls");break;
                case 4: printf("\n\t<---ELIMINAZIONE TESTA--->\n");
                        elim_testa(&head,&list);
                        system("PAUSE");system("cls");break;
                case 5: printf("\n\t<---ELIMINA NODO--->\n");
                        elim_nodo(&head, &list);
                        system("PAUSE");system("cls");break;
                case 6: printf("\n\t<---NUMERO NODI--->\n");
                        printf("NUMERO NODI->>%hd\n", (list)->cnt);
                        system("PAUSE");system("cls");break;
                case 7: scegli=7;
                        printf("\n\t<---EXIT---->\n");break;
                default:printf("\n\t<---INPUT ERROR--->\n");
                        system("PAUSE"); system("cls");break;
        }


    }while(scegli!=7);
return 0;
}

void crea_lista(NODO **head, INFO_FIELD **list)
{
    (*head)=NULL;
    (*list)->cnt=0;
}

void visita(NODO **head, INFO_FIELD **list)
{
    short i=0;
    NODO *tmp;
    tmp=malloc(sizeof(NODO));
    if((*head)==NULL)
        printf("\n\t<---LISTA VUOTA--->\n");
    else
    {
        tmp=(*head);
        printf("\n<---LISTA CIRCOLARE--->\n");
        for(i=0;i<(*list)->cnt;i++)
        {
            printf("NODO>> %hd - NOME>> %s\n",i, tmp->data.stringa);
            tmp=tmp->p_next;
        }
    }
}

void ins_testa(NODO **head, INFO_FIELD **list, INFO_FIELD inserire)
{
    NODO *ptr;
    ptr=malloc(sizeof(NODO));
    strcpy(ptr->data.stringa,inserire.stringa);
    ptr->p_next=(*head);
    (*head)=ptr;
    (*list)->cnt++;
}

void ins_nodo(NODO **head, INFO_FIELD **list, INFO_FIELD inserire)
{
    NODO *ptr;
    ptr=malloc(sizeof(NODO));
    if(ptr!=NULL)
    {
        strcpy(ptr->data.stringa,inserire.stringa);
        ptr->p_next=(*head)->p_next;
        (*head)->p_next=ptr;
        (*list)->cnt++;
    }
}

void elim_testa(NODO **head, INFO_FIELD **list)
{
    NODO *ptr;
    ptr=malloc(sizeof(NODO));
    ptr=(*head)->p_next;
    free(*head);
    (*head)=ptr;
    (*list)->cnt--;
}

void elim_nodo(NODO **head, INFO_FIELD **list)
{
    NODO *ptr;
    ptr=malloc(sizeof(NODO));
    ptr=(*head)->p_next;
    (*head)->p_next=ptr->p_next;
    free(ptr);
    (*list)->cnt--;
}
