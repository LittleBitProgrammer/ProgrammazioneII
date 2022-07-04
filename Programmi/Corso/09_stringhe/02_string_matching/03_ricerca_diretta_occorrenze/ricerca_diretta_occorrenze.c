/**
 * @file occorrenze_ita.c
 * @author Roberto Vecchio & Francesco Mabilia
 * @brief Calcolo del numero delle occorrenze del pattern "ita" con 
 *        l' utilizzo della ricerca diretta
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
    /**
     * it -> indice di scorrimento del testo
     * ip -> indice di scorrimento del pattern
     * uguali -> contatore per il conteggio delle lettere successive tra pattern e testo
     * itt -> variabile temporanea di scorrimento del testo
    */
    short it, ip, uguali, itt;  

    /* patt -> pattern che bisogna trovare nel testo */
    char *patt = "ita";

    /**
     * len_t -> lunghezza testo
     * len_p -> lunghezza pattern
    */
    int len_t, len_p;

    /* num_trovati -> variabile contatore per le volte che troviamo il pattern nel testo */
    short num_trovati;
    char *testo = "Nel mezzo del cammin di nostra vita\n"
                  "mi ritrovai per una selva oscura\n"
                  "ché la diritta via era smarrita.\n";

    len_t = strlen(testo);
    len_p = strlen(patt);
    num_trovati = 0;
    it = ip = 0;

    while (it < len_t){
        if (testo[it] == patt[ip]){
            uguali = 1;
            itt = it + 1;
            ip++;

            while ((itt < len_t) && (ip < len_p) && uguali){
                if (testo[itt] == patt[ip]){
                    uguali++;
                }else{
                    uguali = 0;
                }
                itt++;
                ip++;
            }
            
            if (uguali == len_p){
                num_trovati++;
            }
        }
        ip = 0;
        it++;
    }
    
    printf("numtrovati = %d\n", num_trovati);
    return 0;
}