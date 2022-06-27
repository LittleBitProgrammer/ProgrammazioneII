#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[200], nome_file[100]; /** L'array buffer e' un array atto a contenere un gruppo di byte che volta per volta andro a sostituire il contenuto ad ogni letture **/
    FILE *fp; /** Puntatore al FILE **/
    printf("INIZIO PROGRAMMA\n");
    printf("Inserire nome del file:\n>>");
    gets(nome_file); /** INPUT PERCORSO FILE **/
    if((fp=fopen(nome_file, "r"))==NULL) /**  Verifica errore al puntatore NULLO **/
    {
        printf("<----ERRORE APERTURA FILE---->");
        exit(1); /** Se esso e' NULLO si procede alla terminazione del programma **/
    }
    while(!feof(fp)) /** Ciclo WHILe fin quando non termina il file **/
    {
       fgets(buffer,200,fp); /** Ad ogni iterazione viene prodotta la memorizzazione di ogni stringa di size 200 **/
       printf("%d\t%s\n",feof(fp),buffer); /** Stampa a video del BUFFER **/
    }
    fclose(fp); /** Chiusura del FILE **/
return 0;
}
