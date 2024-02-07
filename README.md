# generic-problem-solver

I had an outstanding participation, I created a solver capable of finding **optimal solutions** for any solvable problem. Taking advantage of abstract factories, it integrates perfectly with the problems, employing heuristic techniques for efficient exploration.

**Description:** This project consists of a series of "problems" and a series of "solvers", with the objective that each solver can follow a series of steps to reach the goal state of a problem, and that this is shown to the user. Ball Sort, Towers of Hanoi and Lights Out problems were programmed.


For specific information on the statement, as well as how the problems work, how the problem was solved, and possible improvements, see the external documentation PDF. 

**Authors:**

- Fabián Orozco Chaves (B95690) | <fabian7orozco@gmail.com>
- Sofía Velásquez Shum (C08395)
- Carolina Zamora (C08633)

## Compilation

### Using g++: 
Use the following command:
`g++ -o solucionar *.cpp`

### Usando Makefile:
Use the `make` or `make solucionar` command to compile all files. 

## Execution
Use the command `./solucionar` followed by the input parameters in order: problem name and solver name. Example:

`./solucionar Problema Solucionador`

For problems, the registered computer names are:

- `ProblemaFabian`
- `ProblemaSofia`
- `ProblemaCarolina`

For solvers, the registered team names are:

- `SolucionadorFabian`
- `SolucionadorSofia`
- `SolucionadorCarolina`
