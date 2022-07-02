/**
 * @file bin_to_integer.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Scrivere una function C per invertire l'ordine dei bit di una variabile intera A mediante operatori bitwise
 * 
 * @version 1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "converter.h"

int main()
{
    /* Dichiarazione delle variabili */
    short menu;                     /* Scelta menu */
    short bit_array[MAX_LEN];       /* Array dei bit */
    short len_byte;                 /* Lunghezza dei byte */

    word_union word;

    do{
        /* Scelta dell'opzione da eseguire */
        puts("\nSelezione");
        puts("[0] Uscita dal programma!");
        puts("[1] Rappresentazione binaria di intero char!");
        puts("[2] Rappresentazione binaria di intero short!");
        puts("[3] Rappresentazione binaria di intero long!");

        fflush(stdin);
        scanf("%hd", &menu);

        /* Sviluppo della scelta */
        switch (menu)
        {
        case 0:
            exit(0);

        case 1:
            len_byte = sizeof(char);
            /* Inserimento dell'intero carattere */
            printf("Immettere intero char C: ");
            fflush(stdin);
            scanf("%hd", &word.C[0]);

            puts("Char in decimale, esadecimale e binario:");
            printf("C= %+10hd,    hex=%02x,", word.C[0], word.C[0]);

            populate_bit(len_byte, word.C, bit_array);
            break;

        case 2:
            len_byte = sizeof(short);
            /* Inserimento dell'intero short */
            printf("Immettere intero short S: ");
            fflush(stdin);
            scanf("%hd", &word.S[0]);

            puts("Short in decimale, esadecimale e binario:");
            printf("S= %+10hd,    hex=%02x,", word.S[0], word.S[0]);

            populate_bit(len_byte, word.C, bit_array);

            break;

        case 3:
            len_byte = sizeof(long);
            /* Inserimento dell'intero long */
            printf("Immettere intero long L: ");
            fflush(stdin);
            scanf("%ld", &word.L);

            puts("Long in decimale, esadecimale e binario:");
            printf("L= %+10ld,    hex=%02x,", word.L, word.L);

            populate_bit(len_byte, word.C, bit_array);

            break;
        default:
            exit(1);
        }

        /* Stampa prima dell'inversione */
        puts("\nPrima dell inversione:");
        print_bit(len_byte, bit_array);

        /* Stampa del valore decimale dell'array di bit */
        puts("\nDecimale:");
        print_dec_number(len_byte, bit_array);

        /* Inversione */
        inverse_array(len_byte, bit_array);

        /* Dopo inversione array */
        puts("\nDopo inversione:");
        print_bit(len_byte, bit_array);

        /* Stampa del valore decimale dell'array di bit */
        puts("\nDecimale:");
        print_dec_number(len_byte, bit_array);

    }while(menu != 0);
    return 0;
}