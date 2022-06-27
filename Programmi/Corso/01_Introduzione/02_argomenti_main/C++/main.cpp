/**
 * @file main.cpp
 * @author Roberto Vecchio 
 * @brief Il programma ha lo scopo di mostrare un esempio di utilizzo dei parametri del main:
 *        - argc
 *        -argv[]
 *
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

/* iostream */
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    /* Stampa del primo argomento, inserito dopo il comando di esecuzione del programma */
    cout << endl << "Ciao, " << argv[1] << "!" << endl;

    /* Denota la corretta terminazione del programma */
    return 0;
}