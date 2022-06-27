#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 10
void stampa(char [], int *, int *,int *);
void enqueue(char [], int *, int *, int *);
void dequeue(char [], int *, int*, int *);
int main()
{
    char coda[11]={' '};
    int testa=0, fondo=0, n_elem=0;
    short scelta;
    do{
        printf("Cosa vuoi fare?\n");
        printf("[1] - QUEUE\n[2] - ENQUEUE\n[3] - VISUALIZZA\n[4] - EXIT\n>>");
        fflush(stdin);
        scanf("%hd", &scelta);
        switch(scelta){
            case 1: enqueue(coda,&testa,&fondo,&n_elem);system("PAUSE");system("cls");break;
            case 2: dequeue(coda,&testa,&fondo,&n_elem);system("PAUSE");system("cls");break;
            case 3: stampa(coda,&n_elem,&testa,&fondo);system("PAUSE");system("cls");break;
            case 4: scelta=4;break;
            default:printf("\nSCELTA NON CONSENTITA\n");break;}
    }while(scelta!=4);
return 0;
}

void enqueue(char coda[], int *testa, int *fondo, int *n_elem)
{
    printf("\n---%d---\n", *n_elem);
    if((*n_elem)<MAX)
    {

        (*fondo)=(*testa)+(*n_elem);
        (*fondo)=(*fondo)%MAX;
        printf("\nInserisci Elemento \t fondo: %d\n>>", *fondo);
        fflush(stdin);
        coda[*fondo]=getchar();
        (*n_elem)++;
    }
    else
        printf("\n---OVERFLOW DELLA CODA---\n");
}

void dequeue(char coda[], int *testa, int *fondo, int *n_elem)
{
    if((*n_elem)>0)
    {
        printf("Elemento Eliminato: %d",coda[*testa]);
        (*testa)++;
        (*testa)=(*testa)%MAX;
        (*n_elem)--;
    }
    else
        printf("\n---ERRORE, CODA VUOTA---\n");
}

void stampa(char coda[], int *n_elem, int *testa,int *fondo)
{
    short i=0;
    if(*n_elem==0)
        printf("\nCODA VUOTA!\n");
    else
    {
        printf("\nSTAMPA DELLA CODA\tElem: %d\tfonfo: %d\n",*n_elem,*fondo);
        for(i=(*testa);i<=(*fondo);i++)
            printf("%d -> %c\n", i, coda[i]);
            printf("\n****%hd****\n", i);
    }
}
