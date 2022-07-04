/**
 * @file occorrenza_ita.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Trovare la prima occorrenza del pattern "ita" e della lettera "i"
 * @version 1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>

int main(){
    /* Pattern da trovare nel testo */
    char *patt = "ita";

    /* Testo nel quale trovare il pattern*/
    char *testo = "Nel mezzo del cammin di nostra vita\n"
                  "mi ritrovai per una selva oscura\n"
                  "ché la diritta via era smarrita.\n";

    /* Puntatore all'occorrenza*/
    char *ch;
    short i, j;
    
    
    ch = strchr(testo, patt[0]);
    printf("strchr(testo, patt[0]) = %d\n", ch);

    if (ch != NULL){
        j = ch-testo;

        printf("&testo[j] = %d\n", &testo[j]);
        printf("ch = ");
        putchar(*ch);
        
        printf("coincide con *(testo+j) = ");
        putchar(*(testo + j));
    }

    ch = strstr(testo, patt);
    printf("\n\nstrchr(testo, patt) = %d\n", ch);

    if (ch != NULL){
        j = ch-testo;
        printf("&testo[j] = %d\n", &testo[j]);

        for ( i = 0; i < strlen(patt); i++){
            putchar(*(ch+i));
        }

        puts("coincide con ");
        for ( i = 0; i < j+strlen(patt); i++){
            putchar(*(testo+i));
        }
    }

    return 0;
}