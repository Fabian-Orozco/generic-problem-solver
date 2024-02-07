/**
 * @file State03021_BS.cpp
 * @author Fabián Orozco, Sofía Shum y Carolina Zamora.
 * @brief La Clase State03021_BS representa un posible estado o posición de una matriz enfocada en Ball Sort
 * @version 1.0
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 */

#include "State03021_BS.h" 

/**
 * @brief Método que invoca la sobrecarga de >> de la matriz.
 * @param entrada Recibe por referencia el flujo de entrada.
 * @return istream& Devuelve un flujo de entrada con lo que generó el método en su ejecución.
 */
istream& State03021_BS::cargar( istream& entrada ){
    entrada >> *matrizEstado;
    return entrada;
}

/**
 * @brief Método que que invoca la sobrecarga de << de la matriz.
 * @param salida Recibe por referencia el flujo de salida.
 * @return ostream& Devuelve un flujo de salida con lo que generó el método en su ejecución.
 */
ostream& State03021_BS::imprimir( ostream& salida ){
    salida << *matrizEstado;
    return salida;
}

/**
 * @brief Constructor por omisión, inicializa puntero a matriz con una instancia nueva de Matriz03021_BS
 */
State03021_BS::State03021_BS(){
    matrizEstado = 0;
    matrizEstado = new Matriz03021_BS();
}

/**
 * @brief Constructor de copia, inicializa puntero a matriz con una instancia nueva de Matriz03021_BS clonada con la que pasan por referencia en parámetro.
 * @param otra Recibe un objeto Matriz03021_BS por referencia.
 */
State03021_BS::State03021_BS( Matriz03021_BS & otra ){
    matrizEstado = 0;
    matrizEstado = new Matriz03021_BS(otra);
}

/**
 * @brief Destructor, se encarga de la liberación de la memoria.
 */
State03021_BS::~State03021_BS(){
    delete matrizEstado;
    matrizEstado = 0;
}

/**
 * @brief Método que invoca al constructor de copia del estado con la matriz propia y retorna su resultado
 * @return State03021_BS* Devuelve un nuevo objeto tipo State03021_BS creado con las carácteristicas del estado propio.
 */
State03021_BS * State03021_BS::clonar(){
    return  new State03021_BS( *matrizEstado );
}

/**
 * @brief Sobrecarga del operador ==, realiza un dynamic casting para realizar la verificación de igualdad entre las matrices.
 * @param estado Recibe un puntero a Estado con el que se quiere comparar.
 * @return int Devuelve 0 si al menos una de las entradas de la matriz es distinta; de manera contraria retorna 1.
 */
int State03021_BS::operator==( Estado * estado ){
    State03021_BS * stateBSPtr = dynamic_cast <State03021_BS *> (estado);
    if(stateBSPtr){
        return (*matrizEstado)==(*stateBSPtr->matrizEstado);
    }
    else{
        return 0;
    }
}

/**
 * @brief Sobrecarga del operador !=, invoca la sobrecarga de == y la retorna su negación.
 * @param estado Recibe un puntero a Estado con el que se quiere comparar.
 * @return int Devuelve 1 si al menos una de las entradas de la matriz es distinta; de manera contraria retorna 0.
 */
int State03021_BS::operator!=( Estado * estado ){
    return !(*this==estado);
}