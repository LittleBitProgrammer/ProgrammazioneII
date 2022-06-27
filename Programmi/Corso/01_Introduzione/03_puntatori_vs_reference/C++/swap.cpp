/**
 * @file swap.c
 * @author Roberto Vecchio
 * @brief Definizione dell'algoritmo di swap
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "swap.hpp"

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}