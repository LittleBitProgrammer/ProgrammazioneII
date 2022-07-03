#include <stdio.h>
#include <string.h>

int main()
{
    /* Creazione buffer di scrittura */
    char buffer[61];
    int character, i = 0;

    do
    {
        character = getchar();
        buffer[i++] = (char)character;
    } while (character != '\n');

    buffer[i - 1] = '\0'; /* Sovrascriviamo \n con \0 */
    printf("La stringa %s e' lunga %d caratteri\n", buffer, strlen(buffer));
    
    /* Stampo un carattere */
    putchar(*(buffer + 2));
    return 0;
}