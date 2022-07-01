/**
 * @file number_to_bit.c1
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Algoritmo di conversione numerica a binaria (qualsiasi tipo di numero intero o reale)
 * @version 1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#define MAX_LEN (sizeof(char *) * 8)

/* Prototipi di funzione */
void populate_bit(short, char[], short[]);
void zero_array(short[]);
void print_array(short, short[]);

typedef union 
{
    long L;
    float F;
    short S[sizeof(long) / sizeof(short)];
    char C[sizeof(long) / sizeof(char)];
} word_union;

int main()
{
    /* Dichiarazione delle variabili */
    short menu;                     /* Scelta menu */
    short bit_array[MAX_LEN];       /* Array dei bit */
    short len_byte;                 /* Lunghezza dei byte */

    word_union word;

    do{
        /* Scelta dell'opzione da eseguire */
        puts("Selezione");
        puts("[0] Uscita dal programma!");
        puts("[1] Rappresentazione binaria di intero char!");
        puts("[2] Rappresentazione binaria di intero short!");
        puts("[3] Rappresentazione binaria di intero long!");

        fflush(stdin);
        scanf("%hd", &menu);

        /* Sviluppo della scelta */
        switch (menu)
        {
        case 0:
            exit(0);

        case 1:
            len_byte = sizeof(char);
            /* Inserimento dell'intero carattere */
            printf("Immettere intero char C: ");
            fflush(stdin);
            scanf("%d", word.C[0]);

            puts("Char in decimale, esadecimale e binario:");
            printf("C= %+10hd,    hex=%02x,", word.C[0], word.C[0]);

            populate_bit(sizeof(char), word.C, bit_array);
            break;

        case 2:
            len_byte = sizeof(short);
            /* Inserimento dell'intero short */
            printf("Immettere intero short S: ");
            fflush(stdin);
            scanf("%hd", word.S[0]);

            puts("Short in decimale, esadecimale e binario:");
            printf("S= %+10hd,    hex=%02x,", word.S[0], word.S[0]);

            populate_bit(sizeof(short), word.C, bit_array);

            break;

        case 3:
            len_byte = sizeof(long);
            /* Inserimento dell'intero long */
            printf("Immettere intero long L: ");
            fflush(stdin);
            scanf("%ld", word.L);

            puts("Long in decimale, esadecimale e binario:");
            printf("L= %+10hd,    hex=%02x,", word.L, word.L);

            populate_bit(sizeof(long), word.C, bit_array);

            break;
        }

        /* Stampa dell' array dei bit */
        print_array(len_byte, bit_array);

    }while(menu != 0);
    return 0;
}

void zero_array(short bit_array[MAX_LEN])
{
    int i;
    /* Riempimento della matrice dei bit con tutti 0 */
    for(i = 0; i < MAX_LEN; i++)
    {
        bit_array[i] = 0;
    }
}

void populate_bit(short len_byte, char array_characters[], short bit_array[MAX_LEN])
{
    int i,j;
    zero_array(bit_array);

    for(i = 0; i < len_byte; i++)
    {
        /* Estrazione del valore temporaneo */
        char temp_character = array_characters[i];

        /* P.S. per lo svolgimento guardare la foto nella cartella */
        for(j = 0; j < sizeof(char) * 8; j++)
        {
            /* Riempimento dell'array dalla posizione 0 con il bit meno significativo */
            bit_array[(i * 8) + j] = temp_character & 1;

            /* Shift a dx della variabile in considerazione */
            temp_character >> 1; 
        }
    }
}

void print_array(short len_bit, short bit_array[MAX_LEN]){
    int i;

    for (i = (len_bit * 8) - 1; i >= 0; i--)
    {
        (i%4 == 0) ? printf("%1hd ", bit_array[i]) : printf("%1hd", bit_array[i]);
    }
}