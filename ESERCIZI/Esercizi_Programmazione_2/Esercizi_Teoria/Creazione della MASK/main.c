#include <stdio.h>
#include <stdlib.h>

void main()
{
    unsigned char bit[16][4]={'0','0','0','0', '0','0','0','1', '0','0','1','0', '0','0','1','1',
                                '0','1','0','0', '0','1','0','1', '0','1','1','0', '0','1','1','1',
                                '1','0','0','0', '1','0','0','1', '1','0','1','0', '1','0','1','1',
                                '1','1','0','0', '1','1','0','1', '1','1','1','0', '1','1','1','1'};
    unsigned char dx,sx, mask;
    int b;
    printf("\n**************\n");
    printf("CREAZONE DELLA MASCHERA");
    printf("\nMaschera dei bit meno significativi(5 bit)\n");
    for(b=1;b<=5;b++)
        mask=mask<<1|1;
    sx=mask>>4;
    dx=(mask<<4); dx=dx>>4;
    printf("\nCHAR= %c\t DEC= %d\t EX=%02x\n",mask,mask,mask);
    printf("\n\t\tBIN=%c%c%c%c %c%c%c%c\n",bit[sx][0],bit[sx][1],bit[sx][2],bit[sx][3],
                                            bit[dx][0],bit[dx][1],bit[dx][2],bit[dx][3]);
    printf("\n\n\n");
    printf("\nMaschera dei bit piu' significativi(5 bit)\n");
    mask=mask<<(sizeof(unsigned char)*8-5);
    printf("\nCHAR= %c\t DEC= %d\t EX=%02x\n",mask,mask,mask);
    sx=mask>>4;
    dx=(mask<<4); dx=dx>>4;
    printf("\n\t\tBIN=%c%c%c%c %c%c%c%c\n",bit[sx][0],bit[sx][1],bit[sx][2],bit[sx][3],
                                            bit[dx][0],bit[dx][1],bit[dx][2],bit[dx][3]);

}
