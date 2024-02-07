/**
 * @file Solver03021Factory.cpp
 * @author Fabián Orozco, Sofía Shum y Carolina Zamora.
 * @brief La Clase Solver03021Factory representa una fabrica que produce solucionadores.
 * @version 1.0
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 */
#include "Solver03021Factory.h" 

/**
 * @brief Método que "produce"/crea y retorna una instancia de tipo Solver03021 (solucionador).
 * @return Solver03021* Devuelve una instancia de tipo Solver03021.
 */
Solver03021 * Solver03021Factory::producir(){
    return new Solver03021();
}

Solver03021Factory::~Solver03021Factory(){

}
