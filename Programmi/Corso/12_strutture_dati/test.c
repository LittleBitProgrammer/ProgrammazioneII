#include <stdio.h>

void printTest(char *array)
{
    printf("%c", array[0]);
}
 
int main()
{
    char *c = "ABCD";

    printTest(c +2);

    return 0;
 
}