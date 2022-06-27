#ifndef MIOHEADER_H_INCLUDED
#define MIOHEADER_H_INCLUDED

#include <iostream>
//LIBRERIE

using namespace std;

class Data
{
private:
    int d, m, y;

public:
    Data(int dd, int mm, int yy);
    void get_date();
    Data& add_day(int n);
    Data& add_month(int n);
};

Data::Data(int dd, int mm, int yy)
{
    d=dd; m=mm; y=yy;
}

void Data::get_date()
{
    cout<<"Giorno= "<<d<< endl;
    cout<<"Mese= "<<m<<endl;
    cout<<"Anno= "<<y<< endl;
}

Data& Data::add_day(int n)
{
    this->d+=n;
    return *this;
}

Data& Data::add_month(int n)
{
    this->m+=n;
    return *this;
}
#endif // MIOHEADER_H_INCLUDED
