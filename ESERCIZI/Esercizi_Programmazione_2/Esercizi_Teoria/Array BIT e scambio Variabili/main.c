#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char bit[16][4]={'0','0','0','0', '0','0','0','1', '0','0','1','0', '0','0','1','1',
                                '0','1','0','0', '0','1','0','1', '0','1','1','0', '0','1','1','1',
                                '1','0','0','0', '1','0','0','1', '1','0','1','0', '1','0','1','1',
                                '1','1','0','0', '1','1','0','1', '1','1','1','0', '1','1','1','1'};
    unsigned char C, dx,sx;
    int x,y;
    C='a';
    sx=C>>4;
    dx=(C<<4); dx=dx>>4;
    printf("\nCHAR= %c\t DEC= %d\t EX=%02x\n",C,C,C);
    printf("\n\t\tBIN=%c%c%c%c %c%c%c%c\n",bit[sx][0],bit[sx][1],bit[sx][2],bit[sx][3],
                                            bit[dx][0],bit[dx][1],bit[dx][2],bit[dx][3]);
    printf("\n*****************************************\n");
    printf("SCAMBIO VARIABILI CON BITWISE");
    printf("\n Inserire X ed Y: ");
    scanf("%d%d",&x,&y);
    x=x^y;
    y=x^y;
    x=x^y;
    printf("\nX= %d\t Y=%d\n",x,y);
}
