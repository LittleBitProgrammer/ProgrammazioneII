#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void all_statica(int n); /** Function per la creazione della stringa STATICA **/
void all_dinamica(int n); /** Function per la creazione della stringa DINAMICA **/
int main()
{
    int n; /** Dichiarazione del numero di caratteri della stringa **/
    printf("Inserire il numero di caratteri:\n>>");
    scanf("%d", &n); /** INPUT numero dei caratteri **/
    printf("\n\t--->ALLOCAZIONE STATICA<---\n");
    system("PAUSE");
    all_statica(n); /** Richiamo function per la creazione della Stringa STATICA **/
    printf("\n\t--->ALLOCAZIONE DINAMICA<---\n");
    system("PAUSE");
    all_dinamica(n); /** Richiamo function per la creazione della Stringa DINAMICA **/
return 0;
}

void all_statica(int n)
{
    char parola_s[50]; /** Dichiarazione della stringa **/
    int i=0, j=0;
    printf("\nINSERIRE LA STRINGA CARATTERE X CARATTERE\n");
    for(i=0;i<n;i++) /** Ciclo FOR per inserire i caratteri **/
    {
        printf("Inserire carattere %d:\n>>",i+1);
        fflush(stdin);
        parola_s[i]=getchar(); /** prendo l'INPUT con il getchar **/
        j++; /** Contatore per inserire il carattere di fine stringa **/
    }
    parola_s[j]='\0'; /** Inserimento carattere di fine stringa **/
    printf("\nLa Stringa inserita STATICAMENTE e':\n--->");
    puts(parola_s); /** Stampa della stringa **/
}

void all_dinamica(int n)
{
    char *parola_d; /** Puntatore generico della stringa attraverso puntatore **/
    int i=0, j=0;
    parola_d=(char *) malloc((n+1)); /** Allocazione dinamica **/
    printf("\nINSERIRE LA STRINGA CARATTERE X CARATTERE\n");
    for(i=0;i<n;i++) /** Ciclo for per inserire i caratteri **/
    {
        printf("Inserire carattere %d:\n>>", i+1);
        fflush(stdin);
        *(parola_d+i)=getchar(); /** INPUT con la funzione getchar **/
        j++;
    }
    *(parola_d+j)='\0'; /** Inserimento carattere di fine stringa **/
    printf("\nLa Stringa inserita DINAMICAMENTE e':\n--->");
    puts(parola_d); /** Stampa della stringa **/
    free(parola_d); /** Libero allocazione Dinamica **/
}
