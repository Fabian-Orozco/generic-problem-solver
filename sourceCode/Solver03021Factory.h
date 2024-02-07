#ifndef SOLVER03021Factory
#define SOLVER03021Factory

#include "Fabrica.h"
#include "Solver03021.h"

class Solver03021Factory : public Fabrica {
   
    public:
    
        ~Solver03021Factory();
        Solver03021 * producir();

};

#endif
