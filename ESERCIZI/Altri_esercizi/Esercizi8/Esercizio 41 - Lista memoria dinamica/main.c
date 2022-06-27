/*Simulare in C la gestione delle camere di un albergo mediante liste lineari rappresentate su un array di
struct: i principali campi sono le “informazioni” (numero di camera, cliente, etc.) ed i “link” (puntatori ai
nodi della lista).
[Suggerimento: L’array di struct corrisponde alla memoria in cui allocare la lista delle camere libere
(ListaLibera) e la lista delle camere occupate (ListaDati). È necessario creare prima la ListaLibera,
inizializzando l’array dei link in modo che ogni componente punti alla componente successiva. Ogni nodo da inserire nella
ListaDati, quando una camera viene assegnata ad un cliente, è prelevato dalla testa della ListaLibera ed
inserito nella testa della ListaDati; mentre il nodo da eliminare dalla ListaDati, quando una particolare camera
viene liberata, è restituito alla ListaLibera (in testa) per poter essere riutilizzato in seguito.]
*/

#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    char n_stanza;
    char stato[5];
    struct Nodo *p_next;
}nodo[8]={ {0, "Vuoto", &(nodo[1])}, {1, "Vuoto", &(nodo[2])}, {2, "Vuoto", &(nodo[3])}, {3, "Vuoto", &(nodo[4])},
                  {4, "Vuoto", &(nodo[5])}, {5, "Vuoto", &(nodo[6])}, {6, "Vuoto", &(nodo[7])}, {7, "Vuoto", NULL}};
struct Nodo *p_libere, *p_occupate; //SONO LE HEAD DELLE DUE LISTE CHE CONDIVIDONO LA STESSA MEMORIA (NODO, "DB DELL'ALBERGO).


int main()
{
    short scelta,scelta2=1, num_stanza;

    p_libere=&nodo[0];
    p_occupate=NULL; //INIZIALMENTE SARA' VUOTO L'ALBERGO.

    do
    {
        system("cls");
        printf("\t*** ALBERGO OIDO-CROP ***\n\n[1] Registra nuovo cliente\n[2] Libera una stanza\n[3] Visualizza stato camere\n[0] Esci\n\n|-----> ");
        scanf("%hd", &scelta);

        switch(scelta)
        {
        case 1:
            inserisci_cliente();
            break;

        case 2:
            system("cls");
            printf("Che stanza vuoi liberare?\n|-----> ");
            scanf("%hd", &num_stanza);
            elimina_cliente(num_stanza);
            break;

        case 3:
            system("cls");
            printf("STATO CAMERE:\n\n");
            for(char i=0; i<8; i++)
            {
                printf("Camera %hd: ", i);
                puts(nodo[i].stato);
            }
            puts("\n");
            break;

        default:
            printf("Scelta errata, addio.\n\n");
            break;
        }

        system("PAUSE");
        system("cls");
        printf("Vuoi continuare?\n[1] Si\n[0] Esci\n|-----> ");
        scanf("%hd", &scelta2);

    }while(scelta2!=0);

}

void inserisci_cliente()
{
    if(p_occupate<p_libere)
    {
        p_occupate=p_libere;
        strcpy(p_occupate->stato, "Pieno");
        p_libere=p_libere->p_next;
        printf("Cliente aggiunto.\n");
    }
    else if(p_libere!=NULL)
    {
        if(p_occupate-p_libere>1)
        {
            strcpy(p_libere->stato, "Pieno");
            p_libere=p_libere->p_next;
            printf("Cliente aggiunto.\n");
        }
        else
        {
            strcpy(p_libere->stato, "Pieno");
            p_libere=p_occupate->p_next;
            printf("Cliente aggiunto.\n");
        }
    }
    else
        printf("Albergo pieno.\n");

}

void elimina_cliente(short num_stanza)
{
    if(strcmp(nodo[num_stanza].stato, "Pieno")!=0)
    {
        printf("Errore, camera già libera!\n");
    }
    else if(p_occupate<p_libere)
    {
        p_libere=&nodo[num_stanza];
        strcpy(p_libere->stato, "Vuoto");
    }
    else if(p_occupate>p_libere)
    {
        if(&nodo[num_stanza]<p_libere)
        {
            p_libere=&nodo[num_stanza];
            strcpy(p_libere->stato, "Vuoto");
        }
        else
        {
            strcpy(nodo[num_stanza].stato, "Vuoto");
        }
    }

}
