#include "MatrixZ2.h"

using namespace std;

/*
 * Copia los contenidos del bool** que recibe sobre su atributo matrix
 */
void MatrixZ2::copy(bool** matrix){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            this->matrix[i][j] = matrix[i][j];
        }
    }
}

/*
 * Pide la memoria para la matriz
 */
void MatrixZ2::alloc(unsigned int rows, unsigned int columns){
    matrix = new bool*[rows];
    for(int i = 0; i < rows; ++i){
        matrix[i] = new bool[columns];
    }
}

/*
 * Libera la memoria ocupada por la matriz
 */
void MatrixZ2::free(){
    for(int i = 0; i < rows; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
}

/*
 * Asigna a todas las entradas de la matriz el valor que recibe
 */
void MatrixZ2::fill(bool value){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            matrix[i][j] = value;
        }
    }
}

/**
 * @brief Pasa los contenidos de la matriz a un ostream
 * @param out Ostream donde se imprime
 * @return Ostream modificado
 */
std::ostream& MatrixZ2::imprimir(std::ostream& out){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            out << matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

/**
 * @brief Carga los contenidos de la matriz desde un istream
 * @param in Istream de donde se carga
 * @return Istream modificado
 */
std::istream& MatrixZ2::cargar(std::istream& in){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            if(!in.eof()){
                in >> matrix[i][j];
            }
        }
    }
    return in;
}

/**
 * @brief Constructor por omisión
 * 
 * Crea una matriz 1x1 con entradas 0
 */
MatrixZ2::MatrixZ2(){
    rows = 1;
    columns = 1;
    alloc(rows, columns);
    fill(0);
}

/**
 * @brief Constructor por dimensiones (rectangular)
 * 
 * Crea una matriz rowsxcolumns con entradas 0
 * @param rows Cantidad de filas
 * @param columns Cantidad de columnas
 */
MatrixZ2::MatrixZ2(unsigned int rows, unsigned int columns)
    :rows(rows), columns(columns)
{
    alloc(rows, columns);
    fill(0);
}

/**
 * @brief Constructor por dimensiones (cuadrada)
 * 
 * Crea una matriz rowsColumnsxrowsColumns con entradas 0
 * @param rowsColumns Cantidad de filas y de columnas
 */
MatrixZ2::MatrixZ2(unsigned int rowsColumns)
    :rows(rowsColumns), columns(rowsColumns)
{
    alloc(rows, columns);
    fill(0);
}

/**
 * @brief Constructor de copia
 * @param matrix Matriz que va a copiar
 */
MatrixZ2::MatrixZ2(const MatrixZ2& matrix){
    rows = matrix.rows;
    columns = matrix.columns;
    alloc(rows, columns);
    copy(matrix.matrix);
}

/**
 * Destructor (libera la memoria ocupada por la matriz)
 */
MatrixZ2::~MatrixZ2(){
    free();
}

/**
 * @brief Suma de dos matrices
 * @param matrix Matriz que se va a sumar con this
 * @return Matriz del resultado de la suma
 */
MatrixZ2 MatrixZ2::operator+(MatrixZ2& matrix){
    MatrixZ2 result;
    if(rows == matrix.rows && columns == matrix.columns){
        MatrixZ2 sum(rows, columns);
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < columns; ++j){
                sum.matrix[i][j] = this->matrix[i][j] ^ matrix.matrix[i][j];
            }
        }
        result = sum;
    }
    return result;
}

/**
 * @brief Determina si dos matrices son iguales
 * @param matriz Matriz a comparar con this
 * @return True solo si todas las entradas respectivas son iguales
 */
int MatrixZ2::operator==(MatrixZ2& matrix){
    bool isEqual = rows == matrix.rows && columns == matrix.columns;
    if(isEqual){
        for(int i = 0; i < rows && isEqual; ++i){
            for(int j = 0; j < columns && isEqual; ++j){
                isEqual = this->matrix[i][j] == matrix.matrix[i][j];
            }
        }
    }
    return isEqual;
}

/**
 * @brief Determina si todas las entradas son el valor que recibe
 * @param b Bool contra el cual compara cada entrada de la matriz
 * @return True solo si todas las entradas son iguales a b
 */
int MatrixZ2::operator==(bool b){
    MatrixZ2 m(rows, columns);
    m.fill(b);
    return *this==m;
}

/**
 * @brief Determina si dos matrices son diferentes
 * @param matriz Matriz a comparar con this
 * @return False solo si todas las entradas respectivas son iguales
 */
int MatrixZ2::operator!=(MatrixZ2& matrix){
    return !(*this==matrix);
}

/**
 * @brief Operador de asignación con un valor
 * @param value Bool que se va a asignar a todas las entradas (mantiene la misma dimensión)
 */
void MatrixZ2::operator=(bool value){
    fill(value);
}

/**
 * @brief Operador de asignación con otra matriz
 * @param matriz Matriz que se va a copiar y asignar a this
 */
void MatrixZ2::operator=(MatrixZ2& matrix){
    free();
    rows = matrix.rows;
    columns = matrix.columns;
    alloc(rows, columns);
    copy(matrix.matrix);
}

/**
 * @brief Rellena la matriz con valores aleatorios
 */
void MatrixZ2::randomize(){
    srand(time(0));
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            matrix[i][j] = rand() % 2;
        }
    }
}

/**
 * @brief Retorna cantidad de columnas
 * @return Cantidad de columnas (int)
 */
int MatrixZ2::getColumns(){
    return columns;
}

/**
 * @brief Retorna cantidad de filas
 * @return Cantidad de filas (int)
 */
int MatrixZ2::getRows(){
    return rows;
}

/**
 * @brief Permite acceder a una fila (para leer o modificar)
 * @param n Número de fila
 * @return Puntero a bool correspondiente a la fila n de la matriz
 */
bool* MatrixZ2::operator[](int n){
    return matrix[n];
}
