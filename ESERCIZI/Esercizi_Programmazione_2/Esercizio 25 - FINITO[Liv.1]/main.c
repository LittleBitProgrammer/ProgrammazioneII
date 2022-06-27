#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned function(char testo[], char pattern[]); /** Function che esegue la ricerca della prima occorrenza **/

int main()
{
    char testo[100], pattern[25];
    printf("INIZIO PROGRAMMA\n");
    printf("\nInserisci testo:\n>>");
    gets(testo); /** INPUT testo **/
    printf("\nInserisci pattern:\n>>");
    gets(pattern); /** INPUT pattern **/
    printf("\nRISULTATO DEL PATTERN:\n-->%u",function(testo,pattern)); /** Stampa a video del risultato confrontato con STRSTR **/
    printf("\nRISULTATO DEL STRSTR:\n-->%u", strstr(testo, pattern));
return 0;
}
unsigned function(char *testo, char *pattern)
{
    short i;
    for(i=0;i<strlen(testo);i++) /** Ciclo FOR che scorre il testo **/
    {
        if((strncmp(&testo[i],pattern,strlen(pattern)))==0) /** STRNCMP tra l'indice i-esimo di Testo, il pattern e la lunghezza di quest'ultimo **/
            return (unsigned *)(i+&testo[0]); /** Se il confronto è positivo, faccio ritornare l'indirizzo di memoria **/
    }
return NULL; /** Altrinenti ritorna un valore NULLO **/
}
