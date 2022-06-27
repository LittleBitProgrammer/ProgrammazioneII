#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sostituire(char *testo, char *pattern, char *sostituzione); /** FUNCTION **/
int main()
{
    char *testo, *pattern, *sostituzione;
    testo=(char *) malloc(1000); /** MALLOC Variabili **/
    pattern= (char *) malloc(25); /** MALLOC Variabili **/
    sostituzione= (char *) malloc(25); /** MALLOC Variabili **/
    printf("INIZIO PROGRAMMA\n");
    printf("Inserisci TESTO:\n>>");
    gets(testo); /** INPUT TESTO **/
    printf("\nInserisci PATTERN:\n>>");
    gets(pattern); /** INPUT PATTERN **/
    printf("\nInserisci SOSTITUZIONE:\n>>");
    gets(sostituzione); /** INPUT SOSTITUZIONE **/
    realloc(testo,strlen(testo)); /** REALLOC per eliminare gli sprechi di memoria **/
    realloc(pattern, strlen(pattern)); /** REALLOC per eliminare gli sprechi di memoria **/
    realloc(sostituzione, strlen(sostituzione));/** REALLOC per eliminare gli sprechi di memoria **/
    sostituire(testo,pattern,sostituzione); /** RICHIAMO alla Function **/
    free(pattern); free(testo); free(sostituzione); /** Libero gli spazi di memoria **/
return 0;
}

void sostituire(char *testo, char *pattern, char *sostituzione)
{
    short i, numero=0, y=0, x=strlen(sostituzione)-strlen(pattern); /** X e' la differenza tra SOSTITUZIONE e PATTERN **/
    if(strlen(pattern)==strlen(sostituzione)) /** Lunghezza di PATTERN e SOSTITUZIONE uguale **/
    {
        for(i=0;i<strlen(testo);i++) /** FOR per scorrere l'array **/
            if(strncmp(&testo[i],pattern,strlen(pattern))==0) /** Quando il PATTERN e' uguale al PATTERN **/
                memmove(&testo[i], sostituzione,strlen(sostituzione)); /** Sostituisco il PATTERN con SOSTITUZIONE **/
    }
    else if(strlen(pattern)<strlen(sostituzione)) /** Lunghezza di PATTERN minore di SOSTITUZIONE **/
    {
        for(i=0;i<strlen(testo);i++) /** Ciclo FOR per conta le occorrenze **/
        {
            if(strncmp(&testo[i],pattern,strlen(pattern))==0)
                numero++; /** Contatore di occorrenze **/
        }
        y=strlen(testo)+(numero*x); /** Totale di grandezza che ci serve per REALLOC **/
        testo=realloc(testo, y); /** REALLOC del testo **/
        for(i=0;i<strlen(testo);i++) /** FOR per scorrere l'array **/
        {
            if(strncmp(&testo[i],pattern,strlen(pattern))==0) /** Quando il PATTERN e' uguale a SOSTITUZIONE **/
            {
                memmove(&testo[i+strlen(pattern)+x],&testo[i+strlen(pattern)],strlen(testo)-(i+strlen(pattern)-1)); /** Aggiungo i BYTE dopo la parola che devo sostituire **/
                memmove(&testo[i],sostituzione,strlen(sostituzione)); /** Sostituisco il PATTERn con SOSTITUZIONE **/
            }
        }
    }
    else /** Lunghezza del PATTERN minore di SOSTITUZIONE **/
    {
        for(i=0;i<strlen(testo);i++) /** Ciclo FOR per conta le occorrenze **/
        {
            if(strncmp(&testo[i],pattern,strlen(pattern))==0)
                numero++; /** Contatore occorrenze **/
        }
        y=strlen(testo)-(numero*x); /** Totale di grandezza che ci serve per REALLOC **/
        testo=realloc(testo, y); /** REALLOC del testo **/
        for(i=0;i<strlen(testo);i++) /** FOR per scorrere l'array **/
        {
            if(strncmp(&testo[i],pattern,strlen(pattern))==0) /** Quando il PATTERN e' uguale a SOSTITUZIONE **/
            {
                memmove(&testo[i+strlen(pattern)+x],&testo[i+strlen(pattern)],strlen(testo)-(i+strlen(pattern)-1)); /** REALLOCO il testo togliendo i BYTE che non mi servono **/
                memmove(&testo[i],sostituzione,strlen(sostituzione)); /** Sostituisco PATTERN con sostituzione **/
            }
        }
    }
    puts(testo); /** OUTPUT testo **/
}
