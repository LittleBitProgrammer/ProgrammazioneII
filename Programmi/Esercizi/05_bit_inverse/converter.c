/**
 * @file converter.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Implementazione della libreria converter.h
 * @version 1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "converter.h"

/* Definizione funzioni */

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
            temp_character >>= 1; 
        }
    }
}

void print_bit(short len_bit, short bit_array[MAX_LEN]){
    int i;

    for (i = (len_bit * 8) - 1; i >= 0; i--)
    {
        printf("%hd%s", bit_array[i], (i % 4 == 0) ? " " : "");
    }
}

void print_dec_number(short len_byte, short bit_array[])
{
    int i;
    int decimal_number = 0;

    for(i = 0; i < (len_byte * 8); i++)
    {
        decimal_number += (bit_array[i] * (1 << i)); 
    }

    printf("\nDecimale: %d\n", decimal_number);
}

void inverse_array(short len_byte, short bit_array[])
{
    int i;
    short size = (len_byte * 8);

    for(i = 0; i <= (size / 2) - 1; i++)
    {
        swap_xor(bit_array + i, (bit_array + size - 1) - i);
    }
}

void swap_xor(short *a, short *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
