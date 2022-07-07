#ifndef _AUTOMOBILE_HPP_
#define _AUTOMOBILE_HPP_

#include "Veicolo.hpp"

typedef enum {utilitaria, berlina, suv} type_info;

class Automobile : public Veicolo
{
    private:
        type_info tipo_auto;

    public:
        /* Setter */
        void set_tipo(type_info tipo_auto);

        /* Getter */
        type_info get_tipo();

        /* Constructor */
        Automobile(int num_ruote, int num_passeggeri, type_info tipo_auto);
        Automobile();
        Automobile(const Automobile &automobile);

        /* Destructor */
        ~Automobile();

        /* Show */
        void show();
};

#endif 