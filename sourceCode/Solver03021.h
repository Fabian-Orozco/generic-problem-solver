#ifndef SOLVER03021
#define SOLVER03021

#include "Solucionador.h"
#include "Problem03021_BS.h" 
#include "EstadoConRuta.h"
#include "Solucion.h"

class Solver03021 : public Solucionador {

    private:

        void busqueSolucion(Lista *, Lista *, Lista *, Estado *, Problema *);

    public:
        
        Solucion * solucione( Problema * );
        void ordenarLista( Lista * , Problema * );
        
};

#endif
