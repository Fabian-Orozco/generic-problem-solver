/**
 * 
 * @file Matriz03021_BS.cpp
 * @author Fabián Orozco, Sofía Shum y Carolina Zamora.
 * @brief La Clase Matriz03021_BS representa una matriz con tamaño fijo de entradas tipo char. Posee métodos con enfoques propios al problema de Ball Sort
 * @version 1.0
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <random>
#include <cstdlib>
#include <time.h>

#include "Matriz03021_BS.h"

/**
 * @brief Método que reserva memoria para cada entrada de la matriz. 
 * Crea de forma dinámica un vector de punteros que representa la cantidad de filas de la matriz, los recorre y pide memoria para cada una de las columnas.
 */
void Matriz03021_BS::pedirMemoria(){
    matriz = new char *[FILASBS];  
    for (int f = 0; f < FILASBS; ++f){
        matriz[f] = new char[COLUMNASBS];
    }       
}

/** 
 * @brief Método que libera la memoria de cada uno de los punteros del vector de punteros (columnas) de la matriz; además de liberar la memoria del puntero principal al vector de punteros (filas)
 */
void Matriz03021_BS::liberarMemoria(){
    for (int f = FILASBS - 1; f >= 0; --f){
        delete[] matriz[f];
    }
    delete[] matriz;
    matriz = 0;
}

/**
 * @brief Método que inicializa todas las entradas de la matriz con un punto.
 */
void Matriz03021_BS::rellenar(){
    for(int f = 0; f < FILASBS; ++f){
        for(int c = 0; c < COLUMNASBS; ++c){
            matriz[f][c] = '.';
        }
    }
}

/**
 * @brief Método que copia las entradas y el descenso de una matriz pasada por parámetro a la propia matriz.
 * @param otra Recibe una matriz por referencia de la cual se copiarán sus entradas y el descenso.
 */
void Matriz03021_BS::copiar( Matriz03021_BS & otra){
    for (int f = 0; f < FILASBS; ++f){
        for (int c = 0; c < COLUMNASBS; ++c){
            matriz[f][c] = otra.matriz[f][c];
        }
    }

    for (int c = 0; c < COLUMNASBS; ++c){
            descenso[c] = otra.descenso[c];
    }
}

/**
 * @brief Método que modulariza la inicialización de la matriz. Invoca para pedir memoria, rellenar de forma correcta la matriz.
 */
void Matriz03021_BS::_init(){
    pedirMemoria();
    rellenar();
    randomize();
}

/**
 * @brief Método que se encarga de generar la salida para el método amigo sobrecargado de operator <<. Recorre la matriz he imprime sus entradas con algunos arreglos.
 * @param salida Recibe por referencia el flujo de salida.
 * @return ostream& Devuelve un flujo de salida con lo que generó el método en su ejecución.
 */
ostream& Matriz03021_BS::imprimir( ostream& salida ){
    for (int f = 0; f < FILASBS; ++f){
        for (int c = 0; c < COLUMNASBS; ++c){
            if(f == 3){
                salida << "|_" << matriz[f][c] << "_|  ";
            }
            else{
                salida << "| " << matriz[f][c] << " |  ";
            }
        }
        salida << endl;
    }
    return salida;
}

/**
 * @brief Método que se encarga de asignar el valor a cada elemento de la matriz según la entrada pasada por referencia en parámetro.
 * @param entrada Recibe por referencia el flujo de entrada.
 * @return istream& Devuelve un flujo de entrada con lo que generó el método en su ejecución.
 */
istream& Matriz03021_BS::cargar( istream& entrada ){
    for (int f = 0; f < FILASBS; ++f){
        for (int c = 0; c < COLUMNASBS; ++c){
            entrada >> matriz[f][c];
        }
    }
    return entrada;
}

/**
 * @brief Constructor por omisión, invoca al método _init() que inicializa la creación de la matriz.
 */
Matriz03021_BS::Matriz03021_BS(){
    _init();
}

/**
 * @brief Constructor de copia, invoca métodos que se encargan de reservar memoria y copiar las entradas de la matriz así como su vector descenso;
 * @param otra Recibe un objeto Matriz03021_BS por referencia.
 */
Matriz03021_BS::Matriz03021_BS(Matriz03021_BS & otra){
    pedirMemoria();
    copiar(otra);
}

/**
 * @brief Destructor, invoca a un método que se encarga de la liberación de la memoria.
 */
Matriz03021_BS::~Matriz03021_BS(){
    liberarMemoria();
}

/**
 * @brief Sobrecarga del operador ==, realiza una comparación entrada por entrada de la matriz.
 * @param otra Recibe un objeto Matriz03021_BS por referencia.
 * @return int Devuelve 0 si al menos una de las entradas es distinta; de manera contraria retorna 1.
 */
int Matriz03021_BS::operator==(Matriz03021_BS & otra){
    int esIgual = 1;
    for(int f = 0; f < FILASBS && esIgual; ++f){
        for(int c = 0; c < COLUMNASBS && esIgual; ++c){
            esIgual = (this->matriz[f][c] == otra.matriz[f][c]);
        }
    }
    return esIgual;
}
/**
 * @brief Sobrecarga del operador !=, realiza una comparación entrada por entrada de la matriz.
 * @param otra Recibe un objeto Matriz03021_BS por referencia.
 * @return int Devuelve 1 si al menos una de las entradas es distinta; de manera contraria retorna 0.
 */
int Matriz03021_BS::operator!=( Matriz03021_BS & otra ){
    return !(*this==otra);
}

/**
 * @brief Sobrecarga del operador =, invoca a otros métodos que se encargan de asignar una matriz pasada por referencia en parámetro a la propia matriz.
 * @param otra Recibe un objeto Matriz03021_BS por referencia.
 */
void Matriz03021_BS::operator=( Matriz03021_BS & otra ){
    liberarMemoria();
    pedirMemoria();
    copiar(otra);
}

/**
 * @brief Metodo que se encarga de randomizar las primeras cuatro columnas de la matriz.
 * Utiliza el método rand() que genera valores de 0 a 4, además del método srand() y time() que se encargan de crear la semilla aleatoria en tiempo de ejecución.
 * La generación de número aleatorio permite elegir entra los indices del vector Colores(atributo de Matriz03021_BS) para ser asignados si estos tienen menos de 4 apariciones en la matriz.
 */
void Matriz03021_BS::randomize(){
    srand(time(0));
    int repeticiones[4] = {0,0,0,0};
    for(int f=0; f < FILASBS; ++f){
        for(int c=0; c < 4; ++c){
            
            int relleno = 0;
            while(!relleno){
                int eleccion = rand() % 4 + 0;
                ++repeticiones[eleccion];
                if(repeticiones[eleccion] <= 4){
                    ++relleno;
                    matriz[f][c] = colores[eleccion];
                }
            }
        }
    }
}

/**
 * @brief Metodo que cuenta la cantidad de apariciones máxima de un caracter en una columna.
 * @param columna Recibe el subindice de la columna que se desea saber la cantidad de apariciones máxima de un caracter.
 * @return int Devuelve un entero que representa la cantidad de apariciones máxima de un caracter.
 */
int Matriz03021_BS::contarMaxColumna( int columna ){
    int repeticiones[5] = {0,0,0,0,0};
    for (int f=0; f < FILASBS; ++f){
        switch(matriz[f][columna]){
            case 'R':
            ++repeticiones[0];
            break;
            case 'G':
            ++repeticiones[1];
            break;
            case 'B':
            ++repeticiones[2];
            break;
            case 'Y':
            ++repeticiones[3];
            break;
            case '.':
            ++repeticiones[4];
            break;
        }
    }
    int max = repeticiones[0];
    for(int i=0; i <= FILASBS; ++i){
        if(repeticiones[i] > max){
            max = repeticiones[i];
        }
    }
    return max;
}

/**
 * @brief Metodo que cuenta la cantidad mínima de ordenaciones que se tienen que dar para que la matriz esté ordenada.
 * @return int Devuelve un entero que representa la cantidad mínima de ordenaciones que se tienen que dar para que la matriz esté ordenada.
 */
int Matriz03021_BS::contarMovimientosRestantes(){
    int cantidadMax = FILASBS*COLUMNASBS;
    for(int i=0; i < COLUMNASBS; ++i){
        cantidadMax -= contarMaxColumna(i);
    }
    return cantidadMax;
}

/**
 * @brief Metodo que verifica si la matriz está ordenada completamente (solucionada) o no.
 * @return int Devuelve un entero distinto a 0 si la matriz está completamente ordenada; en caso contrario retorna 0;
 */
int Matriz03021_BS::solucionado(){
    return !contarMovimientosRestantes();
}

/**
 * @brief Metodo que calcula la heurística optimista según el contenido de la matriz.
 * @return int Devuelve un entero con la cantidad aproximada de movimientos mínimos que se deben realizar para llegar a la solución.
 */
int Matriz03021_BS::heuristica(){
    return contarMovimientosRestantes()/2;
}

/**
 * @brief Metodo que verifica la validez de un movimiento para saber si puede realizarse. Se trabaja con el elemento que está más arriba (de fila 0 a fila 3) de cada columna de acuerdo al vector descensos[].
 * @param columnaOrigen Recibe el número de la columna de la que se quiere mover el elemento.
 * @param columnaDestino Recibe el entero que representa la columna en la que se quiere colocar el elemento.
 * @return int Devuelve un entero distinto de 0 si el movimiento es válido; de forma contraria, retorna 0.
 */
int Matriz03021_BS::movimientoValido( int columnaOrigen, int columnaDestino ){
    int esValido = 1;
    int modificaDescenso = 0;

    //la columnaOrigen tiene al menos un color (descenso es != 4) entonces sí puede mover.
    //la columnaDestino no está llena (descenso es != 0) entonces sí puede colocar.
    esValido = ( (descenso[columnaOrigen] != 4) && (descenso[columnaDestino] != 0) );

    //compara por colores
    if(esValido){

        if(descenso[columnaDestino] == 4){ //evita error de segmentacion en caso de que la columnaDestino sea 4 (no existe fila 4).
            --descenso[columnaDestino];
            ++modificaDescenso; //variable que ayuda a controlar si realicé un cambio que luego se debe revertir.
        }

        char topeOrigen = matriz[ descenso[ columnaOrigen ] ] [ columnaOrigen ];
        char topeDestino = matriz[ descenso[ columnaDestino ] ] [ columnaDestino];

        esValido = ( topeOrigen == topeDestino || topeDestino == '.' ); //tienen el mismo color o donde coloco está vacío.
        
        if(modificaDescenso)
            ++descenso[columnaDestino];
    }
    return esValido;
}

/**
 * @brief Método que realiza el movimiento de una de un caracter de una columna hacia otra dependiendo si es válido o no.
 * @param columnaOrigen Recibe el número de la columna de la que se quiere mover el elemento.
 * @param columnaDestino Recibe el entero que representa la columna en la que se quiere colocar el elemento.
 * @return Matriz03021_BS Devuelve un tipo Matriz03021_BS por referencia (se devuelve así misma), con los cambios realizados o no.
 */
Matriz03021_BS& Matriz03021_BS::mover( int columnaOrigen ,int columnaDestino ){
    if(movimientoValido( columnaOrigen , columnaDestino )){
        matriz[ --descenso[ columnaDestino ] ] [ columnaDestino] = matriz[ descenso[ columnaOrigen ] ] [ columnaOrigen ];
        matriz[ descenso[ columnaOrigen ] ] [ columnaOrigen ] = '.';
        ++descenso[ columnaOrigen ];
    }
    return *this;
}