#include <iostream>
#include "Automobile.hpp"

/* iostrem */
using std::cout;
using std::endl;

void Automobile::set_tipo(type_info tipo_auto)
{
    this->tipo_auto = tipo_auto;
}

type_info Automobile::get_tipo(){
    return this->tipo_auto;
}

Automobile::Automobile(int num_ruote, int num_passeggeri, type_info tipo_auto) : Veicolo(num_ruote, num_passeggeri)
{
    this->tipo_auto = tipo_auto;
}

Automobile::Automobile(){}

Automobile::~Automobile(){}

Automobile::Automobile(const Automobile &automobile) : Veicolo(automobile)
{
    this->tipo_auto = automobile.tipo_auto;
}

void Automobile::show()
{
    cout << "passeggeri: " << get_pass() << "\truote: " << get_ruote() << "\ttipo: ";

    switch (this->tipo_auto)
    {
    case utilitaria:
        cout << "utilitaria";
        break;
    case berlina:
        cout << "berlina";
        break;
    case suv:
        cout << "suv";
        break;

    default:
        break;
    }

    cout << endl;
}