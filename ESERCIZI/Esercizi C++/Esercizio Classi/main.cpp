#include "mioheader.h";

int main()
{
    int n,n1;
    Data D1(1, 3, 1999);
    D1.get_date();

    cout<<"\nQuanti giorni vuoi aggiungere alla data?"<<endl;
    cin>>n;

    cout<<"\nQuanti mesi vuoi aggiungere alla data?"<<endl;
    cin>>n1;

    D1.add_day(n).add_month(n1);
    D1.~Data();
    D1.get_date();
}
