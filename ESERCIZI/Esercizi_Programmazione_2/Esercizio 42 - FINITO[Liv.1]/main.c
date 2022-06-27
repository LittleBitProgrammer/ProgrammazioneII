#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
typedef struct{
            char stringa[15]; /** STRUCT INFO del NODO **/
                }INFO_FIELD;
struct persona{
            INFO_FIELD info;
            struct persona *p_next; /** STRUCT NODO **/
                };
typedef struct persona PERSONA; /** Creazione del tipo NODO **/

PERSONA *crea_lista(); /** Function per la Creazione della lista VUOTA **/
void visualizza_lista(PERSONA *p_head); /** Function per la VISITA della LISTA **/
void ins_testa(INFO_FIELD inserimento, PERSONA **p_head); /** Function per inserimento in TESTA **/
void ins_nodo(INFO_FIELD inserimento, char cerca_nome[], PERSONA *p_pointer); /** Function per inserimento in MEZZO **/
void elim_testa(PERSONA **p_head); /** Function per ELIMINAZIONE della TESTA **/
void elim_nodo(char cerca_nome[], PERSONA *p_pointer); /** Functio per Eliminare nodo **/

int main()
{
    short scelta; /** SWITCH\CASE **/
    char cerca_nome[10]; /** Stringa utilizzata per le operazioni **/
    PERSONA *p_head, *p_pointer; /** Defininiamo due puntatori alla STRUCT PERSONA **/
    INFO_FIELD inserimento; /** NOME NODO DA INSERIRE **/
    p_head=crea_lista(); /** CREAZIONE LISTA VUOTA **/
    do{
        printf("<------GESTIONE LISTA----->\n");
        printf("\nINSERIRE:\n[0] VISITA LISTA\n[1] INSERIMENTO IN TESTA\n[2] INSERIMENTO IN MEZZO\n[3] ELIMINAZIONE IN TESTA\n[4] ELIMINAZIONE IN MEZZO\n[5] EXIT\n>>");
        fflush(stdin);
        scanf("%hd", &scelta); /** INPUT SCELTA **/
        switch(scelta){
                case 0: visualizza_lista(p_head); system("PAUSE"); system("cls");break; /** VISITA LISTA **/
                case 1: printf("\n<--INSERIMENTO IN TESTA-->\n");
                        printf("Inserisci NOME nodo:\n>>");
                        fflush(stdin);
                        gets(inserimento.stringa); /** INPUT nome TESTA **/
                        ins_testa(inserimento,&p_head); /** Richiamo Function **/
                        system("PAUSE"); system("cls");break;
                case 2: printf("\n<--INSERIMENTO IN MEZZO-->\n");
                        p_pointer=p_head; /** Aggiorno il puntatore al nodo corrente **/
                        printf("Inserire NOME del NODO dopo il quale inserire l'ELEMENTO:\n>>");
                        fflush(stdin);
                        gets(cerca_nome); /** INPUT nome del NODO da cercare e passare alla function **/
                        printf("Inserire NOME nodo:\n>>");
                        fflush(stdin);
                        gets(inserimento.stringa); /** INPUT del nome del NODO che andremo ad inserire dopo quello cercato in precedenza **/
                        ins_nodo(inserimento,cerca_nome,p_pointer); /** Richiamo Function **/
                        system("PAUSE"); system("cls"); break;
                case 3: printf("\n<--ELIMINAZIONE TESTA-->\n");
                        elim_testa(&p_head);
                        system("PAUSE"); system("cls"); break;
                case 4: printf("\n<--ELIMINAZIONE NODO-->\n");
                        p_pointer=p_head; /** Aggiorno il puntatore al nodo corrente **/
                        printf("\nInserire NODO da eliminare:\n>>");
                        fflush(stdin);
                        gets(cerca_nome); /** Input nome NODO da eliminare **/
                        elim_nodo(cerca_nome, p_pointer);
                        system("PAUSE"); system("cls"); break;
                case 5: scelta=5; printf("\n<--USCITA-->\n");break; /** uscita **/
                default: printf("\n<---ERRORE INSERIMENTO--->\n");break;
                    }
    }while(scelta!=5);
return 0;
}


PERSONA *crea_lista()
{
    PERSONA *testa;
    testa=NULL;
    return testa;
}

void visualizza_lista(PERSONA *p_head)
{
    short i=0; /** Variabile utilizzata per contare i nodi **/
    while(p_head!=NULL) /** Finche' la LISTA non e' finita **/
    {
        printf("NODO = %hd - NOME = %s\n",i, p_head->info.stringa); /** Stampa informazione **/
        p_head=p_head->p_next; /** Aggiorna il puntatore al nodo successivo **/
        i++; /** aggiorna contatore **/
    }
}
void ins_testa(INFO_FIELD inserimento, PERSONA **p_head)
{
    PERSONA *ptr; /** Puntatore alla Struct PERSONA **/
    ptr=(PERSONA *) calloc(1,sizeof(PERSONA)); /** Alloca in memoria lo spazio della struct **/
    strcpy(ptr->info.stringa,inserimento.stringa); /** Inserisce l'INPUT preso in precedenza nella struct **/
    ptr->p_next=*p_head;
    *p_head=ptr; /** Aggiorna HEAD al nuovo puntatore **/
    printf("\n<---INSERIMENTO IN TESTA EFFETTUATO CON SUCCESSO--->\n");
}
void ins_nodo(INFO_FIELD inserimento, char cerca_nome[], PERSONA *p_pointer)
{
    PERSONA *ptr; /** Puntatore alla Struct PERSONA **/
    if(p_pointer!=NULL) /** Se il nodo non e' uguale a NULL **/
    {
        ptr=(PERSONA *) calloc(1,sizeof(PERSONA)); /** Alloco a PTR la grandezza della struct PERSONA **/
        while((p_pointer)->p_next!=NULL) /** Finche' non finisce la lista **/
        {
            if(strcmp((p_pointer)->info.stringa,cerca_nome)==0) /** Se uno dei Nodi corrisponde a quello cercato **/
            {
                strcpy(ptr->info.stringa,inserimento.stringa); /** Passo le INFO da inserire alle INFO di PTR **/
                ptr->p_next=(p_pointer)->p_next; /** Passo a PTR il p_next **/
                (p_pointer)->p_next=ptr; /** Agggiorno p_pointer al novoo puntatore **/
            }
            (p_pointer)=(p_pointer)->p_next; /** Scorro i p_next per scorrere la lista **/
        }
    }
    printf("\n<---INSERIMENTO IN MEZZO EFFETTUATO CON SUCCESSO--->\n");
}
void elim_testa(PERSONA **p_head)
{
    PERSONA *ptr; /** Puntatore alla struct PERSONA **/
    ptr=(PERSONA *) calloc(1,sizeof(PERSONA));/** Alloco a PTR la grandezza della struct PERSONA **/
    if((*p_head)->p_next==NULL) /** Se e' presente un solo nodo nella Lista, cioe' solo la testa **/
    {
        free(*p_head); /** Libero la testa della coda **/
        (*p_head)=NULL; /** Lista VUOTA **/
    }
    else /** Se sono presenti piu' nodi nella LISTA **/
    {
        ptr=(*p_head)->p_next; /** PTR diventa uguale al nodo dopo la testa **/
        free(*p_head); /** Dealloco la Testa **/
        (*p_head)=ptr; /** Aggiorno la Testa della lista **/
    }
    printf("\n<---ELIMINAZIONE IN TESTA EFFETTUATA CON SUCCESSO--->\n");
}
void elim_nodo(char cerca_nome[], PERSONA *p_pointer)
{
    PERSONA *ptr; /** Puntatore alla Struct PERSONA **/
    ptr=(PERSONA *) calloc(1,sizeof(PERSONA)); /** Alloco a PTR la grandezza della Struct PERSONA **/
    if(p_pointer!=NULL) /** Finche' la LISTA non e' finita **/
    {
        if(strcmp(p_pointer->info.stringa,cerca_nome)!=0) /** Se il nodo TESTA non e' uguale all'elemento cercato **/
        {
            ptr=p_pointer->p_next; /** PTR diventa uuale al nodo successivo la TESTA **/
            while(ptr->p_next!=NULL) /** Finche' il nodo successivo non e' il FONDO della lista **/
            {
                if(strcmp(ptr->info.stringa,cerca_nome)==0) /** Se le info del PTR sono uguali a quelle dell'elemento cercato **/
                {
                    p_pointer->p_next=ptr->p_next; /** Aggiorno il puntatore a quello successivo **/
                    free(ptr); break; /** Libero PTR e termino il ciclo **/
                }
                p_pointer=p_pointer->p_next; /** Aggiorno p_pointer con quello successivo **/
                ptr=ptr->p_next; /** Aggiorno PTR a quello successivo **/
            }
        }
    }
    else /** Altrimenti **/
        printf("\n<--LISTA VUOTA-->\n"); /** LISTA VUOTA **/
}
