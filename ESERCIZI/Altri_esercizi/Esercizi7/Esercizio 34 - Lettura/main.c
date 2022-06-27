/*Scrivere un programma C che crei un file binario “studenti1.dat” contenente le seguenti informazioni:
o cognome e nome (30c) c = char
o matricola (cccc/cccccc) [es. 0124/002345]
o numero degli esami superati (short)
o media pesata degli esami (float)
o crediti acquisiti (short).
Il file contiene le informazioni già ordinate per matricola. Scrivere una function C che, a partire da un file di
aggiornamento relativo ad un certo esame (per esempio, “esameProg2.dat”) contenente gli studenti che
l’hanno superato ed i relativi voti, crei il file “studenti2.dat” aggiornato.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome_cogn[30];
    int matricola;
    short esami_superati;
    float media_pesata;
    short crediti_tot;
}stud;

void fill_student(stud* studente);
void show_student(stud* s, FILE* fp);

int main()
{
    char scelta;
    short num, num1;
    FILE* fp_stud;
    stud studente, s_to_read;

    fp_stud=fopen("studenti1.txt", "a+b");

    printf("Che azione vuoi eseguire?\n[1]Inserisci uno studente nei file.\n[2]Leggi uno studente\n[0]Esci\n\n|----->");
    scanf("%c", &scelta);

    switch(scelta)
    {
        case '0':
            break;

        case '1':
            printf("Quanti studenti vuoi aggiungere? ");
            scanf("%hd", &num);
            for(char i=1; i<=num; i++)
            {
                fill_student(&studente);//inserisco i dati dello studente nella struct di buffer

                if(fwrite(&studente, sizeof(stud), 1, fp_stud)!=1)//Mi accerto che la fwrite funzioni a dovere
                {
                    puts("\n*** ERRORE SALVATAGGIO STUDENTE! ***");
                    exit(1);
                }
            }

            fclose(fp_stud);
            break;

        case '2':
                printf("Quale studente vuoi visualizzare? ");
                scanf("%hd", &num1);

                fseek(fp_stud, sizeof(stud)*num1, SEEK_CUR);

                show_student(&s_to_read, fp_stud);

            fclose(fp_stud);
            break;

        default:
            printf("Hai sbagliato scelta.\n");
            break;
    }

}

void fill_student(stud* studente)
{
    system("cls");

     printf("Inserisci il nome dello studente: ");
     fflush(stdin);
    fgets(studente->nome_cogn, 20, stdin);
    printf("Inserisci la matricola dello studente: ");
    scanf("%d", &studente->matricola);
    fflush(stdin);
    printf("Inserisci il numero di esami superati: ");
    scanf("%hd", &studente->esami_superati);

    printf("Inserisci la media dello studente: ");
    scanf("%f", &studente->media_pesata);

    printf("Inserisci i crediti acquisiti dallo studente: ");
    scanf("%hd", &studente->crediti_tot);
}

void show_student(stud* s, FILE* fp)
{

    fread(s, sizeof(stud), 1, fp);
    system("cls");
    printf("Nome e cognome: %s", s->nome_cogn);
    printf("Matricola: %d\n", s->matricola);
    printf("Numero esami superati: %hd\n", s->esami_superati);
    printf("Media: %f\n", s->media_pesata);
    printf("Crediti totali: %hd\n", s->crediti_tot);

}
