/**
 * @file Problem03021_BS.cpp
 * @author Fabián Orozco, Sofía Shum y Carolina Zamora.
 * @brief La Clase Problem03021_BS representa en general el juego de Ball Sort, administra las opciones de éste mediante la clase State03021_BS.
 * @version 1.0
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 */

#include "Problem03021_BS.h" 

/**
 * @brief Constructor por omisión, inicializa puntero a State03021_BS con una instancia nueva de State03021_BS
 */
Problem03021_BS::Problem03021_BS(){
    estadoInicial = 0;
    estadoInicial = new State03021_BS();
}

/**
 * @brief Método que retorna el estado contenido en el problema como atributo.
 * @return Estado* Devuelve el atributo estadoInicial del problema.
 */
Estado * Problem03021_BS::getEstadoInicial(){
    return estadoInicial;
}

/**
 * @brief Método que verifica si un estado del problema es solución.
 * @param estado Recibe un puntero a Estado con el estado del que se quiere saber si está o no solucionado.
 * @return int Devuelve un 1 si la matriz del estado está completamente ordenada, en caso contrario, retorna 0.
 */
int Problem03021_BS::esSolucion( Estado * estado ){
    State03021_BS * stateBSPtr = dynamic_cast <State03021_BS *> (estado);
    if(stateBSPtr){
        return stateBSPtr->matrizEstado->solucionado();
    }
    return 0;
}

/**
 * @brief Método que verifica la heurística de un estado del problema.
 * @param estado Recibe un puntero a Estado con el estado del que se quiere saber su heurística.
 * @return int Devuelve un entero que representa la cantidad de ordenaciones mínimas que se deben realizar.
 */
int Problem03021_BS::heuristica( Estado * estado ){
    State03021_BS * stateBSPtr = dynamic_cast <State03021_BS *> (estado);
    if(stateBSPtr){
        return stateBSPtr->matrizEstado->heuristica();
    }
    return 0;
}

/**
 * @brief Método que verifica y retorna los siguientes estados posibles de un estado en particular contenidos en una lista.
 * @param estado Recibe un puntero a Estado con el estado del que se quieren saber sus estados siguientes.
 * @return Lista* Devuelve un puntero a Lista que contiene los estados siguientes al actual.
 */
Lista * Problem03021_BS::getSiguientes( Estado * estado ){
    State03021_BS * stateBSPtr = dynamic_cast <State03021_BS *> (estado);
    if(stateBSPtr){
        Lista * siguientes = new Lista();
        for(int columnaOrigen = 0; columnaOrigen <= 5; ++columnaOrigen){
            for(int columnaDestino = 0; columnaDestino <= 5; ++columnaDestino){
                if(stateBSPtr->matrizEstado->movimientoValido( columnaOrigen , columnaDestino ) ){
                    State03021_BS * clon = stateBSPtr->clonar();
                    clon->matrizEstado->mover(columnaOrigen, columnaDestino);
                    siguientes->push_back( clon );
                }
            }
        }
        return siguientes;
    }
    return 0;
}