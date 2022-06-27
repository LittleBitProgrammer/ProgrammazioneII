#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void cancella(char testo[], char pattern[]); /** Function **/

int main()
{
    char *testo, *pattern;
    testo=(char *)malloc(100); /** Allocazione dinamica del testo **/
    printf("INIZIO PROGRAMMA!\n");
    printf("\nInserisci Testo:\n>>");
    gets(testo); /** INPUT testo **/
    realloc(testo,strlen(testo)); /** Realloco per risparmiare memoria sui blocchi non occupati in precedenza **/
    pattern=(char *)malloc(25); /** Allocazione dinamica del pattern **/
    printf("\nInserisci Pattern:\n>>");
    gets(pattern); /** INPUT pattern **/
    realloc(pattern,strlen(pattern));/** Realloco per risparmiare memoria sui blocchi non occupati in precedenza **/
    printf("\nIl testo con i PATTERN eliminati e':\n-->");
    cancella(testo,pattern); /** Passaggio alla function TESTO e PATTERN **/
return 0;
}

void cancella(char *testo, char *pattern)
{
    short i;
    for(i=0;i<strlen(testo);i++) /** Ciclo FOR per scorrere l'array **/
    {
        if(strncmp(&testo[i],pattern,strlen(pattern))==0) /** La STRNCMP parte dall'i-esimo elemento di TESTO, confronta con PATTERN fino alla lunghezza del PATTERN **/
            memmove(&testo[i],&testo[strlen(pattern)+i],strlen(testo)-i); /** La MEMMOVE sostituisceil PATTERN trovato e sovrappone il restante testo alla sua destra, avvicinando il terminatore di stringa **/
    }
    realloc(testo,strlen(testo)); /** Realloco per risparmiare memoria sui blocchi non occupati in precedenza **/
    puts(testo); /** Stampa del TESTO **/
}
