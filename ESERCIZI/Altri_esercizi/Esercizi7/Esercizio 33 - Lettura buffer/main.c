/*Scrivere una function C che legga, mediante una variabile “buffer” di 200char, un file testo e lo
visualizzi sullo schermo 40 char per riga e 25 righe per ogni schermata, fermandosi finché non viene premuto
un tasto per continuare.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char *nome_file, buffer[200]={"lol"};
    nome_file=(char *)malloc(10);

    printf("Inserisci il nome del file con l'estensione:\n");
    fgets(nome_file, 10, stdin); fflush(stdin);

    fp=fopen(nome_file, "a+");

    fwrite(buffer, sizeof(char), 40, fp);
    printf("\n%s\n", buffer);
}
