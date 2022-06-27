/* Scrivere una function C per costruire una lista ordinata in ordine alfabetico a partire da un nomi di
nomi in ordine casuale, come nel seguente. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    char nome[15];
    struct lista *p_next;
}LISTA;

void show_list(LISTA *ptr);
void ordina(LISTA **head, char *nomi[], short n);

int main()
{
    char *nomi[11]={"Giuseppe","Mario","Anna","Angela","Valeria","Fabrizio","Marianna","Giovanni","Patrizia","Sara","Valentina"};
    LISTA *head=NULL;

    ordina(&head, nomi, 11);
    show_list(head);
    return 0;
}

void show_list(LISTA *ptr)
{
    while(ptr->p_next!=NULL)
    {
        puts(ptr->nome);
        ptr=ptr->p_next;
    }
}

void ordina(LISTA **head, char *nomi[], short n)
{
    short i=0;

    while(i<n)
    {
        LISTA *prev, *curr, *nodo;

        nodo=malloc(sizeof(LISTA));
        strcpy(nodo->nome, nomi[i]); //PREPARO IL MIO NODO ITERATIVAMENTE PER IL CONTROLLO

        for(prev=NULL,curr=*head; curr!=NULL && (strcmp(curr->nome,nomi[i])>0); prev=curr, curr=curr->p_next);
        //PARTENDO DAL PRECEDENTE NULL, E DAL CORRENTE=HEAD, SCORRO LA LISTA FIN QUANDO IL CORRENTE E' NULLO (FINE LISTA) E
        //NODO->NOME SARà MINORE, OGNI VOLTA AVANZERANNO I DUE PUNTATORI DI UN NODO
        //FATTO CIO, SARO POSIZIONATO BENE PER L'INSERIMENTO

            //CASO 1: INSERIMENTO IN TESTA
            if(prev==NULL)//SE SI FERMA ALL'INIZIO
            {
                nodo->p_next=(*head);
                *head=nodo;
            }
            else if(curr==NULL)//CASO 2: INSERIMENTO IN CODA, ALLA FINE
            {
                prev->p_next=nodo;
                nodo->p_next=NULL;//O = coda, è lo stesso
            }
            else//CASO 3: INSERIMENTO TRA 2 NODI
            {
                prev->p_next=nodo;
                nodo->p_next=curr;
            }

        i++;
    }//FINE WHILE

}
