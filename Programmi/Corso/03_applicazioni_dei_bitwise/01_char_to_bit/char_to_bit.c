/**
 * @file vhar_to_bit.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Algoritmo di conversione da char a bit
 * @version 1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main()
{
    /* Dichiarazione variabili */
    unsigned char bit[16][5] = 
    {
        "0000\0", "0001\0", "0010\0", "0011\0",
        "0100\0", "0101\0", "0110\0", "0111\0",
        "1000\0", "1001\0", "1010\0", "1011\0",
        "1100\0", "1101\0", "1110\0", "1111\0"
    };

    unsigned char character; /* Carattere di cui visualizzare i bit */
    unsigned char left, right; /* Most e less significant bit */

    /* Input */
    printf("Inserire il carattere di cui si vuole mostrarne i bit: ");
    scanf("%c", &character);

    /* Assegnazioni */
    left = character >> 4;
    right = (unsigned char)(character << 4) >> 4;

    /* Stampa */
    printf("char = %c\tint = %d\tesadecimale = %x\nbinario = %s %s, %d", character, character, character, bit[left], bit[right], 65 & 1);

    return 0;
}