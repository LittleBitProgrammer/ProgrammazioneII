/**Scrivere una function C di conversione di un intero positivo da base 2 a base 10,
mediante l’ algoritmo delle divisioni successive, che generi un array di caratteri
contenenti le cifre decimali**/
#include <stdio.h>
#include <stdlib.h>
void function (unsigned char * , int); /** DICHIARO LA MIA PROCEDURA **/
int main()
{
    int x, i;
    unsigned char binario[10]={'0','0','0','0','0','0','0','0','0','0'};/** inizializzo l'array vuoto **/
    printf("Inserisci il numero: \n>>");
    scanf("%d",&x);
    function(binario,x);/** Passiamo alla Procedura l'indirizzo dell' array e il dato in INPUT **/
    printf("\nLa stampa in decimale e':\n>>");
    for(i=9;i>=0;i--) /** Ciclo FOR per la stampa dell' array **/
        printf("%c", binario[i]);
return 0;
}


void function (unsigned char *binario , int x) /** Procedura **/
{
    int somma=0, i=0, pow=1;  /** Dichiarazione delle variabili **/
    while(x>0) /** Fin quando X è maggiore di 0 **/
    {
        somma+=(pow*(x%2));
        x/=10;     /** DIVIDO IL NUMERO PER 10 **/
        pow=pow<<1;     /** ESEGUO UNO SHIFT A SINISTRA DI 1 DELLA VARIABILE POTENZA COSI' CHE LA POTENZA VENGA MOLTIPLICATA A 2 A 2 **/
    }
    while(somma>0)
    {
        binario[i]=(somma%10)+0x30;     /** PONGO L'I-ESIMO ELEMENTO DELL'ARRAY UGUALE AL MODULO DELLA SOMMA PIU' 48 PER LA STAMPA DEI CARATTERI **/
        somma=somma/10; /** DIVIDO LA SOMMA PER 10 **/
        i++; /** Ad ogni iterazione sommo 1 alla variabile i **/
    }
}
