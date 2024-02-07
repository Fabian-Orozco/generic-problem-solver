#ifndef MATRIZ03021_BS
#define MATRIZ03021_BS

#include <iostream>
using namespace std;

#define FILASBS 4
#define COLUMNASBS 6

class Matriz03021_BS {
    
    friend ostream& operator<<(ostream & salida, Matriz03021_BS & matriz){
        return matriz.imprimir(salida);
    }
    friend istream& operator>>(istream & entrada, Matriz03021_BS & matriz){
        return matriz.cargar(entrada);
    }

     private:

        char ** matriz;
        char colores[FILASBS+2] =  {'R','G','B','Y','.','\0'};
        int descenso[COLUMNASBS] = {0,0,0,0,4,4}; //contiene el valor de la cantidad (0,1,2,3,4) de descensos que hay que hacer para llegar a la bola que está más alta.

        void pedirMemoria();
        void liberarMemoria();
        void rellenar();
        void copiar( Matriz03021_BS & );
        void _init();

        ostream& imprimir( ostream & );
        istream& cargar( istream & );


    
    public:

        Matriz03021_BS(); //siempre por omisión (mismo tamaño)
        Matriz03021_BS( Matriz03021_BS & ); //constructor de copia para los cambios
        ~Matriz03021_BS();

        int operator==( Matriz03021_BS & );
        int operator!=( Matriz03021_BS & );
        void operator=( Matriz03021_BS & );
        void randomize();

        int contarMovimientosRestantes();
        int contarMaxColumna( int ); //retorna la maxima cantidad de colores en una columna (también cuentan los '.')
        int solucionado(); //realiza un calculo para saber si el problema está solucionado
        int heuristica(); //retorna la cantidad mínima de movimientos necesarios para llegar a la solución

        int movimientoValido( int,int );
        Matriz03021_BS& mover( int,int );
};

#endif