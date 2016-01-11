#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL_TYPE
#define BOOL_TYPE
typedef enum {false = 0, true = 1} bool;
#endif


int main() {
	
	int i,j,k, m, var, var1, var2;
	int con;

	FILE* fd ;

	FILE* fp = fopen("sudokuCNF.cnf", "wt");
	if(fp==NULL) {
		printf("file open failed. 'sudokuCNF.cnf'.\n");
		return -1;
	}
	
	fd = fopen("sudoku.txt", "r");
	if(fd==NULL) {
		printf("file open failed. sudoku.txt \n ");
		return -1;
	}

//rule 1	
	for(i=0; i<9; i++) {
		for(j=0; j<9; j++) {
			for(k=0; k<9; k++) {
				var = i*81+j*9+k+1;
				fprintf(fp, "%d ", var);
			}
			fprintf(fp, " 0\n");
		}
	}
//rule 2
	for(i=0;i<9;i++) {
		for(k=0; k<9; k++) {
			for(j=0; j<8; j++)
				for(m=j+1; m<9; m++) {
					var1 = i*81+j*9+k+1;
					var2 = i*81+m*9+k+1;
					fprintf(fp, "%d %d 0\n", var1*-1, var2*-1);
				}
		}
	}
//rule 3
	for(j=0;j<9;j++) {
		for(k=0; k<9; k++) {
			for(i=0; i<8; i++)
				for(m=i+1; m<9; m++) {
					var1 = i*81+j*9+k+1;
					var2 = m*81+j*9+k+1;
					fprintf(fp, "%d %d 0\n", var1*-1, var2*-1);
				}
		}
	}
//rule 4
	int masarr[81] = {1,  10,  19,  28,  37,  46,  55,  64,  73, 
					 82,  91, 100, 109, 118, 127, 136, 145, 154,
					163, 172, 181, 190, 199, 208, 217, 226, 235,
					244, 253, 262, 271, 280, 289, 298, 307, 316, 
					325, 334, 343, 352, 361, 370, 379, 388, 397,
					406, 415, 424, 433, 442, 451, 460, 469, 478,
					487, 496, 505, 514, 523, 532, 541, 550, 559,
					568, 577, 586, 595, 604, 613, 622, 631, 640,
					649, 658, 667, 676, 685, 694, 703, 712, 721 };

	int boxidx[9][9] = {{0, 1, 2, 9, 10, 11, 18, 19, 20},
						{3, 4, 5, 12, 13, 14, 21, 22, 23},
						{6, 7, 8, 15, 16, 17, 24, 25, 26},
						{27, 28, 29, 36, 37, 38, 45, 46, 47},
						{30, 31, 32, 39, 40, 41, 48, 49, 50},
						{33, 34, 35, 42, 43, 44, 51, 52, 53},
						{54, 55, 56, 63, 64, 65, 72, 73, 74},
						{57, 58, 59, 66, 67, 68, 75, 76, 77},
						{60, 61, 62, 69, 70, 71, 78, 79, 80}};
	for(i=0;i<9;i++) {
		for(k=0;k<9;k++) {
			for(m=0;m<8;m++) {
				for(j=m+1;j<9;j++) {
					fprintf(fp, "%d %d 0\n",(masarr[boxidx[i][m]]+k)*-1 ,(masarr[boxidx[i][j]]+k)*-1);
				}
			}
		}
	}

	j=0;
	k=0;
	
	for(m=0;m<81;m++) {
		fscanf(fd, "%d", &con);
		var = 9*m + con;

		if(con != 0) {
			fprintf(fp, "%d 0\n", var);
		}
	}

	return 0;
}



