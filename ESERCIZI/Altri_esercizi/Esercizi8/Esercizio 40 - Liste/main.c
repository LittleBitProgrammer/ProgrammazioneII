/*Simulare in C l’algoritmo di visita di una lista lineare già memorizzata mediante un array statico di
struct (come nella tabella in basso) in cui il primo campo contiene l’informazione ed il secondo contiene il
link al nodo successivo (in questo caso il link è l’indice di una componente dell’array). Memorizzando
nell’array i dati come mostrato nella figura che segue, l’output del programma consiste nell’elenco di nomi
ordinato alfabeticamente. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persone
{
    char nome[12];
    short link_succ;
};

struct persone utente[11]={ {"anna", 5}, {"mario", 8}, {"giuseppe", 6}, {"angela", 0},
                                            {"valeria", -1}, {"fabrizio", 7}, {"marianna", 2}, {"giovanni", 1},
                                            {"patrizia", 10}, {"valentina", 4}, {"sara", 9} };;

int main()
{
    short i=0;
    short testa=3;

    do
    {
        printf("%s\n", utente[testa].nome);
        testa=utente[testa].link_succ;
    }while(testa!=-1);
}
