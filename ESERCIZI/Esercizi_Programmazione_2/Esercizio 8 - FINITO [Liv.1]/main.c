#include <stdio.h>
#include <stdlib.h>
int somma(int x, int y); /** Function che esegue l'addizione **/
int main()
{
    int n1, n2;
    printf("INIZIO PROGRAMMA\n");
    printf("Inserisci primo ADDENDO ( INT )");
    printf("\n>>");
    scanf("%d", &n1); /** INPUT primo numero **/
    printf("Inserisci secondo ADDENDO ( INT )");
    printf("\n>>");
    scanf("%d", &n2); /** INPUT secondo numero **/
    printf("\n\nLa SOMMA binaria dei due interi e': %d", somma(n1,n2)); /** OUTPUT del risultato con richiamo diretta alla FUNCTION **/
return 0;
}

int somma(int x, int y) /** Function **/
{
    int rip=1, somma=0;
    while(rip>0) /** Esegue le operazione fin quando il RIPORTO � maggiore di 0 **/
    {
        somma=x^y; /** XOR tra X ed Y **/
        rip=x&y; /** AND tra X ed Y **/
        rip=rip<<1; /** SHIFT a sinistra di 1 bit **/
        x=somma; y=rip; /** Assegnazione nuovi valori per la successiva ITERAZIONE del ciclo **/
    }
return somma; /** Restituzione valore nel MAIN **/
}
