/**
 * @file mask.h
 * @author Roberto Vecchio  & Francesco Mabilia
 * @brief Definizione della libreria mask.h
 * @version 1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _MASK_H_
#define _MASK_H_

typedef enum {mask_bit, shift_bit, pow_bits} menu;

/* Dichiarazione delle funzioni */
int extract_bit(int, short, menu);
int mask(short);
int shift(short);
int pow_bit(short);

#endif 