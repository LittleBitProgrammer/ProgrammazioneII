/**
 * @file low_up.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Scrivere una function C:
 *        char low_up(char ch) che cambia il carattere in input da minuscolo
 *        a maiuscolo e viceversa automaticamente
 * @version 1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "up_down.h"

int main()
{
    /* Dichiarazione variabili */
    char character;

    /* Input */
    printf("\nInserire nuovo carattere: ");
    scanf("%c", &character);

    /* Maiuscolo a minuscolo e viceversa */
    character = updown(character);

    /* Stampa del nuovo carattere */
    printf("\nNuovo carattere: %c", character);

    return 0;
}