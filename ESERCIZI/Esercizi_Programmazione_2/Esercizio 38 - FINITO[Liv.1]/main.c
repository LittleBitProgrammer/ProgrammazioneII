#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 10
void stampa(char []); /** Function stampa della coda **/
void queue(char [], int *); /** Function inserimento **/
void enqueue(char [], int *, int); /** Function per eliminazione **/
int main()
{
    char coda[11]={' '}; /** CODA **/
    int inizio=0, testa=0; /** All'inizio testa = fondo perche' elementi = 0 **/
    short scelta;
    do{
        printf("Cosa vuoi fare?\n");
        printf("[1] - QUEUE\n[2] - ENQUEUE\n[3] - VISUALIZZA\n[4] - EXIT\n>>");
        fflush(stdin);
        scanf("%hd", &scelta);
        switch(scelta){
            case 1: queue(coda,&testa);system("PAUSE");system("cls");break;
            case 2: enqueue(coda,&inizio,testa);system("PAUSE");system("cls");break;
            case 3: stampa(coda);system("PAUSE");system("cls");break;
            case 4: scelta=4;break;
            default:printf("\nSCELTA NON CONSENTITA\n");break;}
    }while(scelta!=4);
return 0;
}

void stampa(char coda[])
{
    short i=0;
    printf("\nSTAMPA DELLA CODA\n");
    for(i=0;i<MAX;i++)
        printf("%d -> %c\n", i, coda[i]);
}

void queue(char coda[], int *fine)
{
    if(*fine<MAX)
    {
        printf("\nInserisci CARATTERE:\n>>");
        fflush(stdin);
        coda[*fine]=getchar();
        (*fine)++;
    }
    else
        printf("\ERRORE, CODA PIENA");
}
void enqueue(char coda[], int *inizio, int fine)
{
    if(fine<=(*inizio))
        printf("\nERRORE, CODA VUOTA!\n");
    else
    {
        coda[*inizio]=' ';
        (*inizio)++;
    }
}
