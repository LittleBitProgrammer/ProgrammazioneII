//ESERCIZIO 1. Scrivere una fuction C "char low_upp(char ch)" che cambia
//il carattere in input da minuscolo a maiuscolo e viceversa automaticamente.
#include <stdio.h>
#include <stdlib.h>
char low_upp(char ch); /** Function principale **/
int main()
{
    char ch;
    printf("Inizio del programma\n");
    printf("Inserire il carattere:\n>>");
    fflush(stdin); /** Pulizia del Buffer **/
    scanf("%c",&ch); /** Prendiamo il carattere in INPUT **/
    ch=low_upp(ch); /** Ch diventerà uguale al ritorno della function **/
    printf("CARATTERE MODIFICATO:\n--->%c", ch); /** Stampa a video del carattere modificato **/

return 0;
}
char low_upp(char ch)
{
    char mod;
    mod=ch^32; /** XOR bit 32 **/
return mod; /** Return della Function **/
}
