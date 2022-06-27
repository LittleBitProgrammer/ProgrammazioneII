//Scrivere una function C che, dopo aver estratto i bit da una variabile intera X (tipo char, short o
//int) visualizzi i bit e poi calcoli il valore corrispondente dalla formula:
//Val_X = bn−12n−1+ … + b222 + b121+ b020
//dove b è l’array dei bit di X: bj, per j=0, 1,…, n−1 dal meno significativo al più significativo, (dove n=8 per il
//tipo char, n=16 per il tipo short o n=32 per il tipo int). Confrontare il risultato con il valore immesso per
//la variabile intera X dichiarata una volta signed ed un’altra unsigned.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void bit_show(short , char [], short []); /** Function per stampare a video la variabile in binario **/
void contare_signed(short bit[], int len); /** Fuction che effettua il calcolo richiesto **/
int main()
{   int len, scelta, k;
    short bit[32]; /** Array di BIT che utilizziamo per effettuare il calcolo **/
    union word32bit{
            float F;
            int I;
            short S[2];
            char C[4];}word; /** Costrutto UNION **/
    printf("\nScegliere che tipo di DATO analizzare:");
    printf("\nInserire [1] per INT ");
    printf("\nInserire [2] per SHORT ");
    printf("\nInserire [3] per CHAR : ");
    scanf("%d", &scelta);
    switch(scelta){ /** Scelta del tipo della variabile **/
    case 1:
        len=sizeof(int); /** Lunghezza in byte del tipo INT **/
        printf("\nImmetterte tipo di dato INT: ");
        scanf("%d",&word.I); /** Accesso ad un campo dell'UNION (INT I) **/
        bit_show(sizeof(int), word.C, bit);/** Creazione dell'array di BIT **/
        contare_signed(bit,len); break; /** Richiamo alla Function **/
    case 2: /** CASO 2 **/
        len=sizeof(short); /** Lunghezza in byte del tipo SHORT **/
        printf("\nImmettere tipo di dato SHORT: ");
        scanf("%hd",&word.S[0]); /** Accesso ad un campo dell'UNION (SHORT S[]) **/
        bit_show(sizeof(short), word.C,bit);/** Creazione dell'array di BIT **/
        contare_signed(bit,len); break;/** Richiamo alla Function **/
    case 3: /** CASO 3 **/
        len=sizeof(char); /** Lunghezza in byte del tipo CHAR **/
        printf("\nImmettere tipo di dato CHAR: ");
        fflush(stdin);/** Pulizia del buffer **/
        scanf("%c", &word.C[0]); /** Accesso ad un campo dell'UNION (CHAR C[]) **/
        bit_show(sizeof(char), word.C,bit); /** Creazione dell'array di BIT **/
        contare_signed(bit,len); break;/** Richiamo alla Function **/
    default:exit(0);break; /** EXIT in caso in cui la scelta immessa non esiste **/
        }
    printf("\n");
    printf("\nBINARIO: ");
    for(k=8*len-1;k>=0;k--) /** Stampa in binario del dato in INPUT **/
         (k%4==0) ? printf("%1d", bit[k]): printf("%1d", bit[k]);
return 0;
}

void bit_show(short len, char ch[], short bit[32]) /** Procedura che crea l'array di BIT **/
{
    short j, jc;
    char c;
    for(j=0;j<32;j++)
        bit[j]=0;
    for(jc=0;jc<len;jc++)
    {
        c=ch[jc];
        for(j=0;j<8;j++)
        {
            bit[j+8*jc]=c&1;
            c=c>>1;
        }
    }
}

void contare_signed(short bit[], int len) /** Procedura che effettua il calcolo SIGNED e UNSIGNED **/
{
    int conta1=0, i=0;
    unsigned int conta2=0;
    for(i=len*8-1;i>=0;i--)
    {
        conta1=conta1+bit[i]*pow(2,i); /** Formula richiesta **/
        conta2=conta2+bit[i]*pow(2,i); /** Formula richiesta **/
    }
    printf("\nVARIABILE SIGNED: %d\nVARIABILE UNSIGNED: %u", conta1,conta2); /** Stampa delle variabili UNSIGNED e SIGNED **/
}
