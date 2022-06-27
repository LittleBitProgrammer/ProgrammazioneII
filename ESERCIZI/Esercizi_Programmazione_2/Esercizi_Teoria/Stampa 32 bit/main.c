#include <stdio.h>
#include <stdlib.h>
void bit_show(short, char [], short []);
int main()
{
    union word32bit{
        float F;
        int L;
        short S[2];
        char C[4];
        }word;
    int len, k;
    short bit[32];
    printf("Hello world!\n");
    printf("\nInserire int: ");
    scanf("%d", &(word.L));
    len=sizeof(int);
    bit_show(sizeof(int),word.C,bit);
    printf("\n");
    for(k=8*len-1;k>=0;k--)
        printf("%hd", bit[k]);
    printf("\n");
    return 0;
}

void bit_show(short len, char ch[], short bit[32])
{
    short j, jc; char c;
    int k;
    for(j=0;j<32;j++)
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
        for(k=8*len-1;k>=0;k--)
        printf("%hd", bit[k]);
}
