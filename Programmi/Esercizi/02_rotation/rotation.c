/**
 * @file rotation.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Scrivere una function C:
 *        char rotate(char ch, char n_bit) 
 *        per ruotare di n bit (n_bit), verso sinistra o verso destra (rispettivamente per n_bit<0 e per n_bit>0), il
 *        contenuto di una variabile char mediante gli operatori bitwise
 * @version 1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "bit.h"

int main()
{
    /* Dichiarazione variabili */
    char character;
    short n_bit;

    /* Input carattere */
    printf("Inserire un carattere: ");
    scanf("%c", &character);

    /* Input bit */
    printf("Inserire il numero di bit da ruotare [-8,0] o [0,8]: ");
    scanf("%hd", &n_bit);

    /* Rotazione del carattere */
    character = rotate(character, n_bit);

    /* Stampa del carattere ottenuto */
    printf("\nCarattere ruotato: %c\n", character);

    return 0;
}