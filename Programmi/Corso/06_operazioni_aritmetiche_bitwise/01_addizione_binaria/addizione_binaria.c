void addizione_binaria(int op1, int op2)
{
    int sum;
    int riporto = 1;

    while (riporto > 0)
    {
        sum = op1 ^ op2;
        riporto = op1 & op2;
        riporto <<= 1;
        
        op1 = sum;
        op2 = riporto;
    }
    
}