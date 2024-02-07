#ifndef MATRIXZ2_H
#define MATRIXZ2_H

#include <iostream>
#include <istream>
#include <ostream>
#include <random>
#include <time.h>

/**
 * @brief Esta clase representa una matriz con entradas en el cuerpo Z2 (F2)
 */
class MatrixZ2{
    private:
		/*
		 * Elementos de la matriz
		 */
        bool** matrix;
        /*
         * Número de filas de la matriz
         */
        unsigned int rows;
        /*
         * Número de columnas de la matriz
         */
        unsigned int columns;
        /*
         * Copia los contenidos del bool** que recibe sobre su atributo matrix
         */
        void copy(bool** matrix);
        /*
         * Pide la memoria para la matriz
         */
        void alloc(unsigned int rows, unsigned int columns);
        /*
         * Libera la memoria ocupada por la matriz
         */
        void free();
        /*
         * Asigna a todas las entradas de la matriz el valor que recibe
         */
        void fill(bool value);

    public:
		MatrixZ2();        
        MatrixZ2(unsigned int rows, unsigned int columns);        
        MatrixZ2(unsigned int rowsColumns);        
        MatrixZ2(const MatrixZ2& matrix);        
        ~MatrixZ2();		
        MatrixZ2 operator+(MatrixZ2& matrix);        
        int operator==(MatrixZ2& matrix);
        int operator==(bool b);
        int operator!=(MatrixZ2& matrix);
        void operator=(MatrixZ2& matrix);
        void operator=(bool value);
        void randomize();
        int getRows();
        int getColumns();
        bool* operator[](int n);
        std::ostream& imprimir(std::ostream& out);
        std::istream& cargar(std::istream& in);
};

#endif
