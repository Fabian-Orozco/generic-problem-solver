/**
 * @file Problem03021Factory.cpp
 * @author Fabián Orozco, Sofía Shum y Carolina Zamora.
 * @brief La Clase Problem03021Factory representa una fabrica que produce problemas de Ball Sort
 * @version 1.0
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 */

#include "Problem03021Factory.h"

/**
 * @brief Método que "produce"/crea y retorna una instancia de tipo Problem03021_BS (problema).
 * @return Problem03021_BS* Devuelve una instancia de tipo Problem03021_BS.
 */
Problem03021_BS * Problem03021Factory::producir(){
    return new Problem03021_BS();
}

Problem03021Factory::~Problem03021Factory(){
    
}