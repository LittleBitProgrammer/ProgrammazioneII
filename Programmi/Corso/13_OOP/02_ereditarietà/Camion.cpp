#include <iostream>
#include "Camion.hpp"

/* iostrem */
using std::cout;
using std::endl;

void Camion::set_peso(int peso_rimorchio)
{
    this->peso_rimorchio = peso_rimorchio;
}

int Camion::get_peso(){
    return this->peso_rimorchio;
}

Camion::Camion(){}

Camion::Camion(int num_ruote, int num_passeggeri, int peso_rimorchio) : Veicolo(num_ruote, num_passeggeri)
{
    this->peso_rimorchio = peso_rimorchio;
}

Camion::Camion(const Camion &camion) : Veicolo(camion)
{
    this->peso_rimorchio = camion.peso_rimorchio;
}

Camion::~Camion(){}

void Camion::show()
{
    cout << "passeggeri: " << get_pass() << "\truote: " << get_ruote() << "\tpeso: " << this->peso_rimorchio << endl;
}