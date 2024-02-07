#include "GridLO.h"
#include "MatrixZ2.h"
#include "Separador.h"

using namespace std;

/**
 * @brief Constructor por omisión
 * 
 * Se crea grid de 4x4
 */
GridLO::GridLO()
    : grid(GRIDSIZE_LO)
{
    wasLoaded = false;
    initial = true;
}

/**
 * @brief Constructor por copia
 * @param grid GridLO que se copia
 */
GridLO::GridLO(const GridLO& grid)
    : grid(grid.grid), initial(grid.initial), flipColumn(grid.flipColumn), flipRow(grid.flipRow), wasLoaded(grid.wasLoaded)
{
    
}

/**
 * @brief Destructor
 */
GridLO::~GridLO(){
    
}

/**
 * @brief Clona this
 * @return Puntero a GridLo clonado
 */
GridLO* GridLO::clonar(){
    GridLO* r = new GridLO(*this);
    return r;
}

/**
 * @brief Carga el estado desde un istream
 * @param in Istream del cual se carga el estado
 * @return Istream modificado
 */
istream& GridLO::cargar(istream& in){
    bool error = in.eof();
    bool done = false;
    char buffer[STREAMSIZE_LO];
    int row = 0;
    int column = 0;
    Separador s;
    while(!in.eof() && !error && !done){
        error |= row == GRIDSIZE_LO;
        if(!error){
            in.getline(buffer, STREAMSIZE_LO);
            if(buffer[0]){
                char ** strArr = s.separar(buffer);
                column = 0;
                while(strArr[column][0] && !error){
                    error |= column == GRIDSIZE_LO ;
                    for(int i = 0; strArr[column][i] && !error; ++i){
                        error |= i;
                    }
                    error |= strArr[column][0] != '1' && strArr[column][0] != '0';
                    if(!error){
                        grid[row][column] = strArr[column][0] == '1';
                        ++column;
                    }
                }
                s.liberar(strArr);
            }
        }
        ++row;
        done |= row == GRIDSIZE_LO && column == GRIDSIZE_LO;
    }
    error |= !done;
    if(error){
        cerr << "Error: los datos no tienen el formato correcto (debe contener exactamente ";
        cerr << GRIDSIZE_LO << "x" << GRIDSIZE_LO << " elementos que sean solo 1 o 0)." << endl;
        MatrixZ2 grid2(GRIDSIZE_LO);
        grid = grid2;
    }
    else{
        wasLoaded = true;
    }
    initial = true;
    return in;
}

/**
 * @brief Pasa la información del estado a un ostream
 * @param out Ostream al cual se imprime
 * @return Ostream modificado
 */
ostream& GridLO::imprimir(ostream& out){
    if(initial){
        out << "Estado inicial:\n";
    }
    else{
        out << "Switch (" << flipRow << ", " << flipColumn << "):" << endl;
    }
    grid.imprimir(out);
    return out;
}

/**
 * @brief Operador para determinar si dos estados son iguales
 * @param e Puntero a estado
 * @return True solo si e apunta a un GridLO y los grids son iguales
 */
int GridLO::operator==(Estado* e){
    GridLO* grid = dynamic_cast<GridLO*>(e);
    return grid && this->grid == grid->grid;
}

/**
 * @brief Operador para determinar si dos estados son distintos
 * @param e Puntero a estado
 * @return False solo si e apunta a un GridLO y los grids son iguales
 */
int GridLO::operator!=(Estado* e){
    return !(*this == e);
}

/**
 * @brief Genera el resultado de invertir una casilla y las adyacentes
 * @param row Fila de la casilla invertida
 * @param column Columna de la casilla invertida
 * @return GridLO resultado de hacer el movimiento
 */
GridLO GridLO::flip(unsigned int row, unsigned int column){
    int dimension = grid.getColumns();
    GridLO flip(*this);
    if(isValidPosition(row, column)){
        flip.initial = false;
        flip.flipRow = row;
        flip.flipColumn = column;
        flip.grid[row][column] = !flip.grid[row][column];
        if(isValidPosition(row, column-1)){
            flip.grid[row][column-1] = !flip.grid[row][column-1];
        }
        if(isValidPosition(row, column+1)){
            flip.grid[row][column+1] = !flip.grid[row][column+1];
        }
        if(isValidPosition(row-1, column)){
            flip.grid[row-1][column] = !flip.grid[row-1][column];
        }
        if(isValidPosition(row+1, column)){
            flip.grid[row+1][column] = !flip.grid[row+1][column];
        }
    }
    return flip;
}

/*
 * Determina si es una posición válida en grid
 */
bool GridLO::isValidPosition(unsigned int row, unsigned int column){
    return row >= 0 && column >= 0 && row < grid.getRows() && column < grid.getColumns();
}
