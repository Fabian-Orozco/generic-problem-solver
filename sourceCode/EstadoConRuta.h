#ifndef ESTADOCONRUTA_03021
#define ESTADOCONRUTA_03021

#include "Estado.h"
#include "Lista.h"

class EstadoConRuta : public Estado{
    private:

        Estado * estado;
        Lista * ruta;

        istream& cargar( istream& );
        ostream& imprimir( ostream& );

    public:

        EstadoConRuta( Estado *, Lista & );
        EstadoConRuta( EstadoConRuta & );
        ~EstadoConRuta();

        EstadoConRuta * clonar();
        int operator==( Estado * );
        int operator!=( Estado * );

        Lista * getRuta();
        Estado * getEstado();

};

#endif