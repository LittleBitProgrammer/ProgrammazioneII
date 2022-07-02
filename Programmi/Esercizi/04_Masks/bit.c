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
#include "bit.h"

void printbit(int integer)
{
    int i;
    for(i = (sizeof(integer) * 8) -1; i >= 0; i--)
    {
        printf("%hd", (integer >> i) & 1);
        if(i % 4 == 0 && i != 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}