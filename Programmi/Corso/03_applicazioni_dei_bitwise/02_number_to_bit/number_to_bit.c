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

typedef union 
{
    long L;
    float F;
    short S[sizeof(long) / sizeof(short)];
    char C[sizeof(long) / sizeof(char)];
} word_union;

int main()
{
    short menu;
    short bit_array[MAX_LEN];
    short len_byte;

    word_union word;

    return 0;
}

void zero_array(short bit_array[MAX_LEN])
{
    int i;
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
        char temp_character = array_characters[i];

        for(j = 0; j < sizeof(char) * 8; j++)
        {
            bit_array[(i * 8) + j] = temp_character & 1;
            temp_character >> 1; 
        }
    }
}
