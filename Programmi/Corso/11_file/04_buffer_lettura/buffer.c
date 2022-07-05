#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 30

int main()
{
    char buffer[BUFFSIZE];
    char filename[60];
    FILE *fp;

    puts("Inserire il nome del file");
    gets(filename);

    if((fp = fopen(filename, "r")) == NULL)
    {
        puts("Errore apertura file");
        exit(1);
    }

    while(!feof(fp))
    {
        fgets(buffer, BUFFSIZE, fp);
        printf("%d\t%s\n", feof(fp), buffer);
    }

    fclose(fp);

    return 0;
}