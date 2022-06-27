/* Scrivere una function C
char rotate(char ch, char n_bit)
per ruotare di n bit (n_bit), verso sinistra o verso destra (rispettivamente per n_bit<0 e per n_bit>0), il
contenuto di una variabile char mediante gli operatori bitwise. */

#include <stdio.h>
#include <stdlib.h>
char rotate_left(char ch, char n_bit);
char rotate_right(char ch, char n_bit);
int main()
{
    char c;
    unsigned short int n_bit;
    printf("Inserisci il carattere da shiftare: ");
    scanf("%c", &c);

    printf("Inserisci il numero di bit da shiftare: " );
    scanf("%hd", &n_bit);

    printf("\nSHIFT A SINISTRA: %c", rotate_left(c, n_bit));
    printf("\nSHIFT A DESTRA: %c", rotate_right(c, n_bit));

}

char rotate_left(char ch, char n_bit)
{
    char bit_s=ch>>(8-n_bit);
    ch=ch<<n_bit;
    ch=ch|bit_s;
    return ch;
}

char rotate_right(char ch, char n_bit)
{
    char bit_s=ch<<(8-n_bit);
    ch=ch>>n_bit;
    ch=ch|bit_s;
    return ch;
}
