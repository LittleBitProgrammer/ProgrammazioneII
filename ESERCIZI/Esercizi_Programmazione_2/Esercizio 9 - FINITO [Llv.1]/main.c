#include <stdio.h>
#include <stdlib.h>
int differenza(int x, int y); /** Function per la DIFFERENZA **/
int main()
{
    int n1, n2;
    printf("INIZIO PROGRAMMA\n");
    do{
    printf("Inserisci il SOTTRAENDO ( INT )");
    printf("\n>>");
    scanf("%d", &n1); /** INPUT primo numero **/
    printf("Inserisci il MINUENDO ( INT )");
    printf("\n>>");
    scanf("%d", &n2); /** INPUT secondo numero **/
    }while(n1<n2); /** Ripeto il ciclo fin quando il primo intero è più grande o uguale al secondo **/
    printf("\n\nLa DIFFERENZA binaria dei due interi (N1-N2) e': %d", differenza(n1,n2)); /** OUTPUT con il richiamo diretto alla function **/
return 0;
}

int differenza(int x, int y) /** FUNCTION **/
{
    int resto=0, prestito=1;
    while(prestito>0) /** Ripeto il ciclo fino a quando la variabile "prestito" è maggiore di 0 **/
    {
        resto=x^y; /** XOR tra X e Y **/
        prestito=~x&y; /** AND tra X NEGATO e Y **/
        prestito=prestito<<1; /** SHIFT a sinistra "prestito" di 1 bit **/
        x=resto; y=prestito; /** Assegnazione nuovi valori per la successiva iterazione del ciclo **/
    }
return resto; /** Valore da ritornare nel main **/
}
