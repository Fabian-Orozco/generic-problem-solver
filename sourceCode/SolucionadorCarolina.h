#ifndef SOLUCIONADORCAROLINA_H
#define SOLUCIONADORCAROLINA_H

#include "Problema.h"
#include "Solucionador.h"

/**
 * @brief Solucionador de Carolina, derivado de Solucionador
 */
class SolucionadorCarolina : public Solucionador{
    public:
        Solucion* solucione(Problema* problem);

    private:
		/*
		 * Agrega e a la Lista si no estaba antes:
		 * set U {e}
		 */
        void setAdd(Lista& set, Estado* e);
        /*
         * Resuelve el problema (problem), escribiendo la solución en sol
         * a partir del estado inicial (initial)
         */
        void solve(Problema* problem, Estado* initial, Lista* sol);
        /*
         * Resuelve recursivamente el problema (problem), escribiendo rutas en
         * sol, agrega cada estado visitado en visited. Analiza la solución
         * obtenida de agregar el estado actual (e) al final de sol
         */
        bool solveR(Problema* problem, Estado* e, Lista* sol, Lista& visited);
        /*
         * Retorna la resta de conjuntos set \ excluded en una Lista
         */
        Lista* difference(Lista& set, Lista& excluded);
        /*
         * Ordena la lista de menor a mayor heurística determinada por el problema
         */
        void arrange(Problema* problem, Lista* list);
};

#endif
