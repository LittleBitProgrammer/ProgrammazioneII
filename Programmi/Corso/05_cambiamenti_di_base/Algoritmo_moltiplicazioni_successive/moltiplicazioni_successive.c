void fraz_bit_mult(float x, unsigned char n_bit, unsigned char bit[23])
{
    int i;
    for(i = 0; i < n_bit; i++)
    {
        x *= 2;
        bit[i] = (char)x; /* si può usare anche il floor da <math.h> */
        x -= bit[i];
    }

    for(i = n_bit; i < 23; i++)
    {
        bit[i] = 0;
    }
}