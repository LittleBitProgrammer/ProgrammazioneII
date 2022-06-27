/*Confrontando i risultati con quelli delle relative funzioni del C ed utilizzando per le stringhe
o l’allocazione statica
V l’allocazione dinamica
scrivere una function C che accetti in input il numero n e legga da tastiera n caratteri (uno alla volta)
costruendo la stringa che li contiene (parametro di output), senza usare strcat(...). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char n;
    char *stringa;

    printf("Quanti caratteri vuoi inserire?\n|-----> ");
    scanf("%hd", &n);
    fflush(stdin);

    stringa=(char *)malloc(n+1);
    function(n, stringa);

    puts(stringa);
}

void function(char n, char *s)
{
    char c;

    for(char i=0; i<n; i++)
    {
        printf("Inserisci l'%hd-iesimo carattere: ", i);
        scanf("%c", &c);
        fflush(stdin);

        *(s+i)=c;
    }

    *(s+n)='\0';
}
