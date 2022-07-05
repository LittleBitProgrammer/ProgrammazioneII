#include <stdio.h>
#include <string.h>

int main()
{
    char character;
    char filename[13]; /* testo + .txt + \0 */
    FILE *fp;

    printf("Inserire il nome del file (massimo 8 caratteri) = ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    fp = fopen(filename,"r");
    do
    {
        character = getc(fp);
        putchar(character);
    } while (character != EOF);

    fclose(fp);
    
    return 0;
}