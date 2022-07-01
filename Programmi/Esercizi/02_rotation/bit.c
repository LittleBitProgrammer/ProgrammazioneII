/**
 * @file bit.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Implementazione della libreria bit.h
 * @version 1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "bit.h"

void printbit(char character)
{
    int i;
    for(i = (sizeof(character) * 8) -1; i >= 0; i--)
    {
        printf("%hd", (character >> i) & 1);
        if(i % 4 == 0 && i != 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

char rotate(char character, short n_bit)
{
    /* Stampa del carattere prima della rotazione */
    puts("Carattere prima della rotazione in binario:");
    printbit(character);

    /* Rotazione */
    if(n_bit >= 0)
    {
        /* Rotazione a destra */

        /* Ricaviamo i bit che andranno persi durante la prima fase della rotazione */
        char right = character << (sizeof(character) * 8 - n_bit);

        /* Stampa dei bit ottenuti */
        puts("Lato destro in binario:");
        printbit(right);

        /* Ricaviamo i bit che ruoteranno a destra */
        char left = character >> n_bit;

        /* Stampa dei bit ottenuti */
        puts("Lato sinistro in binario:");
        printbit(left);

        /* Calcoliamo la variabile ruotata */
        character = left | right;

        /* Stampiamo la variabile ruotata */
        puts("Carattere ruotato in binario:");
        printbit(character);
    }
    else
    {
        /* Rotazione a sinistra */

        /* Ricaviamo i bit che andranno persi durante la prima fase della rotazione */
        char left = character >> (sizeof(character) * 8 - abs(n_bit));

        /* Stampa dei bit ottenuti */
        puts("Lato sinistro in binario:");
        printbit(left);

        /* Ricaviamo i bit che ruoteranno a sinistra */
        char right = character << abs(n_bit);

        /* Stampa dei bit ottenuti */
        puts("Lato destro in binario:");
        printbit(right);

        /* Calcoliamo la variabile ruotata */
        character = left | right;

        /* Stampiamo la variabile ruotata */
        puts("Carattere ruotato in binario:");
        printbit(character);
    }
    return character;
}