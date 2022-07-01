/**
 * @file logico.c
 * @author Roberto Vecchio
 * @brief Il programma ha lo scopo di mostrare come funziona il tipo logico in un programma C
 * @version 0.1
 * @date 2022-06-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main()
{
    /* Dichiarazione variabili */
    float F = 1.5f;
    short A, B, C, D;
    short notA, notB, notC, notD, notF;

    /* Inizializzazione */
    A = 5 == 5; /* true */
    B = 5 == 6; /* false */
    C = 8;
    D = -7;
    
    /* Stampa prima della negazione */
    printf("\nA = %hd\tB = %hd\tC = %hd\tD = %hd\tF = %f\n", A, B, C, D, F);

    /* Negazione */
    notA = !A;
    notB = !B;
    notC = !C;
    notD = !D;
    notF = !F;

    /* Stampa dopo la negazione */
    printf("\nnotA = %hd\tnotB = %hd\tnotC = %hd\tnotD = %hd\tnotF = %hd\n", notA, notB, notC, notD, notF);

    /* Denota la corretta terminazione del programma */
    return 0;
}