#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>
#define MAX_LEN 32 /** Lunghezza Massima **/
typedef enum{vero,falso} Logico; /** Creazione tipo bollenano **/

union s_p{
    float fa;
    int la;
    char C[4];
}a; /** Union **/

void converti_float(int len, unsigned char bit[MAX_LEN]); /** Procedura per la conversione da BASE 10 a BASE 2 **/
float parte_Intera(char *input);
float parte_Reale(char *input);

int main()
{
    char input[1000], T[]={"."},*p;
    short j=0,i=0;
    Logico esito=falso;
    float numero=0.0;
    unsigned char bit[MAX_LEN];
    while(esito==1)
    {
        system("cls");
        printf("Inserisci numero reale;\nEsempio \"-12.35\" -> ");
        fflush(stdin); gets(input);
        /// MI RICAVO IL SEGNO DEL NUMERO
        if(input[0]=='-' || input[0]=='+')
            j++;

        while(isdigit(input[j])!=0 || input[j]=='.')
            j++;

        if(j==strlen(input))
            esito=vero;
        else{
            printf("INPUT ERROR!\a");
        }
        j=0;
    }
    /// DIVIDO IN DUE PARTI, LA STRINGA IMMESSA COME INPUT; COSì CHE POSSA CALCOLARE LA PARTE INTERA E QUELLA REALE.
    p=strtok(input,T);
    /// CHIAMATA ALLA FUNZIONE PER IL CALCOLO DELLA PARTE INTERA DEL NUMERO. LA PRIMA PARTE DELLA STRINGA PRECEDENTEMENTE DIVISA.
    numero=parte_Intera(p);
    /// CHIAMATA ALLA FUNZIONE PER IL CALCOLO DELLA PARTE REALE DEL NUMERO. LA RESTANTE PARTE DI STRINGA.
    while((p=strtok(NULL,T))!=NULL)
        numero=numero+parte_Reale(p);
    /// CONTROLLANDO IL PRIMO BIT DELLA STRINGA IMMESSA IN INPUT CONTROLLO IL SEGNO DEL NUMERO
    if(input[0]=='-')
    {
        numero=numero*-1;
        printf("Segno: (-)\t\tNumero: %.3f",numero);
    }
    else
        printf("Segno: (+)\t\tNumero: %.3f",numero);
    /// ORA CONVERTO IL NUMERO IN BINARIO E LO VISUALIZZO
    a.fa=numero;
    converti_float(a.la,bit);
    printf("\nBinario:\ts\te\t\tm\n");
    printf("        \t%1d\t",bit[0]);
    for(i=1;i<9;i++)
        printf("%1d",bit[i]);
    printf("\t");
    for(i=9;i<32;i++)
        printf("%1d",bit[i]);
    return 0;
}

/// FUNZIONE PER LA CONVERSIONE DI UN NUMERO FLOAT DA BASE 10 A BASE 2.
void converti_float(int len, unsigned char bit[MAX_LEN]) /** Scorro le posizione dell'array contenente i bit e lo inizializzo con la variabile len **/
{
    short i;
    /// SCORRO TUTTE LE POSIZIONE DELL'ARRAY CONTENENTE I BIT, E LO INIZIALIZZO CON I BIT DELLA VARIABILE "len".
    for(i=31;i>=0;i--)
    {
        bit[i]=(char)(1&len);
        len=len>>1;
    }
}

float parte_Intera(char *input)
{
    short j=0,i=strlen(input)-1,cifre_i[strlen(input)],len=0;
    int numero=0;
    while(i>0)
    {
        cifre_i[len++]=input[i]-48; /** Converto il char in intero **/
        i--;

    }

   /**Calcolo della parte intera immessa **/
    for(j=0;j<len;j++)
        numero=numero+cifre_i[j]*pow(10,j);
        printf("%hd\n",numero);
    return (float)numero;
}

float parte_Reale(char *input)
{
    short j=0,cifre_r[strlen(input)],len=0;
    float numero=0.0;
    while(j<strlen(input))
    {
        cifre_r[len++]=input[j]-48; /// CONVERTO I CARATTERI IN CIFRE E LI MEMORIZZO NELL'ARRAY.
        j--;
    }
    /// FORMULA PER IL CALCOLO DELLA PARTE REALE DEL NUMERO IMMESSO.
    for(j=0;j<len;j++)
        numero=numero+cifre_r[j]/pow(10,j+1);

    return numero;
}

