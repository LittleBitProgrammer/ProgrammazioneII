/**
 * @file converter.h
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Definizione della libreria converter.h
 * @version 1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _CONVERTER_H_
#define _CONVERTER_H_

/* size massima della variabile, in base alla versione del compilatore */
#define MAX_LEN (sizeof(char *) * 8)

/* Unioni */
typedef union 
{
    long L;
    short S[sizeof(long) / sizeof(short)];
    char C[sizeof(long) / sizeof(char)];
} word_union;

/* Prototipi di funzione */
void populate_bit(short, char[], short[]);
void zero_array(short[]);
void print_bit(short, short[]);
void print_dec_number(short, short[]);
void inverse_array(short, short[]);
void swap_xor(short *, short *);

#endif