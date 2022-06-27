/*Scrivere delle function C per calcolare rispettivamente l’epsilon macchina del tipo float, del tipo
double e del tipo long double, visualizzando ad ogni passo i singoli bit. Confrontare i risultati ottenuti
con i valori delle variabili predefinite FLT_EPSILON, DBL_EPSILON e LDBL_EPSILON.*/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
union numero
{
    float eps_float;
    double eps_double;
    long double eps_ld;

    long long int x[2];
}epsilon;
char bit[128]={0};

void epsilon_calc_float();
void epsilon_calc_double();
void epsilon_calc_ld();
void bit_show();

int main()
{
    char scelta, scelta2=1;

    do
    {
        system("cls");
        printf("Seleziona il tipo di dato di cui vuoi conoscere l'epsilon.\n[1] FLOAT\n[2] DOUBLE\n[3] LONG DOUBLE\n");
        //printf("Float= %e\nDouble= %e\nLong double= %e\n", FLT_EPSILON, DBL_EPSILON, LDBL_EPSILON);
        do
        {
            printf("\n--->");
            scanf("%hd", &scelta);
        }while(scelta<1 | scelta>3);

        switch(scelta)
        {
        case 1:
            epsilon_calc_float();
            break;
        case 2:
            epsilon_calc_double();
            break;
        case 3:
            epsilon_calc_ld();
            break;
        }
        system("PAUSE");
        system("cls");
        printf("Vuoi provare un altro tipo?\n[1]SI\n[0]No\n--->");
        scanf("%hd", &scelta2);
    }while(scelta2!=0);
}

void bit_show()
{
    char i=0, j=0;
    do
    {
        bit[j++]=epsilon.x[i]&1;
        epsilon.x[i]>>=1;
        if(j== 63 ||j==127)
            i++;
    }while(i<2);
}

void epsilon_calc_float()
{
    epsilon.eps_float=1; //ULP DI 1
    float val=epsilon.eps_float+1, temp;
    char n_div=-1;
    printf("\n");
    while(val>1)
    {
        epsilon.eps_float/=2;//DIMEZZO L'EPSILON
        temp=epsilon.eps_float;//SALVO L'EPSILON CHE POI VERRA' AZZERATO PER MOSTRARLO
        //epsilon.eps_float+=1;
        n_div++;
        bit_show();

        for(short i=31; i>=0; i--)
        {
            (i==31 || i==23) ? printf("%hd ", bit[i]) : printf("%hd", bit[i]);
        }

        val=temp+1;//CALCOLO IL VALORE
        epsilon.eps_float=temp;//RIPRISTINO EPSILON
        printf("\n");
    }
    epsilon.eps_float*=2.0F;

    printf("\nIl valore dell'epsilon del tipo FLOAT e' uguale a: %e\n%hd divisioni effettuate.\n", epsilon.eps_float, n_div);
    printf("Float epsilon= %e\n\n", FLT_EPSILON);
}

void epsilon_calc_double()
{
    epsilon.eps_double=1; //ULP DI 1
    double val=epsilon.eps_double+1, temp;
    char n_div=-1;
    printf("\n");
    while(val>1)
    {
        epsilon.eps_double/=2;//DIMEZZO L'EPSILON
        temp=epsilon.eps_double;//SALVO L'EPSILON CHE POI VERRA' AZZERATO PER MOSTRARLO
        epsilon.eps_double+=1;
        n_div++;
        bit_show();

        for(short i=63; i>=0; i--)
        {
            (i==63 || i==52) ? printf("%hd ", bit[i]) : printf("%hd", bit[i]);
        }

        val=temp+1;//CALCOLO IL VALORE
        epsilon.eps_double=temp;//RIPRISTINO EPSILON
        printf("\n");
    }
    epsilon.eps_double*=2.0F;

    printf("\nIl valore dell'epsilon del tipo DOUBLE e' uguale a: %e\n%hd divisioni effettuate.\n", epsilon.eps_double, n_div);
    printf("Double epsilon= %e\n\n", DBL_EPSILON);
}

void epsilon_calc_ld()
{
    epsilon.eps_ld=1; //ULP DI 1
    long double val=epsilon.eps_ld+1, temp;
    char n_div=-1;
    printf("\n");
    while(val>1)
    {
        epsilon.eps_ld/=2;//DIMEZZO L'EPSILON
        temp=epsilon.eps_ld;//SALVO L'EPSILON CHE POI VERRA' AZZERATO PER MOSTRARLO
        epsilon.eps_ld+=1;
        n_div++;
        bit_show();

        for(short i=79; i>=0; i--)
        {
            (i==79 || i==62) ? printf("%hd ", bit[i]) : printf("%hd", bit[i]);
        }

        val=temp+1;//CALCOLO IL VALORE
        epsilon.eps_ld=temp;//RIPRISTINO EPSILON
        printf("\n");
    }
    epsilon.eps_ld*=2.0F;

    printf("\nIl valore dell'epsilon del tipo LONG DOUBLE e' uguale a: %e\n%hd divisioni effettuate.\n", epsilon.eps_ld, n_div);
    printf("Long double epsilon= %e\n\n", LDBL_EPSILON);
}
