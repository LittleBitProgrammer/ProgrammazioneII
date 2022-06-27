/*Usando l’allocazione dinamica e le funzioni C per manipolare le stringhe, scrivere una function C che
restituisca il numero totale delle occorrenze di una sottostringa in una stringa e
o [liv.1] ne visualizzi la posizione di tutte le occorrenze trovate.
V [liv.2] restituisca in un array la posizione di tutte le occorrenze trovate. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char occ[10];

int main()
{
    char  *testo="trentatre trentini", *pattern="tr";
    occorrenze(testo, pattern);

    for(char i=0; i<10; i++)
    {
        printf("Occorrenza alla posizione [%hd]\n", occ[i]);
    }
}

void occorrenze(char *t, char *p)
{
    char i=0;
    char *tok=t;

    t=strstr(t, p);
    while(t!=NULL)
    {
            t+=strlen(p);
            occ[i++]=strlen(tok)-strlen(t)-strlen(p);
            t=strstr(t, p);
    }
}
