#include <stdio.h>
#include <stdlib.h>
void operatori(int x, int *p); /** Function per la conversione utilizzando l'algoritmo delle divisioni successive **/
void bitwise(int x, int *r); /** Function per la conversione utilizzando gli operatori BITWISE **/
int main()
{
    int x;
    int r[32], p[32]; /** Dichiarazione dei due array dove andremo a porre i BIT **/
    printf("Inizio del programma!\n");
    printf("Inserisci Valore INT\n");
    printf(">>");
    scanf("%d", &x); /** INPUT valore da analizzare **/
    printf("\nCambio di BASE con OPERATORI DI QUOZIENTE E RESTO DELLA DIVISIONE INTERA:\n");
    system("PAUSE");
    printf(">>");
    operatori(x,p); /** Richiamo alla FUNCTION **/
    printf("\nCambio di BASE con OPERATORI BITWISE:\n>>");
    system("PAUSE");
    printf(">>");
    bitwise(x,r); /** Richiamo alla FUNCTION **/
    printf("\n");
return 0;
}
void operatori(int x, int *p)
{
    int j=0, resto, quoziente, b=0;
    while(quoziente>0) /** Fin quando il quoziente è maggiore di 0 **/
    {
        quoziente=x/2; /** Quoziente = divisione tra il numero in INPUT e la base 2 **/
        resto=x%2; /** Resto = Modulo tra l'INPUT e la base **/
        p[j++]=resto; /** Inseriamo il resto ( 0-1 ) al generico passo j **/
        x=quoziente; /** Assegniamo ad X il valore del quoziente per la prossima ITERAZIONE del ciclo **/
    }
    for(b=j-1;b>=0;b--) /** Ciclo FOR per la stampa dell'array **/
        printf("%d", p[b]);

}
void bitwise(int x, int *r)
{
    int j=0, b=0;
        for(b=0;b<32;b++) /** Assegniamo il valore 0 a tutti gli elementi dell'array **/
            r[b]=0;
        for(b=0;b<32;b++)
        {
            r[b]=x&1; /** AND bitwise tra X ed 1 **/
            x=x>>1; /** Shift a destra di 1 per passare ad analizzare il bit successivo **/
            j++;
            if(x==0) /** Uscita dal ciclo quando termina il numero da analizzare **/
                break;
        }
         for(b=j-1;b>=0;b--) /** Stampa dell'array **/
            printf("%d", r[b]);
}
