#ifndef GRIDLO_H
#define GRIDLO_H

#define STREAMSIZE_LO 32
#define GRIDSIZE_LO 4

#include <iostream>
#include <string.h>
#include "Estado.h"
#include "MatrixZ2.h"
#include "Separador.h"

/**
 * @brief Clase derivada de Estado, representa una cuadrícula (grid) del problema LightsOut
 */
class GridLO : public Estado {
    friend class LightsOut;
    private:
		/*
		 * MatrixZ2 que representa el grid
		 */
        MatrixZ2 grid;
        /*
         * Indica si fue cargada desde un istream
         */
        bool wasLoaded;
        /*
         * Determina si es una posición válida en grid
         */
        bool isValidPosition(unsigned int row, unsigned int column);
        /*
         * Determina si es el estado inicial
         */
        bool initial;
        /*
         * Número de fila que ha sido elegida para hacer switch (o flip)
         */
        unsigned int flipRow;
        /*
         * Número de columna que ha sido elegida para hacer switch (o flip)
         */
        unsigned int flipColumn;
    public:
        GridLO();
        GridLO(const GridLO& grid);
        ~GridLO();
        GridLO * clonar();
        std::istream& cargar(std::istream& in);
        std::ostream& imprimir(std::ostream& out);
        int operator==(Estado* e);
        int operator!=(Estado* e);
        GridLO flip(unsigned int row, unsigned int column);
};

#endif
