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
        struct nodo *p_prev;
        };
typedef struct nodo NODO;
void crea_lista(NODO **testa, NODO **coda);
void visita_testa(NODO *testa);
void visita_coda(NODO *coda);
void ins_testa(NODO **testa, NODO **coda, INFO_FIELD inserimento);
void elim_testa(NODO **testa, NODO **coda);
void ins_nodo(NODO **testa, NODO **coda, INFO_FIELD cerca_nodo, INFO_FIELD inserimento);
void elim_nodo(NODO **testa, NODO **coda, INFO_FIELD cerca_nodo);
int main()
{
    short scelta=0;
    INFO_FIELD inserimento, cerca_nodo;
    NODO *testa, *coda;
    testa=(NODO *) calloc(1,sizeof(NODO));
    coda=(NODO *) calloc(1,sizeof(NODO));
    crea_lista(&testa,&coda);
    do{
        printf("\n\t<----GESTIONE LISTA BIDIREZIONALE---->\n");
        printf("INSERIRE:\n[1] VISITA DALLA TESTA\n[2] VISITA DALLA CODA\n[3] INSERIRE TESTA\n[4] ELIMINA TESTA\n[5] INSERIMENTO NODO\n[6] ELIMINAZIONE NODO\n[7] EXIT\n>>");
        fflush(stdin);
        scanf("%hd",&scelta);
        switch(scelta){
                case 1: printf("\n\t<---VISITA DALLA TESTA--->\n");
                        visita_testa(testa);
                        system("PAUSE");system("cls");break;
                case 2: printf("\n\t<---VISITA DALLA CODA--->\n");
                        visita_coda(coda);
                        system("PAUSE");system("cls");break;
                case 3: printf("\n\t<---INSERIMENTO IN TESTA--->\n");
                        printf("Inserire NOME NODO\n>>");
                        fflush(stdin);
                        gets(inserimento.stringa);
                        ins_testa(&testa,&coda,inserimento);
                        system("PAUSE");system("cls");break;
                case 4: printf("\n\t<---ELIMINAZIONE IN TESTA--->\n");
                        elim_testa(&testa,&coda);
                        system("PAUSE");system("cls");break;
                case 5: printf("\n\t<---INSERIMENTO IN MEZZO--->\n");
                        printf("Inserire NODO PRECEDENTE ALL'INSERIMENTO\n>>");
                        fflush(stdin);
                        gets(cerca_nodo.stringa);
                        printf("Inserire NOME NODO\n>>");
                        fflush(stdin);
                        gets(inserimento.stringa);
                        ins_nodo(&testa,&coda,cerca_nodo,inserimento);
                        system("PAUSE");system("cls");break;
                case 6: printf("\n\t<---ELIMINAZIONE NODO--->\n");
                        printf("Inserire NOME NODO da eliminare\n>>");
                        fflush(stdin);
                        gets(cerca_nodo.stringa);
                        elim_nodo(&testa,&coda,cerca_nodo);
                        system("PAUSE");system("cls");break;
                case 7: printf("\n\t<---EXIT--->\n");break;
                default:printf("\n<---INPUT ERROR--->\n");break;
                    }
    }while(scelta!=7);

return 0;
}

void crea_lista(NODO **testa, NODO **coda)
{
    (*testa)->p_next=NULL;
    (*testa)->p_prev=NULL;
    (*testa)=NULL;
    (*coda)=(*testa);
}

void visita_testa(NODO *testa)
{
    short i=0;
    NODO *tmp;
    tmp=(NODO *) calloc(1,sizeof(NODO));
    tmp=testa;
    if(tmp==NULL)
        printf("\n<---LISTA BIDIREZIONALE VUOTA--->\n");
    else
    {
        while(tmp!=NULL)
        {
            printf("NODO>> %hd - NOME>> %s\n", i, tmp->dato.stringa);
            tmp=tmp->p_next;
            i++;
        }
    }

}

void visita_coda(NODO *coda)
{
    short i=0;
    NODO *tmp;
    tmp=(NODO *) calloc(1,sizeof(NODO));
    tmp=coda;
    if(tmp==NULL)
        printf("\n<---LISTA BIDIREZIONALE VUOTA--->\n");
    else
    {
        while(tmp!=NULL)
        {
            printf("NODO>> %hd - NOME>> %s\n", i, tmp->dato.stringa);
            tmp=tmp->p_prev;
            i++;
        }
    }
}

void ins_testa(NODO **testa, NODO **coda, INFO_FIELD inserimento)
{
    NODO *ptr;
    ptr=(NODO *)calloc(1,sizeof(NODO));
    if((*testa)==NULL)
    {
        strcpy(ptr->dato.stringa,inserimento.stringa);
        ptr->p_next=NULL;
        ptr->p_prev=NULL;
        (*testa)=ptr;
        (*coda)=(*testa);
    }
    else if((*testa)->p_next==NULL && (*testa)!=NULL)
    {
        strcpy(ptr->dato.stringa,inserimento.stringa);
        ptr->p_prev=NULL;
        (*testa)->p_prev=ptr;
        (*coda)=(*testa);
        ptr->p_next=(*testa);
        (*testa)=ptr;
    }
    else
    {
        strcpy(ptr->dato.stringa,inserimento.stringa);
        ptr->p_prev=NULL;
        ptr->p_next=(*testa);
        (*testa)->p_prev=ptr;
        (*testa)=ptr;
    }
}

void elim_testa(NODO **testa, NODO **coda)
{
    NODO *ptr;
    ptr=(NODO *) calloc(1,sizeof(NODO));
    if((*testa)==NULL)
    {
        printf("\n\t<---LISTA VUOTA--->\n");
    }
    else if((*testa)->p_next==NULL)
    {
        free(*testa);
        (*testa)=NULL;
        (*coda)=(*testa);
        printf("\n\t<---ELIMINAZIONE AVVENUTA--->\n");
        printf("\n\t<---ADESSO LA LISTA E' VUOTA--->\n");
    }
    else
    {
        ptr=(*testa)->p_next;
        ptr->p_prev=NULL;
        free(*testa);
        (*testa)=ptr;
        printf("\n\t<---ELIMINAZIONE AVVENUTA--->\n");
    }

}

void ins_nodo(NODO **testa, NODO **coda, INFO_FIELD cerca_nome, INFO_FIELD inserimento)
{
    NODO *ptr, *tmp;
    ptr=(NODO *)calloc(1,sizeof(NODO));
    tmp=(NODO *)calloc(1,sizeof(NODO));
    if((*testa)==NULL)
    {
        printf("\n\t<---LISTA VUOTA--->\n");
    }
    else if((*testa)==(*coda))
    {
        strcpy(ptr->dato.stringa,inserimento.stringa);
        (*testa)->p_next=ptr;
        ptr->p_prev=(*testa);
        ptr->p_next=NULL;
        (*coda)=ptr;
    }
    else if(strcmp((*testa)->dato.stringa,cerca_nome.stringa)==0)
    {
        strcpy(ptr->dato.stringa,inserimento.stringa);
        ptr->p_next=(*testa)->p_next;
        ptr->p_prev=(*testa);
        (*testa)->p_next->p_prev=ptr;
        (*testa)->p_next=ptr;
    }
    else if(strcmp((*coda)->dato.stringa,cerca_nome.stringa)==0)
    {
        strcpy(ptr->dato.stringa,inserimento.stringa);
        ptr->p_next=NULL;
        (*coda)->p_next=ptr;
        ptr->p_prev=(*coda);
        (*coda)=ptr;
    }
    else
    {
        tmp=(*testa)->p_next;
        while(tmp!=NULL)
        {
            if(strcmp(tmp->dato.stringa,cerca_nome.stringa)==0)
            {
                strcpy(ptr->dato.stringa,inserimento.stringa);
                ptr->p_next=tmp->p_next;
                ptr->p_next->p_prev=ptr;
                tmp->p_next=ptr;
                ptr->p_prev=tmp;
            }
            tmp=tmp->p_next;
        }
    }
}

void elim_nodo(NODO **testa, NODO **coda, INFO_FIELD cerca_nodo)
{
    NODO *ptr, *tmp;
    ptr=(NODO *) calloc(1,sizeof(NODO));
    tmp=(NODO *) calloc(1,sizeof(NODO));
    if(strcmp((*testa)->dato.stringa,cerca_nodo.stringa)==0)
        elim_testa(testa,coda);
    else if(strcmp((*coda)->dato.stringa,cerca_nodo.stringa)==0)
    {
        ptr=(*coda)->p_prev;
        ptr->p_next=NULL;
        (*coda)->p_prev=NULL;
        free(*coda);
        (*coda)=ptr;
    }
    else
    {
        tmp=(*testa)->p_next;
        while(tmp!=NULL)
        {
            if(strcmp(tmp->dato.stringa,cerca_nodo.stringa)==0)
            {
                ptr=tmp;
                tmp->p_prev->p_next=ptr->p_next;
                ptr->p_next->p_prev=tmp->p_prev;
                free(ptr);
            }
            tmp=tmp->p_next;
        }
    }
}
