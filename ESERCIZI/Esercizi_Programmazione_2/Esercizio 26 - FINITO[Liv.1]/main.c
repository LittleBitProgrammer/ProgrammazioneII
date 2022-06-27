#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void occorrenze(char *testo, char *pattern); /** Function per il calcolo delle occorrenze **/
int main()
{
    char *testo, *pattern; /** Dichiarazione del TESTO e del PATTERN **/
    short n;
    printf("INIZIO PROGRAMMA\n");
    printf("\nInserire quantitativo di caratteri MAX dell'array:\n>>");
    scanf("%hd",&n); /** INPUT della grandezza del size **/
    fflush(stdin);
    testo=(char *) malloc(n*sizeof(char)); /** MALLOC della Variabile TESTO **/
    pattern=(char *) malloc(10);/** MALLOC della variabile PATTERN **/
    printf("\nInserire la STRINGA:\n>>");
    gets(testo); /** INPUT TESTO **/
    printf("\nInserire il PATTERN:\n>>");
    gets(pattern);/** INPUT PATTERN **/
    occorrenze(testo,pattern); /** Richiamo alla function **/
    free(testo); free(pattern);/** Libero lo spezio di memoria **/
return 0;
}

void occorrenze(char *testo, char *pattern)
{
    short i, cont=0;
    for(i=0;i<strlen(testo);i++) /** Ciclo FOR per scorrere il testo **/
    {
        if(strncmp(&testo[i],pattern,strlen(pattern))==0) /** La STRNCMP parte dall'i-esimo elemento di TESTO, confronta con PATTERN fino alla lunghezza del PATTERN **/
            {
                cont++; /** Incremento la variabile CONT **/
                printf("\nL'ocorrenza numero %d si trova in posizione %p",cont,(i+&testo[0])); /** STAMPA a video dell'occorrenza seguente e del suo indirizzo **/
            }
    }
    if(cont==0) /** Se le occorrenze sono 0 stampo a video il PRINTF successivo **/
        printf("\nNon esistono occorrenze del PATTERN nel testo inserito!!\n");
}
