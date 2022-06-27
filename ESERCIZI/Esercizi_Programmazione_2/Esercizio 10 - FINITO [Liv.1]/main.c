//[liv.1] Scrivere una function C che, fissato il numero n di bit, calcoli la rappresentazione di un intero:
//• per complemento a 2;
//• eccesso B (B-biased).
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
typedef enum {false, true} bool; /** Creazione del tipo BOOLEANO **/

void function (int, int); /** Function per il complemento a 2 **/
void function2 (int, int); /** Function per l'eccesso B-biased **/
void visualizza (char [], int); /** Function per la stampa a video dell'array **/
void inizializza (char []); /** Function per l'inizzializzazione dell'array **/
int main ()
{
    int n,x;
    printf("INIZIO DEL PROGRAMMA\n");
    while(n<0 || n>32)
    {
        printf("Inserisci un INTERO per fissare il numero di BIT\n>>");
        scanf("%d", &n); /** INPUT numero di BIT **/
    }
    printf("Inserisci il numero da trasformare\n>>");
    scanf("%d",&x); /** INPUT numero da trasformare **/
    function(n, x);
    function2(n, x);
return 0;
}
void function (int n, int x)
 {
    bool segno = false; /** FALSE = POSITIVO **/
    char bit[10];
    int i=0;
    inizializza(bit); /** MEMORIZZO IL SEGNO **/
    if(x<0)
    {
        segno=true;
        x=-x;
    }

    while(x>0)
    {
        bit[i] =(x%2)+48; /** ORA NEL POSTO CORRISPONDENTE E' MEMORIZATO IL CARATTERE '0' OPPURE '1' **/
        x=x/2;
        i++;
    }
    bit[i]='\0'; /** Aggiungo il terminatore per farlo diventare una stringa **/

    while(segno==true) /** SE IL SEGNO E' NEGATIVO VADO A COMPLEMENTARE **/
    {
        i=0;
        do{
            i++;
        }while(bit[i-1]!='1' && bit[i]!='\0');
        i++;
        while(bit[i]!='\0')
        {
            if(bit[i]=='1')
                bit[i]='0';
            else
                bit[i]='1';
            i++;
        }
    }

    printf("Utilizzando il COMPLEMENTO A DUE\n-->");
    visualizza(bit,n);
}
void visualizza (char arr[], int n) /** OUTPUT array di BIT **/
 {
    int i=0;
    for (i=n-1;i>=0;i--)
        printf("%c",arr[i]);
    printf("\n");
}
void inizializza(char bit[]) /** Creazione dell'array di CHAR **/
{
    int i;
    for(i=0;i<10;i++)
        bit[i]='0';
}
void function2(int n, int x)
{
    char bit [10];
    int i=0;
    inizializza(bit);
    x=x+pow(2,(n-1))-1;
    while(x>0)
    {
        bit[i]=(x%2)+48; /** ORA NEL POSTO CORRISPONDENTE E' MEMORIZATO IL CARATTERE '0' OPPURE '1' **/
        x=x/2;
        i++;
    }
    bit[i] = '\0';    /** Aggiungiamo il terminatore di stringa **/
    printf ("Utilizzando il BIASED\n-->");
    visualizza(bit,n);
}
