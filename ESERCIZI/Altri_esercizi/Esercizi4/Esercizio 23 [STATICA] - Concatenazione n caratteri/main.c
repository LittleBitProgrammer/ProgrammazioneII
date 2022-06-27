/*Confrontando i risultati con quelli delle relative funzioni del C ed utilizzando per le stringhe
V l’allocazione statica
o l’allocazione dinamica
scrivere una function C che accetti in input il numero n e legga da tastiera n caratteri (uno alla volta)
costruendo la stringa che li contiene (parametro di output), senza usare strcat(...). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100
void concatena(char a[]);

int main()
{
    char stringa[n];

    printf("Inserisci i caratteri singolarmente\n");
    concatena(stringa);

    printf("La stringa inserita e': \n");
    puts(stringa);

}

void concatena(char a[])
{
     char i=0, c;

     do
     {
         a[i++]=c=getchar();
         fflush(stdin);
     }while(c!='\n');
}
