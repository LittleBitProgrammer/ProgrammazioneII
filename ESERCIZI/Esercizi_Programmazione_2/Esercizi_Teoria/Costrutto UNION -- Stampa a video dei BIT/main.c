#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 32 /**Numero bit intero LONG**/
void bit_show(short , char [], short []);
void main()
{
    short menu, bit[MAX];
    int len, k;
    union word32bit{
            float F;
            long L;
            short S[2];
            char C[4];
                    }word;
    do{
        puts("Seleziona");
        puts("[0]. uscita dal programma");
        puts("[1]. rappresentazione binaria di un intero char");
        puts("[2]. rappresentazione binaria di un intero short");
        puts("[3]. rappresentazione binaria di un intero long");
        fflush(stdin);
        scanf("%hd",&menu);
    switch(menu){
        case 0: exit(0);
        case 1:
            len=sizeof(char);
            printf("\nimmettere intero char C: ");
            fflush(stdin);
            scanf("%c",&(word.C[0]));
            puts("Char in decimale, esadecimale e binario");
            printf("C=%+10hd,   hex=%x\t", word.C[0],word.C[0]);
            bit_show(sizeof(char), word.C,bit); break;
        case 2:
            len=sizeof(short);
            printf("\nimmettere intero short S: ");
            fflush(stdin);
            scanf("%hd",&(word.S[0]));
            puts("Short in decimale, esadecimale e binario");
            printf("C=%hd,   hex=%x\t", word.S[0],word.S[0]);
            bit_show(sizeof(short), word.C,bit); break;
        case 3:
            len=sizeof(long);
            printf("\nimmettere intero long L: ");
            fflush(stdin);
            scanf("%ld",&(word.L));
            puts("Long in decimale, esadecimale e binario");
            printf("L=%d,   hex=%x\t", word.L, word.L);
            bit_show(sizeof(long), word.C, bit); break;
        default: exit(1);
    }
     for(k=8*len-1;k>=0;k--)
         (k%4==0) ? printf("%1d", bit[k]): printf("%1d", bit[k]);
    printf("\n");
     }while(menu!=0);
}

void bit_show(short len, char ch[], short bit[MAX])
{
    short j, jc;
    char c;
    for(j=0;j<MAX;j++)
        bit[j]=0;
    for(jc=0;jc<len;jc++)
    {
        c=ch[jc];
        for(j=0;j<8;j++)
        {
            bit[j+8*jc]=c&1;
            c=c>>1;
        }
    }
}
