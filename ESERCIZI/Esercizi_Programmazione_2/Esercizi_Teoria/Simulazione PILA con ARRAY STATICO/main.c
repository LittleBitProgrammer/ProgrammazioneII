/*P2_08_03_T*/


/* 37. [liv.1] Simulare in C la gestione di una pila (stack) tramite array statico (può essere anche un array di struct)
	creando le funzioni di manipolazione push() [inserimento] e pop() [eliminazione]. Il programma deve
	prevedere un menù che consenta di scegliere l’operazione da eseguire.*/
#include <stdio.h>
#include <windows.h>
#define LEN_MAX 10
typedef enum {false, true} bool;

void function_ins (char [], int*);
void function_tog (char [], int*);
void function_vis (char []);
void inizializzazione (char []);

int main () {
    char stack[11];
    int pointer = 0;    //punta alla prima cella di memoria vuota
    bool flag = false;
    int scelta;

    inizializzazione (stack);

    do  {
        printf ("Cosa vuoi fare?\n");
        printf ("[1] - inserisci\n[2] - togli\n[3] - visualizza\n[4] - esci\n");
        scanf ("%d",&scelta);
        fflush (stdin);
        switch (scelta) {
        case 1 : function_ins (stack, &pointer); break;
        case 2 : function_tog (stack, &pointer); break;
        case 3 : function_vis (stack); break;
        case 4 : flag = true; break;
            default : printf ("Scelta non consentita\n");
        }
        system("PAUSE");
        system("cls");
    } while (flag == false);
return 0;
}
void function_ins (char stack [], int *pointer){
    char buffer_char;
    if (*pointer < LEN_MAX) {
        printf ("Che carattere vuoi inserire? ");
        scanf ("%c",&buffer_char);

        stack [*pointer] = buffer_char;
        (*pointer)++;
    } else
        printf ("ERRORE: stack pieno\n");
}
void function_tog (char stack [], int *pointer) {
    if (*pointer == 0)
        printf ("ERRORE: stack gia' vuoto\n");
    else {
        (*pointer)--;
        stack [*pointer] = ' ';
        printf ("Carattere tolto\n");
    }
}
void function_vis (char stack []) {
    int i;
    for (i=LEN_MAX-1; i>-1; i--)
        printf ("%d - %c\n", i, stack [i]);
}
void inizializzazione (char stack []) {
    int i;
    for (i=0; i<LEN_MAX; i++)
        stack [i] = ' ';
}
