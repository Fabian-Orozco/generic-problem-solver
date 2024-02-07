#ifndef LIGHTSOUT_H
#define LIGHTSOUT_H

#include "Problema.h"
#include "GridLO.h"
#include <fstream>

/**
 * @brief Clase derivada de Problema, representa el problema LightsOut
 */
class LightsOut : public Problema{
    public:
        LightsOut();
        GridLO* getEstadoInicial();
        int esSolucion(Estado* e);
        int heuristica(Estado* e);
        Lista* getSiguientes(Estado* e);
    private:
};

#endif
