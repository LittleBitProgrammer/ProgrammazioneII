/**
 * @file occorrenze_ita.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Calcolo del numero delle occorrenze del pattern "ita" con 
 *        l' utilizzo delle funzion per le stringhe
 * @version 1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* Pattern da trovare*/
    char *patt = "ita";

    /* te -> Puntatore all' indirizzo base del testo */
    /* ch -> Puntatore all'occorrenza */
    char *te, *ch;                      

    /* Lunghezze del testo e del pattern */     
    int len_t, len_p;
    /* Volte in cui il pattern è stato trovato */ 
    short num_trovati;
    char *testo = "Nel mezzo del cammin di nostra vita\n"
                  "mi ritrovai per una selva oscura\n"
                  "ché la diritta via era smarrita.\n";

    len_t = strlen(testo);
    len_p = strlen(patt);

    num_trovati = 0;
    te = testo;

    do
    {
        ch = strstr(te, patt);

        if (ch != NULL){
            num_trovati++;
            te = ch + len_p;
        }
    } while (te < (testo + len_t) && ch != 0);

    printf("numtrovati = %d\n", num_trovati);
    
    return 0;
}