#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum{false, true}bool;
typedef struct{ /** STRUCT STUDENTE **/
            char nome[31];
            char matricola[11];
            short esami_superati;
            float media;
            short crediti;
                }STUDENTI;
typedef struct{ /** STRUCT AGGIORNAMENTO **/
            char matricola[11];
            float voto;
            short crediti;
                }ESAMI;

STUDENTI studenti[5];
ESAMI superati[5];

void crea_studenti(short n); /** FUNCTION PER CREAZIONE PRIMO FILE **/
void crea_aggiornamento(short n); /** FUNCTION PER CREAZIONE SECONDO FILE **/
void aggiorna_esame(short n); /** FUNCTION PER AGGIORNAMENTO E CREZIONE DEL FILE **/
float media(float , short *, int); /** FUNCTION PER LA MEDIA DEI VOTI **/

int main()
{
    short n;
    printf("Inserisci NUMERO di STUDENTI DA REGISTRARE (MAX 5)\n>>");
    scanf("%hd", &n); /** INPUT numero di studenti **/
    crea_studenti(n); /** Richiamo Function **/
    crea_aggiornamento(n); /** Richiamo Function **/
    aggiorna_esame(n); /** Richiamo Function **/
return 0;
}

void crea_studenti(short n)
{
    short i=0;
    FILE *fp_studenti; /** Dichiarazione file **/
    printf("\n\t\t<-----CREAZIONE FILE PRINCIPALE----->\n");
    for(i=0;i<n;i++) /** Riempio i campi della STRUCT **/
    {
        printf("\n\t<--- STUDENTE %hd --->\n", i+1);
        printf("\nInserisci NOME e COGNOME\n>>");
        fflush(stdin);
        gets(studenti[i].nome);
        printf("\nInserisci MATRICOLA\n>>");
        fflush(stdin);
        gets(studenti[i].matricola);
        printf("\nInserisci NUMERO ESAMI SUPERATI\n>>");
        fflush(stdin);
        scanf("%hd", &studenti[i].esami_superati);
        printf("\nInserisci MEDIA dei voti\n>>");
        fflush(stdin);
        scanf("%f", &studenti[i].media);
        printf("\nInserisci NUMERO CREDITI ottenuti\n>>");
        fflush(stdin);
        scanf("%hd", &studenti[i].crediti);
    }
    if((fp_studenti=fopen("studenti1.dat", "wb"))==NULL) /** Apro il FILE BINARIO per SCRIVERE SUL FILE **/
    {
        printf("\n<---ERRORE CREAZIONE FILE--->\n"); /** Nel caso di errore nell'apertura del FILE **/
        exit(1); /** TERMINA LA FUNCTION **/
    }
    if((fwrite(studenti,sizeof(studenti[0]), n, fp_studenti))!=n) /** Scrivo sul FILE le STRUCT **/
    {
        printf("\n<---ERRORE SALVATAGGIO FILE--->\n"); /** Nel caso di errore nell'apertura del FILE **/
        exit(1);  /** TERMINA LA FUNCTION **/
    }
    fclose(fp_studenti); /** Chiude il FILE **/
}

void crea_aggiornamento(short n)
{
    short i=0;
    FILE *fp_aggiornamento; /** Dichiarazione del FILE **/
    printf("\n\t\t<-----CREZIONE FILE PER AGGIORNAMENOT----->\n");
    for(i=0;i<n;i++) /** INPUT delle STRUCT per l'aggiornamento **/
    {
        printf("\n\t<--- STUDENTE %hd --->\n", i+1);
        printf("\nInserisci MATRICOLA\n>>");
        fflush(stdin);
        gets(superati[i].matricola);
        printf("\nInserisci VOTO esame\n>>");
        scanf("%f", &superati[i].voto);
        printf("\nInsersci CREDITI dell'esame\n>>");
        scanf("%hd", &superati[i].crediti);
    }
    if((fp_aggiornamento=fopen("esameProg2.dat", "wb"))==NULL) /** Creazione e Apertura file BINARIO **/
    {
        printf("\n<---ERRORE CREAZIONE FILE--->\n"); /** Nel caso di ERRORE nella creazione del file **/
        exit(1); /** Uscita dalla FUNCTION **/
    }
    if((fwrite(superati,sizeof(superati[0]), n, fp_aggiornamento))!=n) /** Scrivo sul FILE le STRUCT **/
    {
        printf("\n<---ERRORE SALVATAGGIO FILE--->\n"); /** Nel caso di errore della SCRITTURa **/
        exit(1); /** Uscita dalla Function **/
    }
    fclose(fp_aggiornamento); /** Chiusura del FILE **/
}

float media(float ex_media, short *es_sup, int nuovo_voto) /** Function per il calcolo della MEDIA PONDERATA **/
{
    ex_media=ex_media*(*es_sup);
    (*es_sup)++;
    ex_media=ex_media+nuovo_voto;
    return ex_media/(*es_sup);
}

void aggiorna_esame(short n)
{
    FILE *fp_studenti, *fp_esami; /** Dichiarzione dei FILE **/
    short i=0, j=0;
    ESAMI esame [n]; /** Dichiarazione della STRUCT **/
    if((fp_studenti=fopen("studenti1.dat","rb"))==NULL) /** APERTURA del primo FILE **/
    {
        printf("\n<---ERRORE APERTURA FILE--->\n");
        exit(1);
    }
    if((fp_esami=fopen("esameProg2.dat","rb"))==NULL) /** APERTURA del secondo FILE **/
    {
        printf("\n<---ERRORE APERTURA FILE--->\n");
        exit(1);
    }
    if((fread(studenti,sizeof(studenti[0]),n,fp_studenti))!=n) /** Lettura del FILE **/
    {
        printf("\n<---ERRORE PASSAGGIO IN MEMORIA\n");
        exit(1);
    }
    if((fread(esame,sizeof(esame[0]),n,fp_esami))!=n) /** Lettura del FILE **/
    {
        printf("\n<---ERRORE PASSAGGIO IN MEMORIA\n");
        exit(1);
    }
    fclose(fp_studenti); fclose(fp_esami); /** Chiusura dei FILE perche' i dati dei file sono gia' salvati nel BUFFER **/
    do{ /** Ciclo DO/WHILE che mette a confronto le matricole dei due file, se uguali somma i crediti degli esami e calcola la nuova media **/
        if(strcmp(esame[i].matricola,studenti[j].matricola)!=0)
            j++;
        else
        {
            media(studenti[i].media, &studenti[i].esami_superati, esame[j].voto);
            studenti[j].crediti+=esame[i].crediti;
            i++;
        }
    }while(i<n);
    if((fp_studenti=fopen("studenti2.dat","wb"))==NULL) /** Creazione nuovo FILE di destinazione **/
    {
        printf("\n<---ERRORE APERTURA FILE--->\n"); /** Nel caso di ERRORE nella creazione del FILE **/
        exit(1); /** USCITA anticipata dalla FUNCTION **/
    }
    if((fwrite(studenti,sizeof(studenti[0]),n,fp_studenti))!=n) /** SCRITTURA delle STRUCT aggiornate dei primi 2 FILE **/
    {
        printf("\n<---ERRORE SALVATAGIO FILE--->\n"); /** Nel caso di ERRORE della SCRITTURa **/
        exit(1); /** USCITA anticipata dalla FUNCTION **/
    }
    fclose(fp_studenti); /** CHIUSURA del FILE **/
}
