/*Approssimare lo zero di una funzione, monotona in un intervallo [a,b] e tale che f(a)f(b)<0, mediante
algoritmo di bisezione ricorsivo. */

#include <stdio.h>
#include <stdlib.h>

float functions_zero(float x_max, float x_min, float precision);
float f(float x);

int main()
{
    float precisione=0.1F;

    printf("Zero= %f\n", functions_zero(6, -2, precisione));

}

float f(float x)
{
    return 3*x-8;
}

float functions_zero(float x_max, float x_min, float precision)
{
    float x_med=(x_max+x_min)/2;

    if(x_max-x_min<precision)
        return x_med;
    else if(f(x_min)*f(x_med)<0)
        return functions_zero(x_min, x_med, precision);
    else
        return functions_zero(x_med, x_max, precision);
}
