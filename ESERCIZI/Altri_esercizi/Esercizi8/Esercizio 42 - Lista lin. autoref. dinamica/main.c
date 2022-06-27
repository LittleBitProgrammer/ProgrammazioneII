/*Realizzare la gestione di una lista lineare mediante menù (visualizzazione mediante visita, inserimento
in testa, inserimento in mezzo, eliminazione in testa, eliminazione in mezzo) implementando la lista lineare
con una struttura autoriferente dinamica.*/
#include "mioheader.h";

int main()
{
    short scelta, scelta2=1;
    Persona *head=crea_lista();//HEAD DELLA LISTA;

    do
    {
        system("cls");
        printf("*MENU GESTIONE LISTA LINEARE AUTORIFERENTE DINAMICA*\n\n");
        printf("[1] Visualizza lista\n[2] Inserisci in testa\n[3] Inserisci in mezzo\n[4] Elimina in testa\n[5] Elimina in mezzo\n\n|-----> ");
        scanf("%hd", &scelta);
        switch(scelta)
        {
        case 1:
            show_list(&head);
            break;
        case 2:
            ins_testa(&head);
            printf("\nElemento aggiunto correttamente.\n");
            break;
        case 3:
            ins_mezzo(&head);
            printf("\nElemento aggiunto correttamente.\n");
            break;
        case 4:
            elim_testa(&head);
            printf("Eliminazione effettuata.\n");
            break;
        case 5:
            elim_mezzo(&head);
            printf("Eliminazione effettuata.\n");
            break;
        default:
            printf("Hai sbagliato\n");
            system("pause");
        }

        printf("\nVuoi uscire?\n[0] Si\n[1] No\n|---> ");
        scanf("%hd", &scelta2);
    }while(scelta2!=0);


}
