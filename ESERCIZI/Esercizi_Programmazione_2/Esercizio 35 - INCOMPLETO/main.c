#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[200], nome_file[100];
    FILE *fp;
    printf("INIZIO PROGRAMMA\n");
    printf("\nInserire NOME FILE\n>>");
    gets(nome_file);
    if((fp=fopen(nome_file, "r"))==NULL)
    {
        printf("<----ERRORE APERTURA FILE---->");
        exit(1);
    }
    while(!feof(fp)) /** Ciclo WHILe fin quando non termina il file **/
    {
       fgets(buffer,200,fp);
       printf("\t%xhh\n",buffer);
    }
    fclose(fp);
return 0;
}
