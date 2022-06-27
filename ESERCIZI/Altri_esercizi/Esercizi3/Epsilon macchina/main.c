/*Programma che calcola l'epsilon macchihina*/
#include <stdio.h>
#include <stdlib.h>
void epsilon_reg_ALU();
int main()
{
    float epsilon=1, val;
    short n=-1;

    val=epsilon+1;
    while(val>1)//IN VAL CI SARA' LA SOMMA TRA EPSILON E 1; FINIRA' SOLO SE E+1=1;
    {
        epsilon/=2;
        n++;//INCREMENTO IN CONTATORE DELLE DIVISIONI
        val=epsilon+1;//CALCOLO PER L'ENNESIMA VOLTA IL VALORW
    }
    epsilon=2.0F*epsilon;
    printf("-> EPSILON REGISTRI MEMORIA <-\nIl numero e' stato dimezzato %hd volte.\nIl valore dell'epsilon macchina e': %e.\n", n, epsilon);

    epsilon_reg_ALU();

    return 0;
}

void epsilon_reg_ALU()
{
    float epsilon=1;
    short n=-1;

    while(epsilon+1>1)
    {
        n++;
        epsilon/=2;
    }

    epsilon=2.0F*epsilon;
    printf("\n-> EPSILON REGISTRI ALU <-\nIl numero e' stato dimezzato %hd volte.\nIl valore dell'epsilon macchina e': %e.\n", n, epsilon);
}
