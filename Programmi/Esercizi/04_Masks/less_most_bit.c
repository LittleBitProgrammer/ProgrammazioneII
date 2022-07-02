/**
 * @file less_most_bit.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Scrivere una function C per estrarre dalla variabile intera X i k bit più significativi o meno significativi,
 *        dove X e k sono i parametri di input, usando:
 *        1)Una maschera;
 *        2)L’operatore di shift (>> o <<);
 *        3)Il prodotto o la divisione per potenza 2.
 * 
 * @version 1
 * @date 2022-07-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "mask.h"
#include "bit.h"

int main()
{
    /* Dichiarazione variabili */
    menu my_menu;
    int variable;
    short n_bit;

    /* Input intero */
    printf("Inserire un valore intero: ");
    scanf("%d", &variable);

    /* Input k */
    printf("Inserire quanti bit si vuole mascherare [k <0 MSB] - [k > 0 LSB]: ");
    scanf("%hd", &n_bit);

    /* Menu */
    puts("Scegliere una delle seguenti opzioni:");
    puts("1 - Maschera for");
    puts("2 - Maschera shift");
    puts("3 - Maschera pow");

    /* Input menu */
    scanf("%d", &my_menu);

    /* Stampa prima della maschera */
    puts("Valore prima della maschera:");
    printbit(variable);

    /* Caso 0 */
    if (n_bit == 0)
    {
        puts("Variabile Mascherata:");
        printbit(variable);

        return 0;
    }

    /* Estrazione LSB o MSB */
    variable = extract_bit(variable, n_bit, my_menu - 1);

    /* Stampa valore mascherato */
    puts("Variabile Mascherata:");
    printbit(variable);
    
    return 0;
}