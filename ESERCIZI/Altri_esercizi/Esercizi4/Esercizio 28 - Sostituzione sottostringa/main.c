/*Utilizzando per le stringhe
o l’allocazione statica
o l’allocazione dinamica
scrivere una function C che sostituisca in un testo tutte le occorrenze di una data sottostringa S1 con un’altra S2
(le due sottostringhe possono avere anche lunghezze diverse). [liv.3]: … con il minimo numero di spostamenti
di blocchi di memoria. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char *testo, *patt_da_sos, *stringa;

    testo=(char *)malloc(18+1);
    printf("Inserisci il testo: "); fgets(testo, 18, stdin);
    fflush(stdin);

    patt_da_sos=(char *)malloc(2+1);
    printf("Pattern da sostituire: "); fgets(patt_da_sos, 3, stdin);
    fflush(stdin);

    stringa=(char *)malloc(3+1);
    printf("Sostituire con: "); fgets(stringa, 4, stdin);
    fflush(stdin);

    printf("Testo: %s\n>Pattern '%s' da sostituire con '%s'\n\n", testo, patt_da_sos, stringa);
    //ASSUMO LE STRINGHE DA TASTIERA

    sost(testo, patt_da_sos, stringa);

    puts(testo);
}

void sost(char *testo, char *patt, char *stringa)
{
    char *oc_found=strstr(testo, patt);
    char *occ[10];
    char len_t=strlen(testo), len_p=strlen(patt), len_s=strlen(stringa);

    char i=0;

    while(oc_found!=NULL)//CERCO TUTTE LE OCCORRENZE E LE SALVO IN UN ARRAY DI PUNTATORI
    {
        *(occ+i++)=oc_found;

        oc_found=strstr(oc_found+1, patt);
    }
    printf("Occorrenze trovate= %hd\n", i);

    if (len_s-len_p==0)
    {
        for (char j=0; j<i; j++)
        {
            printf("prova");
            strncpy(*(occ+j),stringa, len_s);
        }
    }
    else if(len_p<len_s)
    {

        realloc(testo, len_t+(len_s-len_p)*i);
        len_t+=(len_s-len_p)*i;
        i-=1;//PORTO I ALL'INDICE DELL'ULTIMO INDIRIZZO SALVATO NELL'ARRAY (PERCHE' LO INCREMENTO 1 IN PIU')

        char num_byte, cont=(len_s-len_p)*(i+1);
        char *dest, *src;

        for(char j=i; j>=0; j--)
        {
            dest=*(occ+j)+len_s+1;
            src=*(occ+j)+len_p;
            num_byte=len_t-((*occ+j)-testo)-cont-1;

            printf("\nnum_byte=%hd\n", num_byte);
            memmove(dest, src, num_byte);

            strncpy(*(occ+j), stringa, len_s);
            puts(testo);

            cont-=len_s-len_p;
        }
    }
}
