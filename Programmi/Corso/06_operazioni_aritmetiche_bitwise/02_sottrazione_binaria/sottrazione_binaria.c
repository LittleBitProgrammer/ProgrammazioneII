void addizione_binaria(int op1, int op2)
{
    int difference;
    int riporto = 1;

    while (riporto > 0)
    {
        difference = op1 ^ op2;
        riporto = ((~op1) & op2);
        riporto <<= 1;
        
        op1 = difference;
        op2 = riporto;
    }
    
}