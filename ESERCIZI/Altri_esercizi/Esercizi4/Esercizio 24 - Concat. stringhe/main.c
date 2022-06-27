/*Confrontando i risultati con quelli delle relative funzioni del C ed utilizzando per le stringhe
o l’allocazione statica
V l’allocazione dinamica
scrivere una function C che restituisca la concatenazione di due stringhe (parametri di input) senza usare
strcat(...). È a scelta restituire la concatenazione delle due stringhe in una terza variabile (parametro di
output o function stessa) oppure nella prima delle due variabili di input.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *stringa1, *stringa2, *strtot;
    char s1, s2;

    printf("Inserisci il size della prima stringa: ");
    scanf("%hd", &s1);
    fflush(stdin);
    stringa1=(char *)malloc(s1+1);
    printf("Inserisci la prima stringa: ");
    fgets(stringa1, s1, stdin);

    system("cls");

    fflush(stdin);
    printf("Inserisci il size della seconda stringa: ");
    scanf("%hd", &s2);
    fflush(stdin);
    stringa2=(char *)malloc(s1+1);
    printf("Inserisci la seconda stringa: ");
    fgets(stringa2, s2, stdin);
    system("cls");


    concatena(stringa1, stringa2, strtot);
    free(stringa1);
    free(stringa2);
    free(strtot);
}

void concatena(char *str1, char *str2, char *strtot)
{
    strtot=(char *)malloc(strlen(str1)+strlen(str2)+2);
    printf("strlen= %hd\n", strlen(strtot));
    strcpy(strtot, str1);
    strcpy(strtot+strlen(str1), str2);
    puts(strtot);
}
