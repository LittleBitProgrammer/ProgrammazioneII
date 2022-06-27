/* Simulare in C la gestione di una pila (stack) tramite array statico (può essere anche un array di struct)
creando le funzioni di manipolazione push() [inserimento] e pop() [eliminazione]. Il programma deve
prevedere un menù che consenta di scegliere l’operazione da eseguire.*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE_STACK 10

int main()
{
    char pila[SIZE_STACK];
    char scelta2=1, head=-1, el_da_ins;
    short scelta;

    do
    {
        system("cls");
        printf("\t***MENU***\n\n");
        printf("[1] Inserisci elementi nella pila.\n[2] Elimina elementi dalla pila\n[3] Visualizza pila\n[0] Esci\n|-----> ");
        scanf("%hd", &scelta);

        switch(scelta)
        {
        case 0:
            exit(1);

        case 1:
            system("cls");
            if(head<SIZE_STACK-1)
            {
                printf("Inserisci elemento: ");
                fflush(stdin);
                scanf("%c", &el_da_ins);
                push_p(el_da_ins, pila, &head);
            }
            else
                printf("Pila piena.\n");
            break;

        case 2:
            system("cls");
            printf("Elemento in cima eliminato.\n");
            fflush(stdin);
            pop_p(pila, &head);
            break;

        case 3:
            system("cls");
            printf("PILA:\n");
            for(char i=0; i<=head; i++)
            {
                printf("%c ", pila[i]);
            }
            break;

        }

        printf("\nVuoi proseguire?\n|---->");
        fflush(stdin);
        scanf("%c", &scelta2);
    }while(scelta2!='0');

}

void push_p(char elemento, char *pila, char *head)
{
    *(pila+ ++*head)=elemento;
}

void pop_p(char pila[], char* head)
{
    *(pila+ *head--)=0;
}
