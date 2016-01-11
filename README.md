This is SUDOKU solver using miniSAT solver.

Files included:
  sudoku.pl, sudoku.c
    sudoku.c should be compiled to executable file named 
	sudoku(gcc -Wall -o sudoku sudoku.c) before execution.
  sudoku
    Executable file. 
  sudoku.txt
    File which descripts sudoku problem.
  sudokuCNF.cnf, result
    Intermediate products of SUDOKU solver.

Usage: 
  1. Compile sudoku.c(ex. gcc -Wall -o sudoku sudoku.c). 
     The name of compiled file should be 'sudoku'
  2. Execute sudoku.pl(by command 'perl sudoku.pl')

Cautions:
  1. miniSAT program should be installed in your environment. 
     You can get miniSAT from 'http://minisat.se/MiniSat.html'.

  
  
