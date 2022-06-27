/*Scrivere una function C di conversione di un numero reale da base 10 alla rappresentazione floatingpoint
IEEE Std 754. L’input è una stringa di char del tipo [±]X.Y dove X e Y rappresentano rispettivamente
la parte intera e la parte frazionaria del numero.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
float conv_string_to_float(char n[]);

int main()
{
    char numero[10];
    float num;

    printf("Inserisci il numero reale: ");
    gets(numero);

    num=conv_string_to_float(numero);

    printf("\nIl numero in float e'= %.3f\n", num);
}

float conv_string_to_float(char n[])
{
    char i=1, pow10=-1;
    float numero=0.F;


    while(n[i]!='.')
        numero=numero*10.F+(n[i++]-'0');

    i++;
    while(i<=strlen(n)-1)
    {
        numero=numero+pow(10.F, pow10)*(n[i++]-'0');
        pow10-=1;
    }

    if(n[0]=='-')
        numero*=-1.F;

    return numero;
}
