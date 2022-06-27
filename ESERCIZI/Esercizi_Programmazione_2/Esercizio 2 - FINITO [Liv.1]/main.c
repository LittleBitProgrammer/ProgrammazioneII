// Esercizio 2. Scrivere una function in C "char rotate(char ch, int n_bit)" per
// ruotare di n bit, verso destra o verso sinistra, il contenuto di una variabile
//char mediante gli operatori bitwise.
#include <stdio.h>
#include <stdlib.h>
char rotate(char ch, int n_bit); /** Function per la rotazione dei bit **/
int main()
{
    unsigned char ch;
    int n_bit;
    printf("Inizio del programma\n");
    printf("Inserisci carattere:\n>>");
    fflush(stdin);
    scanf("%c", &ch);
    printf("\nDi quanti bit vuoi ruotare?  ");
    scanf("%d",&n_bit); /** Numero dei bit da ruotare **/
    ch=rotate(ch, n_bit); /** Richiamo alla function **/
    printf("\nCarattere Ruotato\n--->%c",ch);
return 0;
}
char rotate(char ch, int n_bit)
{
    int scelta;
    unsigned char ch2, mask=0;
    printf("\nVuoi ruotare a:\n[1] DESTRA\n[2] SINISTRA\n");
    scanf("%d",&scelta);
    switch(scelta){
            case 1:
                    mask=ch<<(8-n_bit);/** ROTAZIONE DESTRA **/
                    ch=ch>>n_bit;
                    ch2=ch|mask; break;
            case 2:
                    mask=ch>>(8-n_bit);/** ROTAZIONE SINISTRA **/
                    ch=ch<<n_bit;
                    ch2=ch|mask; break;
            default: exit(1); break;
                    }
return ch2;
}
