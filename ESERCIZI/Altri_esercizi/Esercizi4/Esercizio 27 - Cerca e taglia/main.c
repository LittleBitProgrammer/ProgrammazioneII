/*Utilizzando per le stringhe
o l’allocazione statica
o l’allocazione dinamica
scrivere una function C che elimini tutte le occorrenze di una data sottostringa in una stringa col minimo
numero di spostamenti di blocchi di memoria. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short occ[10]={0};
int main()
{
    char testo[]="trentatre trentini", *pattern="tr";
    printf("Testo= %s\nPattern = %s\n", testo,pattern);
    search_delete(testo, pattern);


}

void search_delete(char *t, char *p)
{

    char i=0, j=0;
    char *tok=t;

    t=strstr(t, p);
    while(t!=NULL)
    {
            t+=strlen(p);
            occ[i++]=strlen(tok)-strlen(t)-strlen(p);
            t=strstr(t, p);
    }
    t=tok;
    free(tok);

    for(i=0; i<3; i++)
    {
        printf("indice occorrenza= %hd\n", occ[i]);
    }

    char *dest, *src, num_byte;

    do
    {
        dest= (j==0) ? t+occ[j] : t+occ[j]-strlen(p);
        src=t+occ[j]+strlen(p);
        num_byte= (j!=2) ? occ[j+1]-occ[j]-strlen(p) : strlen(t)-occ[j]-strlen(p);

        memmove(dest, src, num_byte);

        j++;
    }while(j!=i);

    puts(t);

    realloc(t, strlen(t));
}
