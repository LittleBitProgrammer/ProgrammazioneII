/**
 * @file main.c
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
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* Stampa del primo argomento, inserito dopo il comando di esecuzione del programma */
    printf("\nCiao, %s!\n", argv[1]);

    /* Denota la corretta terminazione del programma */
    return 0;
}