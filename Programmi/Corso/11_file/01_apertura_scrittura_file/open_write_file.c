#include <stdio.h>
#include <string.h>

int main()
{
    char *testo = "Nel mezzo del cammin di nostra vita\n"
                  "mi ritrovai per una selva oscura\n"
                  "ché la diritta via era smarrita.\n";
    
    int i;
    char *char_pointer;
    char filename[13];
    FILE *fp;

    printf("Inserire il nome del file (massimo 8 caratteri) = ");
    scanf("%s", filename);
    strcat(filename, ".txt");
    printf("Nome file = %s\n", filename);

    fp = fopen(filename, "w");
    char_pointer = testo;
    while(*char_pointer != '\0')
    {
        putc(*char_pointer, fp);
        char_pointer++;
    }
    fclose(fp);

    return 0;
}