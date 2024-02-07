CFLAGS=
OBJECTS=MatrixZ2.o GridLO.o Separador.o Lista.o LightsOut.o SolucionadorCarolina.o Solucion.o FabricaSolucionadorCZ.o FabricaLightsOut.cpp Registro.o FabricaSolucionadorSofia.o FabricaProblemaTH.o EstadoTH.o ProblemaTH.o SolucionadorSofia.o Matriz03021_BS.o State03021_BS.o Problem03021_BS.o EstadoConRuta.o Solver03021.o Solver03021Factory.o Problem03021Factory.o

all: solucionar

%.o: %.cpp
	g++ $(CFLAGS) -c $<

solucionar: main.cpp $(OBJECTS)
	g++ $(CFLAGS) -o solucionar main.cpp $(OBJECTS)
