/**
 * @file mask.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Implementazione della libreria mask.h
 * @version 0.1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bit.h"
#include "mask.h"

int extract_bit(int variable, short n_bit, menu choice)
{
    int my_mask;

    switch (choice)
    {
    case mask_bit:
        my_mask = mask(abs(n_bit));
        break;
    case shift_bit:
        my_mask = shift(abs(n_bit));
        break;
    case pow_bits:
        my_mask = pow_bit(abs(n_bit));
        break;
    default:
        exit(1);
    }

    puts("Maschera in binario: ");
    printbit(my_mask);

    return (n_bit > 0) ? (variable & my_mask) : (variable & (my_mask << ((sizeof(variable) * 8) - abs(n_bit))));
}

int mask(short n_bit)
{
    int i;
    int my_mask = 1;

    for ( i = 0; i < n_bit - 1; i++)
    {
        my_mask = (my_mask << 1) | 1;
    }
    
    return my_mask;
}

int shift(short n_bit)
{
    int my_mask = 1;
    return (my_mask << n_bit) -1;
}

int pow_bit(short n_bit)
{
    return ((int)(pow(2,n_bit)) - 1);
}