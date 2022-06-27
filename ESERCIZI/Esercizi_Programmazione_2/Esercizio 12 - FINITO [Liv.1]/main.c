
//ESERCIZIO 11 [LIV. 1]
//Scrivere una function C per visualizzare la rappresentazione binaria (s,e,m) di un numero float.
//Verificare che il valore del numero ottenuto coincida con il dato iniziale.
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

int Bin_Dec(char [], int , int); /** Function per convertire il valore dell'esponente **/
float Calc_Esp(char array[], int inizio, int fine); /** Function per calcolare la mantissa **/
void estrae_bit(long , char [32]); /** Function per l'estrazione dei bit **/


/** Per la rappresentazione del numero float in segno, esponente e mantissa ho utilizzato la
funzione estrae_bit illustrata nelle slide con la modifica del valore dell'array che rappresenta
il carattere ASCII corrispondente al valore 1 e 0, poi successivamente ricalcolo il valore del
segno, dell'esponente e della mantissa. Per l'esponente ho utilizzato una semplice conversione
di un intero binario in decimale sottraendo il relativo valore del bias, mentre per la mantissa,
poiche rappresenta un numero binario decimale ho utilizzato un'apposita funzione che invece di
utilizzare la funzione pow (non funziona con esponente negativo) utilizza il metodo della
divisione per 2 calcolando il giusto peso per ogni bit, alla fine gli viene sommato il valore
del bit nascosto. **/



int main()
{
	float mantissa, risultato;
	char bit[32];
	short i=0;
	int esponente;
	union basic_single{
                    float fa;
                    long la;
                        }a;
	printf("Inserire un numero float\n>>");
	scanf("%f",&a.fa); /** INPUT FLOAT **/
	estrae_bit(a.la,bit); /** Stampa dei bit **/
	printf("\nFloat\n-->%e\n",a.fa);
	printf("\n\nBit Corrispondenti\tSegno\tEsponente\tMantissa\n-->");
    printf("\t\t\t%c\t", bit[0]); /** SEGNO **/
    for(i=1;i<=8;i++) /** ESPONENTE **/
        printf("%c", bit[i]);
    printf("\t");
    for(i=9;i<32;i++) /** MANTISSA **/
        printf("%c", bit[i]);
    printf("\n");
	if(bit[0]=='1') /** Analisi del segno **/
		printf("\t\t\t-");
	else
		printf("\t\t\t+");
    esponente=Bin_Dec(bit, 1, 8)-128; /** Eliminazione BIAS **/
	printf("\t%d\t",esponente);
    mantissa=Calc_Esp(bit, 9, 31); /** Analisi MANTISSA **/
    mantissa=(float)mantissa; /** CAST **/
	mantissa=mantissa+2; /** Aggiunta bit alla MANTISSA **/
	printf("\t%f",mantissa);
	if(bit[0]=='1')
        risultato=(mantissa*(float)pow(2,esponente))*-1;
	else
		risultato=mantissa*(float)pow(2,esponente);
	printf("\n\nIl risultato e': %f * 2^%d = %f\n\n\n",mantissa,esponente,risultato);
return 0;
}


void estrae_bit(long reg, char B[32])
{
	short i;
	for(i=31; i>=0;i--)
	{
		B[i]=(char)(1&reg)+48; /** Trasformazione da INT a CHAR **/
		reg=reg>>1; /** SHIFT a destra di 1 **/
	}
}


int Bin_Dec(char array[], int inizio, int fine)
{
	int i, numero=0, e=fine-inizio;
	for (i=inizio; i<=fine; i++)
	{
		if (array[i]=='1')
			numero=numero+(int)pow(2,e);
		e--;
	}
return numero;
}


float Calc_Esp(char array[], int inizio, int fine) /** Utilizzo questa function perchè la POW non si può utilizzare con esponente negativo **/
{
	int i;
	float numero=0.0f,peso=1.0f;
	for (i=inizio;i<=fine;i ++)
	{
		if(array[i]=='1')
			numero=numero+peso;
		peso=peso/2;
	}
return numero;
}

