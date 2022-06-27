#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// Il programma funziona perchè l'array stringa è inizializzato nel modo giusto

void main()
{
    char stringa[]="ciao";
    printf("INIZIO PROGRAMMA \n");
    puts(stringa);
    (*stringa)='m';
    puts(stringa);
}
/** LA MODIFICA APPORTATA ALL'ARRAY E' ERRATA
void main()
{
    char *stringa="ciao";
    puts(stringa);
    *stringa='m';
    puts(stringa);
}
**/
