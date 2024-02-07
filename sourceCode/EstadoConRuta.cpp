/**
 * @file EstadoConRuta.cpp
 * @author Fabián Orozco, Sofía Shum y Carolina Zamora.
 * @brief La Clase EstadoConRuta es una clase auxiliar del solucionador, se encarga de contener un estado su el camino por el cual se llega hasta él.
 * @version 1.0
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 */

#include "EstadoConRuta.h"

/**
 * @brief Método que invoca la sobrecarga de >> del 'estadoDerivado'.
 * @param entrada Recibe por referencia el flujo de entrada.
 * @return istream& Devuelve un flujo de entrada con lo que generó el método en su ejecución.
 */
istream& EstadoConRuta::cargar( istream& entrada ){
    entrada >> estado;
    return entrada;
}

/**
 * @brief Método que que invoca la sobrecarga de <<  del 'estadoDerivado' junto con algunos arreglos. 
 * @param salida Recibe por referencia el flujo de salida.
 * @return ostream& Devuelve un flujo de salida con lo que generó el método en su ejecución.
 */
ostream& EstadoConRuta::imprimir( ostream& salida ){
    salida << "Estado: " << estado << endl;
    salida << "Ruta:\n" << ruta;
    return salida;
}

/**
 * @brief Constructor con parámetros, se encarga de inicializar el 'estadoDerivado' realizando un clon con el metodo sobrecargado del método pasado por parámetro.
 * Además, inicializa la ruta creando una nueva por copia y añadiendo el 'estadoDerivado' propio.
 * @param estado Recibe un puntero a Estado con el estado que se quiere clonar y almacenar.
 * @param lista Recibe una lista por referencia, ésta debe contener el camino con los estados que se exploraron para llegar al 'estadoDerivado'.
 */
EstadoConRuta::EstadoConRuta( Estado * estado, Lista & lista ){
    this->estado = estado->clonar(); //metodo clonar del estado pasado por parametro
    ruta = new Lista(lista);
    ruta->push_back(this->estado);
}

/**
 * @brief Constructor de copia, se encarga de inicializar el EstadoConRuta propio con los atributos de otro pasado por parámetro
 * @param otro Recibe un EstadoConRuta por referencia, del cual se quieren clonar sus atributos.
 */
EstadoConRuta::EstadoConRuta( EstadoConRuta & otro ) {
    estado = (otro.estado)->clonar();
    ruta = new Lista(*otro.ruta);
}

/**
 * @brief Destructor, se encarga de liberar memoria.
 */
EstadoConRuta::~EstadoConRuta(){
    if(estado){
        delete estado;
    }
    if(ruta){
        delete ruta;
    }
}

/**
 * @brief Método que clona un EstadoConRuta.
 * @return EstadoConRuta* Devuelve un nuevo EstadoConRuta resultado del constructor de copia.
 */
EstadoConRuta * EstadoConRuta::clonar(){
    return new EstadoConRuta( *this );
}

/**
 * @brief Sobrecarga de operator ==. NO se utiliza. Se implementa por necesidad del polimorfismo (Clase Padre con virtual puro).
 * @return int Devuelve un 0;
 */
int EstadoConRuta::operator==( Estado * estado ){
    cerr << "EstadoConRuta: == comparacion falsa, no se debe utilizar" << endl;
    return 0;
}

/**
 * @brief Sobrecarga de operator !=. NO se utiliza. Se implementa por necesidad del polimorfismo (Clase Padre con virtual puro).
 * @return int Devuelve un 0;
 */
int EstadoConRuta::operator!=( Estado * estado ){
    cerr << "EstadoConRuta: != comparacion falsa, no se debe utilizar" << endl;
    return 0;
}

/**
 * @brief Método que retorna el atributo ruta del objeto.
 * @return Lista* Devuelve la ruta (lista de 'estadosDerivados').
 */
Lista* EstadoConRuta::getRuta(){
    return ruta;
}

/**
 * @brief Método que retorna el atributo estado del objeto.
 * @return Estado* Devuelve el estado ('estadoDerivado') clonado y almacenado.
 */
Estado * EstadoConRuta::getEstado(){
    return estado;
}