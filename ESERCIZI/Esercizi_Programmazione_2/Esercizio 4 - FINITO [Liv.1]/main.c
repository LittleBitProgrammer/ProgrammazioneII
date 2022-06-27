#include <stdio.h>
#include <stdlib.h>

void estrai(short x, short y); /** Procedura utlizzata per l'estrazione dei BIT **/
void visualizza(short x, unsigned char bit[16]); /** Procedura utilizzata per la stampa dei BIT **/
int main()
{
	short x,k;
	k=0;
	printf("inserisci un intero di tipo SHORT\n");
	printf(">>");
	scanf("%hd",&x); /** Input dato **/
	while(k<=0 || k>=16)
	{
		printf("\nQuanti bit vuoi estrarre?? (MAX 16)\n");
		printf(">>");
		scanf("%hd",&k); /** Inserimento del quantitativo di BIT da estrarre **/
	}
	estrai(x,k); /** Richiamo della procedura **/
	return 0;
}


void estrai(short x, short k) /** Procedura estrazione dei bit **/
{
	unsigned char bit[16]; /** Array che utlilizziamo per stampare i BIT **/
	short mask=0, i=0, ris=0, z=0;
	int scelta;
	while(scelta<=0 || scelta>2)
	{
		printf("\nDECIMALE => %d", x); /** Stampa in DECIMALe del valore in INPUT **/
		printf("\nBINARIO => "); /** Stampa in BINARIO del valore in INPUT **/
		visualizza(x,bit); /** Procedura per la stampa dei BIT **/
		for(z=0;z<16;z++)
			(z%4==0) ? printf("%1d", bit[z]): printf("%1d", bit[z]); /** Ogni 4 bit c'è lo spazio tra i bit **/
		printf("\nChe tipo di BIT vuoi estrarre?\n[1] - SIGNIFICATIVI\n[2] + SIGNIFICATIVI\n");
		printf(">>");
		scanf("%d",&scelta); /** Input per la scelta dello SWITCH/CASE **/
	}
	switch(scelta)
	{
		case 1: /** ESTRAZIONE BIT MENO SIGNIFICATIVI **/
			for(i=1;i<=k;i++) /** For per l'aggiunta di 1 in base alla quantità di bit da estrarre **/
                mask=mask<<1|1;
			ris=x&mask; /** AND stra il valore in INPUT 'x' e la maschera 'mask' creata in base a quanti bit estrarre **/
			visualizza(ris,bit); /** Creazione array di bit per la stampa dei bit estratti **/
			printf("\nBIT ESTRATTI: ");
			for(i=16-k;i<=15;i++)
				(i%4==0) ? printf("%1u", bit[i]):printf("%1u", bit[i]); break;
		case 2: /** ESTRAZIONE DEI BIT PIU' SIGNIFICATIVI **/
			for(i=1;i<=k;i++) /** For per l'aggiunta di 1 in base alla quantità di bit da estrarre **/
                mask=mask<<1|1;
            mask=mask<<(16-k); /** SHIFT dei BIT fino a farli arrivare all'indice finale della quantità di BIt da estrarre **/
            ris=x&mask; /** AND tra il valore in INPUT 'x' e la maschera 'mask' creata in base a quanti bit estrarre **/
			visualizza(ris,bit);/** Creazione array di bit per la stampa dei bit estratti **/
			printf("\nBIT ESTRATTI: ");
			for(i=0;i<k;i++)
				(i%4==0) ? printf("%1u", bit[i]):printf("%1u", bit[i]); break;
	}
}

void visualizza(short y, unsigned char bit[16]) /** Procedura per la creazione dell'array dei BIT **/
{
	int j=15; /** 16-1 **/
	do{
		bit[j--]=y & 1;
		y=y>>1;
	 }while(y!=0 && j>=0);
	if(j>=0)
	{
		do{
			bit[j--]=0;
		 }while(j>=0);
	}
}
