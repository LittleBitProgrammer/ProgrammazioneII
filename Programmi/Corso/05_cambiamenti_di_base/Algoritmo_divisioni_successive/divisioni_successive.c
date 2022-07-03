void char_bit_divisioni(unsigned char n, unsigned char bit[8])
{
    int i,j = 0;

    do
    {
        bit[j++] = n % 2;
        n /= 2;
    } while (n > 0);
    
    /* Azzera i restanti bit */
    for(i = j; i < 8; i++)
    {
        bit[i] = 0;
    }
}