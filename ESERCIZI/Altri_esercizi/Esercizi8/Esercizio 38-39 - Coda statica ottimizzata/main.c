/* Simulare in C la gestione di una coda (queue) tramite array statico circolare (può essere anche un array
di struct) creando le funzioni di manipolazione enqueue() [inserimento] e dequeue() [eliminazione]. Il
programma deve prevedere un menù che consenta di scegliere l’operazione da eseguire.*/
#include <stdio.h>
#include <stdlib.h>
#define size_coda 10
char coda[size_coda];
short testa=0, fondo=0;
int main()
{
    char el_da_ins;
    short scelta,scelta2=1, n_elementi=0;

    do
    {
        system("cls");
        printf("\t***MENU***\n\n");
        printf("[1] Inserisci elementi nella coda.\n[2] Elimina elementi dalla coda\n[3] Visualizza coda\n[0] Esci\n|-----> ");
        scanf("%hd", &scelta);

        switch(scelta)
        {
        case 0:
            exit(1);
            break;

        case 1:
            system("cls");
            printf("Inserisci l'elemento: ");
            fflush(stdin);
            scanf("%c", &el_da_ins);
            enqueue(el_da_ins, &n_elementi);

            break;

        case 2:
            system("cls");
            printf("Elemento eliminato.\n");
            dequeue(&n_elementi);
            break;

        case 3:
            system("cls");
            printf("CODA:\n");
            for(char i=0; i<size_coda; i++)
            {
                printf("%c ", coda[i]);
            }
            break;

        }

        printf("\nVuoi proseguire?\n|---->");
        fflush(stdin);
        scanf("%hd", &scelta2);
    }while(scelta2!=0);

}

void enqueue(char el, short* n_el)
{
    if(*n_el<size_coda)
    {
        fondo=testa+*n_el;
        fondo%=size_coda;
        *n_el+=1;
        printf("n_el= %hd", *n_el);
        coda[fondo]=el;
    }
}

void dequeue(short* n_el)
{
    if(*n_el>0)
    {
        testa+=1;
        testa%=size_coda;
        *(n_el)--;
        coda[fondo]='0';
    }
}
