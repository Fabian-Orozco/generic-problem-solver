#include "FabricaSolucionadorSofia.h"

using namespace std; 

SolucionadorSofia* FabricaSolucionadorSofia::producir(){
	SolucionadorSofia * solucionador = new SolucionadorSofia(); 
	return solucionador; 
}