#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSONE{
        char nome[30];
        struct PERSONE *p_next;
        };
struct PERSONE utenti[11];
int main()
{
    short i=0, testa=3; /** IL TERZO ELEMENETO E' LA TESTA DELLA LISTA **/
    struct PERSONE *punt;
    strcpy(utenti->nome, "ANNA\t5\n");
    utenti[0].p_next=&utenti[5];
    strcpy((utenti+1)->nome, "MARIO\t8\n");
    utenti[1].p_next=&utenti[8];
    strcpy((utenti+2)->nome, "GIUSEPPE\t6\n");
    utenti[2].p_next=&utenti[6];
    strcpy((utenti+3)->nome, "ANGELA\t0\n");
    utenti[3].p_next=&utenti[0];
    strcpy((utenti+4)->nome, "VALERIA\t-1\n");
    utenti[4].p_next=NULL;
    strcpy((utenti+5)->nome, "FABRIZIO\t7\n");
    utenti[5].p_next=&utenti[7];
    strcpy((utenti+6)->nome, "MARIANNA\t1\n");
    utenti[6].p_next=&utenti[1];
    strcpy((utenti+7)->nome, "GIOVANNI\t2\n");
    utenti[7].p_next=&utenti[2];
    strcpy((utenti+8)->nome, "PATRIZIA\t10\n");
    utenti[8].p_next=&utenti[10];
    strcpy((utenti+9)->nome, "VALENTINA\t4\n");
    utenti[9].p_next=&utenti[4];
    strcpy((utenti+10)->nome, "SARA\t9\n");
    utenti[10].p_next=&utenti[9];
    punt=&utenti[testa];
    printf("\n<---LISTA NON ORDINATA--->\n");
    system("PAUSE");
    for(i=0;i<11;i++)
        printf("-->%s\n",(utenti+i)->nome);
    printf("\n<---LISTA ORDINATA--->\n");
    system("PAUSE");
    while(punt!=NULL)
    {
        printf("-->%s\n",punt->nome);
        punt=punt->p_next;
    }
return 0;
}
