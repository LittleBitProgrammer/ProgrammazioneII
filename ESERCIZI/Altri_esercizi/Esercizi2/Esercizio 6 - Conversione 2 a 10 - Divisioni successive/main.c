/*Scrivere una function C di conversione di un intero positivo da base 2 a base 10, mediante l’algoritmo
delle divisioni successive, che generi un array di caratteri contenenti le cifre decimali.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
unsigned short bit[8]={0};
unsigned char array_cifre[8]={0};
void main()
{
    unsigned int val;
    printf("Inserisci il valore che vuoi riconvertire: ");
    scanf("%d", &val);

    bit_extract(val);

    printf("Valore in binario:\n");
    for(short i=7; i>=0; i--)
    {
        printf("%u", bit[i]);
    }

    printf("\nArray di char: \n");
    for(short i=7; i>=0; i--)
    {
        printf("%u", array_cifre[i]);
    }
}

void bit_extract(unsigned int x)
{
    short i=0, numero=0, pow_2=0, pow_10=0, cifre=1;
    do
    {
        bit[i++]=x%10;
        x/=10;
        cifre++;
    }while(x!=0);//RICAVO I SINGOLI BIT DALL'INTERO IN BASE 2

        cifre/=2;//CAPISCO QUANTE CIFRE HA IL MIO NUMERO INTERO IN BASE 10

    for(i=0; i<8; i++)//CALCOLO IL MIO NUMERO IN DECIMALE
    {
        pow_2=pow(2,i);
        numero=numero+(bit[i]*pow_2);
    }

    for(i=cifre-1; i>=0; i--)//MEMORIZZO LE CIFRE NELLE CELLE DELL'ARRAY DI CHAR
    {
        pow_10=pow(10,i);
        array_cifre[i]=numero/pow_10;
        numero=numero%pow_10;
    }
}
