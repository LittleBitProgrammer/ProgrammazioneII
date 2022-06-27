#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void all_statica(char *s1, char *s2); /** Function per Concatenazione STATICA **/
void all_dinamica(char *s1, char *s2); /** Function per Concatenazione DINAMICA **/

int main()
{
    char s1[25], s2[25]; /** Dichiarazione delle stringhe da concatenare **/
    printf("INIZIO PROGRAMMA\n");
    printf("Inserire prima STRINGA\n>>");
    gets(s1); /** INPUT STRINGA1 **/
    printf("Inserire seconda STRINGA\n>>");
    gets(s2); /** INPUT STRINGA2 **/
    printf("\n\t--->ALLOCAZIONE STATICA<---\n");
    system("PAUSE");
    all_statica(s1,s2); /** Richiama function **/
    printf("\n\t--->ALLOCAZIONE DINAMICA<---\n");
    system("PAUSE");
    all_dinamica(s1,s2); /** Richiama function **/
return 0;
}

void all_statica(char *s1, char *s2)
{
    char s3[50];
    strcpy(s3,s1); /** Copio S1 in s3 **/
    strcpy(s3+strlen(s1),s2); /** Copio S2 nello shape finale di s1 in s3 **/
    printf("\nRisultato della CONCATENAZIONE STATICA e':\n--->");
    puts(s3); /** Stampo S3 **/
}

void all_dinamica(char *s1, char *s2)
{
    char *s3;
    s3=(char *) malloc(strlen(s1)+strlen(s2)+1); /** Dichiarazione DINAMICA di s3 di dimensione data dalla somma degli strlen di S1 e S2 **/
    strcpy(s3,s1);  /** Copio S1 in S3 **/
    strcpy(s3+strlen(s1),s2); /** Copio S2 in S3 nel punto in cui finisce S1 **/
    printf("\nRisultato della CONCATENAZIONE DINAMICA e':\n--->");
    puts(s3); /** Stampo S3 **/
    free(s3); /** LIBERO MEMORIA **/
}
