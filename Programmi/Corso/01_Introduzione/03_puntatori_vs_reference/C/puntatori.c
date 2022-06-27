/**
 * @file puntatori.c
 * @author Roberto Vecchio
 * @brief Tale programma ha lo scopo di mostrare un esempio di passaggio per riferimento a funzione
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "swap.h"

int main()
{
    /* Dichiarazione variabili */
    int a = 2, b = 3;

    /* Stampa prima dello swap */
    printf("\nPrima dello scambio: a = %d, b = %d\n", a, b);

    /* Scambio delle variabili */
    swap(&a, &b);

    /* Stampa dopo lo swap */
    printf("Dopo lo scambio: a = %d, b = %d\n", a, b);

    /* Denota la corretta terminazione del programma */
    return 0;
}