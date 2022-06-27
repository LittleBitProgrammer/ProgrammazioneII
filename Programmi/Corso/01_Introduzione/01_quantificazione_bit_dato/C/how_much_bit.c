/**
 * @file how_much_bit.c
 * @author Roberto Vecchio
 * @brief Tale programma ha lo scopo di quantificare lo spazio occupato da un determinato tipo di dato in memoria
 * @version 1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main()
{
    /* Stampa del numero di byte (8 bit) per ogni dato */
    printf("\nsizeof(char)          = %d\n", sizeof(char));
    printf("sizeof(short)         = %d\n", sizeof(short));
    printf("sizeof(int)           = %d\n", sizeof(int));
    printf("sizeof(long int)      = %d\n", sizeof(long int));
    printf("sizeof(long long int) = %d\n", sizeof(long long));
    printf("sizeof(float)         = %d\n", sizeof(float));
    printf("sizeof(double)        = %d\n", sizeof(double));
    printf("sizeof(long double)   = %d\n", sizeof(long double));
    printf("sizeof(char *)        = %d\n", sizeof(char *));

    /* Denota la corretta terminazione del programma */
    return 0;
}