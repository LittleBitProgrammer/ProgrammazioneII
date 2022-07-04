#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int main()
{
    int i;
    int write_buffer[SIZE], read_buffer[SIZE];
    FILE *fp;

    /* Popolazione array scrittura */
    for(i = 0; i < SIZE; i++)
    {
        write_buffer[i] = 2 * i;
    }

    /* Apertura file binario in scrittura */
    if((fp = fopen("file_binario.dat", "wb")) == NULL)
    {
        puts("Errore apertura file");
        exit(1);
    }

    /* Scrittura file binario */
    if(fwrite(write_buffer, sizeof(int), SIZE, fp) != SIZE)
    {
        puts("Errore scrittura file");
        exit(1);
    }
    fclose(fp);

    /* Apertura file binario in lettura */
    if((fp = fopen("file_binario.dat", "rb")) == NULL)
    {
        puts("Errore apertura file");
        exit(1);
    }

    /* Lettura file binario */
    if(fread(read_buffer, sizeof(int), SIZE, fp) != SIZE)
    {
        puts("Errore lettura file");
        exit(1);
    }
    fclose(fp);

    /* Stampa dei due vettori */
    for(i = 0; i < SIZE; i++)
    {
        printf("vet[1] = %2d\tvet[2] = %2d\n", write_buffer[i], read_buffer[i]);
    }
    return 0;
}