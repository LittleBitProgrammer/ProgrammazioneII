#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void occorrenze(char *testo, char *pattern, int n); /** Function per il calcolo delle occorrenze **/
int main()
{
    char *testo, *pattern; /** Dichiarazione del TESTO e del PATTERN **/
    short n;
    printf("INIZIO PROGRAMMA\n");
    printf("\nInserire quantitativo di caratteri MAX dell'array:\n>>");
    scanf("%hd",&n); /** INPUT della grandezza del size **/
    fflush(stdin);
    testo=(char *) malloc(n*sizeof(char)); /** MALLOC della Variabile TESTO **/
    pattern=(char *) malloc(25);/** MALLOC della variabile PATTERN **/
    printf("\nInserire la STRINGA:\n>>");
    gets(testo); /** INPUT TESTO **/
    testo=realloc(testo,strlen(testo)); /** Realloco la memoria per risparmiare i blocchi di memoria non occupati in precdenza **/
    printf("\nInserire il PATTERN:\n>>");
    gets(pattern);/** INPUT PATTERN **/
    occorrenze(testo,pattern,n); /** Richiamo alla function **/
    free(testo); free(pattern);/** Libero lo spazio di memoria **/
return 0;
}

void occorrenze(char *testo, char *pattern, int n)
{
    short i, cont=0;
    int *occorrenze;
    occorrenze=(int *) malloc((10*sizeof(short))+1);
    for(i=0;i<strlen(testo);i++) /** Ciclo FOR per scorrere il testo **/
    {
        if(strncmp(&testo[i],pattern,strlen(pattern))==0) /** La STRNCMP parte dall'i-esimo elemento di TESTO, confronta con PATTERN fino alla lunghezza del PATTERN **/
            {
                cont++; /** Incremento la variabile CONT **/
                occorrenze[cont]=(*testo+i); /** Assegno ogni indirizzo all'array **/
            }
    }
    if(cont==0) /** Se le occorrenze sono 0 stampo a video il PRINTF successivo **/
        printf("\nNon esistono occorrenze del PATTERN nel testo inserito!!\n");
    else
    {
        printf("\nIl numero di occorrenze e':\n---> %d", cont); /** Stampa a video delle occorrenze **/
        printf("\nGli indirizzi delle locazioni di memoria sono:");
        for(i=1;i<cont+1;i++) /** Ciclo FOR per la stampa dell'array **/
            printf("\n--->%p", (void *) (occorrenze[i])) ;
    }
    free(occorrenze);
}
