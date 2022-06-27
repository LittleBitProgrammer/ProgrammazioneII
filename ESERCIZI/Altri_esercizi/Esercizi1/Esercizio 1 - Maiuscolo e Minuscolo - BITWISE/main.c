/* Scrivere una function C
char low_upp(char ch)
che cambia il carattere in input da minuscolo a maiuscolo e viceversa automaticamente
mediante gli operatori
bitwise*/

#include <stdio.h>
#include <stdlib.h>
char low_upp(char ch);

int main()
{
    char c;
    printf("Inserisci un carattere: ");
    fflush(stdin);
    scanf("%c", &c);

    printf("Il carattere in uscita e' %c.\n", low_upp(c));

}

char low_upp(char ch)
{
    ch^=0x20;
    return ch;
}
