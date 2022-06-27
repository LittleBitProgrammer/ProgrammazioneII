#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 11 /** NUMERO DI ELEMENTI DELLA PILA **/
void push(char pila[], int *stack); /** Function per inserimento elemento **/
void stampa(char pila[]); /** Function per la stampa della PILA **/
void pop(char pila[], int *stack); /** Function per l'eliminazione elemento **/

int main()
{
    char pila[MAX]={' '};
    int *stack=0, scelta;
    printf("INIZIO PROGRAMMA");
    do{
        printf("\nChe operazione vuoi eseguire?");
        printf("\n[1] INSERIRE ELEMENTO\n[2] ELIMINARE ELEMENTO\n[3] STAMPA DELLA PILA\n[4] EXIT\n>>");
        fflush(stdin);
        scanf("%d", &scelta);
        switch(scelta){ /** SCELTA **/
            case 1: push(pila,&stack);system("PAUSE"); system("cls");break; /** INSERIMENTO **/
            case 2: pop(pila,&stack);system("PAUSE"); system("cls");break; /** ELIMINAZIONE **/
            case 3: stampa(pila);system("PAUSE"); system("cls");break; /** VISITA **/
            case 4: scelta=0;break; /** USCITA **/
            default: printf("\nScelta non consentita\n");break;
            }
    }while(scelta!=0);
return 0;
}

void push(char pila[], int *stack)
{
    if(*stack<MAX)
    {
        printf("\nChe CARATTERE vuoi inserire?\n>>");
        fflush(stdin);
        scanf("%c", &pila[*stack]); /** Inserimento in fondo alla PILA **/
        (*stack)++; /** Incremento la variabile STACK per il prossimo inserimento**/
    }
    else
        printf("\n<---ERRORE, STACK PIENO--->\n");
}

void stampa(char pila[])
{
    short i=0;
    for(i=MAX-1;i>=-1;i--)
        printf("\n%d -- %c", i, pila[i]);
}

void pop(char pila[], int *stack)
{
    if(*stack==0) /** Se lo STACK e' vuoto **/
        printf("\n<---ERRORE, STACK VUOTO--->\n");
    else
    {
        (*stack)--; /** Sottraggo 1 allo stack **/
        pila[*stack]=' '; /** Elimino l'elemento dello STACK **/
        printf("\nCarattere eliminato!\n");
    }
}
