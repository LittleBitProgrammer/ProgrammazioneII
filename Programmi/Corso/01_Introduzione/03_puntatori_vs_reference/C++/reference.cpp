/**
 * @file puntatori.cpp
 * @author Roberto Vecchio
 * @brief Tale programma ha lo scopo di mostrare un esempio di passaggio per riferimento a funzione
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "swap.hpp"

/* iostream */
using std::cout;
using std::endl;

int main()
{
    /* Dichiarazione di variabili */
    int a = 2, b = 3;

    /* Stampa prima dello scambio */
    cout << endl << "Prima dello scambio: a = " << a << ", b = " << b << endl;

    /* Scambio delle variabili */
    swap(a, b);

    /* Stampa dopo lo scambio */
    cout << "Dopo lo scambio: a = " << a << ", b = " << b << endl;

    /* Denota la corretta terminazione del programma */
    return 0;
}