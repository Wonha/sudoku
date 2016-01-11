Program Description:

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
		
	1. Compile sudoku.c(ex. gcc -Wall -o sudoku sudoku.c). The name of compiled file should be 'sudoku'
	2. Execute sudoku.pl(by command 'perl sudoku.pl')
	3. Write sudoku problem to file 'sudoku.txt'. Refer the example about format of sudoku.txt file below.

	5 3 0 0 7 0 0 0 0
	6 0 0 1 9 5 0 0 0
	0 9 8 0 0 0 0 6 0
	8 0 0 0 6 0 0 0 3
	4 0 0 8 0 3 0 0 1
	7 0 0 0 2 0 0 0 6
	0 6 0 0 0 0 2 8 0
	0 0 0 4 1 9 0 0 5
	0 0 0 0 8 0 0 7 9

	where the 0 means target to solve, unknown block.

Cautions:
	
	1. miniSAT program should be installed in your environment. You can get miniSAT from 
	'http://minisat.se/MiniSat.html'.

Application Development Environment:

	Language: perl 5, C
	compiler: gcc 4.8.4
	Text Editor: VIM 7.4
	OS: Ubuntu 14.04.1 64bit desktop
