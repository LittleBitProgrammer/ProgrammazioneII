/*Confrontando i risultati con quelli delle relative funzioni del C, scrivere una function C che restituisca la
prima occorrenza di una sottostringa in una stringa senza usare strstr(...). */

#include <stdio.h>
#include <stdlib.h>
short strstr(char t[], char p[]);
int main()
{
    char *testo="Mannacc a maronn", *pattern="nn";

    short i=strstr(testo, pattern);
    printf("%hd\n", i);
}

short strstr(char t[], char p[])
{
    char i=0, j=0;

    do
    {
        if(t[i]==p[j] && t[i+1]==p[j+1])
            return i;
        i++;
    }while(i<strlen(t));
}
