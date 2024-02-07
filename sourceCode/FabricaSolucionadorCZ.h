#ifndef FABRICASOLUCIONADORCZ_H
#define FABRICASOLUCIONADORCZ_H

#include "Fabrica.h"
#include "SolucionadorCarolina.h"

/**
 * @brief Clase derivada de Fabrica, para producir un puntero a SolucionadorCarolina
 */
class FabricaSolucionadorCZ : public Fabrica {
    public:
        SolucionadorCarolina* producir();
};

#endif
