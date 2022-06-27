/*Scrivere function C per la visita di un grafo mediante l’algoritmo Depth First Search iterativo.
Applicare l’algoritmo al grafo che descrive il seguente labirinto per determinare un cammino che parte
dall’ingresso A e termina nell’uscita Q.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODI 27

typedef struct nodo
{
    char nome;
    short visited;
    short grado;
    short indici[4];
}NODO;

NODO grafo[MAX_NODI];

short stack[MAX_NODI]={-1};
short n_el_pila=0, testa=0;

int main()
{
    initialize_lab();

    iterat_DFS_visit();

    return 0;
}

void initialize_lab()
{

    grafo[0].nome='A';
    grafo[1].nome='a';
    char c='B';
    for(short i=2; i<27; i++)
        grafo[i].nome=c++;

    for(short i=0; i<27; i++)
        grafo[i].visited=0;

    grafo[0].indici[0]=1;
    grafo[0].indici[1]=2;
    grafo[0].grado=2;
    grafo[1].indici[0]=4;
    grafo[1].indici[1]=0;
    grafo[1].indici[2]=11;
    grafo[1].grado=3;
    grafo[2].indici[0]=0;
    grafo[2].indici[1]=4;
    grafo[2].indici[2]=3;
    grafo[2].grado=3;
    grafo[3].indici[0]=2;
    grafo[3].indici[1]=5;
    grafo[3].grado=2;
    grafo[4].indici[0]=1;
    grafo[4].indici[1]=2;
    grafo[4].indici[2]=24;
    grafo[4].indici[3]=7;
    grafo[4].grado=4;
    grafo[5].indici[0]=3;
    grafo[5].indici[1]=6;
    grafo[5].grado=2;
    grafo[6].indici[0]=5;
    grafo[6].indici[1]=7;
    grafo[6].indici[2]=9;
    grafo[6].grado=3;
    grafo[7].indici[0]=4;
    grafo[7].indici[1]=6;
    grafo[7].indici[2]=8;
    grafo[7].grado=3;
    grafo[8].indici[0]=7;
    grafo[8].indici[1]=12;
    grafo[8].indici[2]=26;
    grafo[8].grado=3;
    grafo[9].indici[0]=6;
    grafo[9].indici[1]=13;
    grafo[9].grado=2;
    grafo[10].indici[0]=11;
    grafo[10].indici[1]=25;
    grafo[10].grado=2;
    grafo[11].indici[0]=1;
    grafo[11].indici[1]=10;
    grafo[11].grado=2;
    grafo[12].indici[0]=8;
    grafo[12].indici[1]=13;
    grafo[12].indici[2]=14;
    grafo[12].grado=3;
    grafo[13].indici[0]=9;
    grafo[13].indici[1]=12;
    grafo[13].indici[2]=16;
    grafo[13].grado=3;
    grafo[14].indici[0]=15;
    grafo[14].indici[1]=12;
    grafo[14].indici[2]=18;
    grafo[14].grado=3;
    grafo[15].indici[0]=14;
    grafo[15].indici[1]=16;
    grafo[15].indici[2]=17;
    grafo[15].indici[3]=3;
    grafo[16].indici[0]=13;
    grafo[16].indici[1]=15;
    grafo[16].grado=2;
    //17 SALTO
    grafo[18].indici[0]=14;
    grafo[18].indici[1]=19;
    grafo[18].indici[2]=21;
    grafo[18].grado=3;
    grafo[19].indici[0]=10;
    grafo[19].indici[1]=18;
    grafo[19].indici[2]=17;
    grafo[19].grado=3;
    grafo[20].indici[0]=19;
    grafo[20].indici[1]=22;
    grafo[20].grado=2;
    grafo[21].indici[0]=18;
    grafo[21].indici[1]=22;
    grafo[21].indici[2]=26;
    grafo[21].grado=3;
    grafo[22].indici[0]=20;
    grafo[22].indici[1]=21;
    grafo[22].indici[2]=23;
    grafo[22].grado=3;
    grafo[23].indici[0]=22;
    grafo[23].indici[1]=25;
    grafo[23].grado=2;
    grafo[24].indici[0]=25;
    grafo[24].indici[1]=26;
    grafo[24].indici[2]=4;
    grafo[24].grado=3;
    grafo[25].indici[0]=23;
    grafo[25].indici[1]=24;
    grafo[25].indici[2]=10;
    grafo[25].grado=3;
    grafo[26].indici[0]=24;
    grafo[26].indici[1]=21;
    grafo[26].indici[2]=8;
    grafo[26].grado=3;

}

void push(short el)
{
    if(testa<MAX_NODI)
        stack[testa++]=el;

    printf("testa= %hd\n", testa);
}

short pop()
{
    if(testa>0)
        return stack[--testa];

}

void iterat_DFS_visit()
{
    short i_corr,i=0;

    printf(">>NODO VISITATO: %c\n", grafo[0].nome);
    grafo[0].visited=1;

    for(short i=0; i<grafo[0].grado; i++)
        push(grafo[0].indici[i]);

    while(i<10)
    {
        i_corr=pop();
        if(grafo[i_corr].visited==0)
        {
            printf(">>NODO VISITATO: %c\n", grafo[i_corr].nome);
            grafo[i_corr].visited=1;
        }

        for(short i=0; i<grafo[i_corr].grado; i++)
            push(grafo[i_corr].indici[i]);

        i++;
    }

}

