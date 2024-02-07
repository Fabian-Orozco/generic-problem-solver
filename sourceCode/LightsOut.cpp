
#include "LightsOut.h"

using namespace std;

/**
 * @brief Constructor por omisión
 */
LightsOut::LightsOut(){

}

/**
 * @brief Obtiene el estado inicial de GridLO
 * @return Puntero a GridLO inicial
 */
GridLO* LightsOut::getEstadoInicial(){
    GridLO* initial = new GridLO();
    ifstream file("GridLightsOut.txt");
    if(file){
        file >> initial;
        if(!initial->wasLoaded){
            delete initial;
            initial = 0;
        }
    }
    else{
        cout << "No se ha podido encontrar el archivo \"GridLightsOut.txt\"" << endl;
        delete initial;
        initial = 0;
    }
    if(!initial){
        cout << "Se genera aleatoriamente un problema de LightsOut:\n";
        initial = new GridLO();
        initial->grid.randomize();
    }
    return initial;
}

/**
 * @brief Determina si un estado es solución
 * @param e Puntero a Estado
 * @return True solo si e apunta a un GridLO y el grid está todo apagado
 */
int LightsOut::esSolucion(Estado* e){
    GridLO* grid = dynamic_cast<GridLO*>(e);
    int ret = 0;
    if(grid){
        ret = (*grid).grid==0;
    }
    return ret;
}

/**
 * @brief Determina la heurística de un estado
 * @param e Puntero a Estado
 * @return Valor de la heurística (cantidad de luces encendidas en el GridLO)
 */
int LightsOut::heuristica(Estado* e){
    GridLO* grid = dynamic_cast<GridLO*>(e);
    int diff = 0;
    if(grid){
        MatrixZ2 g = grid->grid;
        for(int i = 0; i < g.getRows(); ++i){
            for(int j = 0; j < g.getColumns(); ++j){
                diff += g[i][j];
            }
        }
    }
    return diff;
}

/**
 * @brief Obtiene los siguientes estados de un estado
 * @param e Puntero a Estado
 * @return Puntero a Lista que contiene los estados siguientes a *e
 */
Lista* LightsOut::getSiguientes(Estado* e){
    GridLO* grid = dynamic_cast<GridLO*>(e);
    Lista* next = new Lista();
    if(grid){
        MatrixZ2 g = grid->grid;
        for(int i = 0; i < g.getRows(); ++i){
            for(int j = 0; j < g.getColumns(); ++j){
                GridLO flip(grid->flip(i, j));
                next->push_back(&flip);
            }
        }
    }
    return next;
}
