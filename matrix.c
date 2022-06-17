#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS	5
#define MATRIX_COLS	4
//const int MATRIX_ROWS = 5;
//const int MATRIX_COLS = 4;

void print_matrix(int rows, int cols, int **mat)
{
	for (int row = 0; row < rows; row++) {
		printf("%d:\t", row);
		for (int col = 0; col < cols; col++) {
			printf("%x ", mat[row][col]);
		}
		printf("\n");
	}
}

void print_matrix_array(int rows, int cols, int mat[MATRIX_ROWS][MATRIX_COLS])
{
	for (int row = 0; row < rows; row++) {
		printf("%d:\t", row);
		for (int col = 0; col < cols; col++) {
			printf("%x ", mat[row][col]);
		}
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	/*
	 * 
	 int matrix[MATRIX_ROWS][MATRIX_COLS]; --> size = 4 * 5 * 4 = 80

	 0	1	2	3
	 10000	10001	10002	10003
	 20000	20001	20002	20003
	 30000	30001	30002	30003
	 40000	40001	40002	40003

	 int *matrix[MATRIX_ROWS]; --> size = 8 * 5 = 40

	 0x000001698a15f410	0x000001698a15f1e0	0x000001698a15f0a0	0x000001698a15f320	0x000001698a15f320	0x000001698a15f460



*/

	//int matrix[MATRIX_ROWS][MATRIX_COLS];
	int *matrix[MATRIX_ROWS];

	for (int row = 0; row < MATRIX_ROWS; row++) {
		matrix[row] = calloc(MATRIX_COLS, sizeof(int));
		for (int col = 0; col < MATRIX_COLS; col++) {
			matrix[row][col] = (row << 16) | col;
			printf("%x\n", matrix[row][col]);
		}
	}

	printf("sizeof(matrix) = %lu\n", sizeof(matrix));
	//print_matrix_array(MATRIX_ROWS, MATRIX_COLS, matrix);
	print_matrix(MATRIX_ROWS, MATRIX_COLS, matrix);

	/*
	   for (int row = 0; row < MATRIX_ROWS; row++) {
	   free(matrix[row]);
	   }
	//free(matrix);
	*/
	return 0;
}
