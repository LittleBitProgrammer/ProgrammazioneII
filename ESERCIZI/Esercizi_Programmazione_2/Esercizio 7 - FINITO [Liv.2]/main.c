/**Ripetere l’esercizio precedente nel caso
che l’input sia una stringa di caratteri contenenti i bit del
numero.**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conversione(char *string, int n); /** Function principale **/
int main()
{
    char string[16];  /** Inizializzazione della stringa in INPUT **/
    int n, i;
    printf("Inserisci la stringa di bit:\n");
    printf("<<-NUMERO PARI- VIENE LETTO 0 >>\n");
    printf("<<-NUMERO DISPARI- VIENE LETTO 1 >>\n");
    printf(">>");
    fflush(stdin);
    gets(string); /** INPUT STRINGA **/
    n=strlen(string); /** Conteggio lunghezza stringa **/
    for(i=n-1;i>=0;i--) /** Scorro la stringa e tutti i caratteri diversi da 0 e 1 li converto in base al loro modulo **/
    {
        if(string[i]%2==0) /** Se il modulo è uguale a 0, i-esimo elemento divento uno 0 **/
            string[i]='0';
        else /** Se il modulo per 2 è diverso da 0, allora diventa un 1 **/
            string[i]='1';
    }
    conversione(string,n); /** Richiamo alla Function **/
return 0;
}

void conversione(char *string, int n) /** Function **/
{
    int somma=0, i=n-1, pot=1, j=0;
    char binario[10]; /** Array dove andremo ad inserire le cifre decimali **/
    while(i>=0)

    {
        somma+=pot*(string[i]%2); /** A Somma si addizziona il modulo per la base del BIT all'i-esimo elemento di string moltiplicato per il valore della della sua posizione **/
        string[i--]/=10; /** Diviamo per la base 10 l'i-esimo elemento di string **/
        pot=pot<<1; /** Sfruttiamo le proprietà dello shift per elevare al quadrato pot **/
    }
    printf("\nL'input in decimale e'\n>> %d", somma);
    printf("\nL'array in ordine");
    while(somma>0)
    {
        binario[j++]=(somma%10)+0x30; /** Passiamo all'array di CHAR il modulo della somma e addizioniamo 48 in esadecimale per trasformalo in un char **/
        somma/=10; /** Dividiamo somma per la base 10 per passare ad analizzare la prossima cifra decimale **/
    }
    for(i=j-1, pot=1; i>=0 ;i--, pot++) /** Stampa dell'array al contrario **/
        printf("\nELEMENTO DI POSTO %d >> %c",pot , binario[i]);
}
