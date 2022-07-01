/**
 * @file up_down.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Implementazione della libreria up_down.h
 * @version 1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "up_down.h"

char updown(char character)
{
    return character ^ MASK;
}