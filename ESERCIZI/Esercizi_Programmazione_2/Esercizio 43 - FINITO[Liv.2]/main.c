#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char INFO;
struct persona{
            INFO x;
            struct persona *p_next;
                };
typedef struct persona PERSONA;

PERSONA *ricorsiva(INFO stringa[]);
PERSONA *crealista();
void ins_testa(char *,  PERSONA **, PERSONA **);
void ins_nodo(char *, short , PERSONA **);
PERSONA *iterativa(INFO stringa[]);

int main()
{
    INFO stringa[]={"STRINGA PROVA"};
    PERSONA *head_list, *p_list;
    printf("INIZIO PROGRAMMA\n");
    head_list=ricorsiva(stringa);
    p_list=head_list;
    printf("\nCREAZIONE LISTA RICORSIVA->>\n");
    while((p_list)!=NULL)
    {
        printf("\t->>%c\n", p_list->x);
        (p_list)=(p_list)->p_next;
    }
    printf("\nCREAZIONE LISTA ITERATIVA->>\n");
    head_list=iterativa(stringa);
    p_list=head_list;
    while((p_list)!=NULL)
    {
        printf("\t->>%c\n", p_list->x);
        (p_list)=(p_list)->p_next;
    }

return 0;
}

PERSONA *ricorsiva(INFO stringa[])
{
    PERSONA *testa;
    if(stringa[0]=='\0')
        return NULL;
    else
    {
        testa=malloc(sizeof(PERSONA));
        testa->x=stringa[0];
        testa->p_next=ricorsiva(stringa+1);
        return testa;
    }
}

PERSONA *iterativa(INFO stringa[])
{
    PERSONA *testa, *punt;
    short i=0;
    testa=crealista();
    punt=NULL;
    while(*(stringa+i)!='\0')
    {
        if(i==0)
            ins_testa(stringa,&testa,&punt);
        i++;
        ins_nodo(stringa,i,&punt);
    }
return testa;
}

void ins_testa(char *array, PERSONA **testa, PERSONA **coda)
{
    PERSONA *ptr;
    ptr=(PERSONA *) calloc(1,sizeof(PERSONA));
    if(ptr!=NULL)
    {
        ptr->x=*array;
        ptr->p_next=NULL;
        *testa=ptr;
        *coda=*testa;
    }
}
void ins_nodo(char *stringa, short i, PERSONA **punt)
{
    PERSONA *ptr;
    ptr=(PERSONA *) calloc(1,sizeof(PERSONA));
    if(ptr!=NULL)
    {
        (*punt)->p_next=ptr;
        ptr->x=*(stringa+i);
        ptr->p_next=NULL;
        (*punt)=ptr;
    }
}

PERSONA *crealista()
{
    PERSONA *testa;
    testa = NULL;
    return testa;
}

