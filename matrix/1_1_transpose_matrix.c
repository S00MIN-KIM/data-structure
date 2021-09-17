#include<stdio.h>
#define ROWS 6
#define COLS 6
#define MAX_TERMS 36
typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows; //row number
	int cols; //column number
	int terms; //element number
} SparseMatrix;
//Use the data structure in p26 of 'DS-Lec-Array_pointer.pdf'


SparseMatrix sparse_matrix_sort(SparseMatrix a) {

	element temp;
	for (int i = 0; i < a.terms; i++) {
		for (int j = 0; j < a.terms - 1; j++) {
			if (a.data[j].row > a.data[j + 1].row) { //row is the priorty
				temp = a.data[j];
				a.data[j] = a.data[j + 1];
				a.data[j + 1] = temp;
			}
			else if (a.data[j].row == a.data[j + 1].row) { //when row is equal
				if (a.data[j].col > a.data[j + 1].col) { //compare the column
					temp = a.data[j];
					a.data[j] = a.data[j + 1];
					a.data[j + 1] = temp;
				}
			}
		}
	}

	return a;
}

SparseMatrix sparse_matrix_transpose(SparseMatrix a)
{
	SparseMatrix at; //transposed matrix of a
	int ai = 0, ati = 0; //Index indication terms in each array
	//ai: index of Matrix a data, and ati: index of Matrux at data

	//set the number of elements same as Matrix a.
	//switch the number of columns and rows because at is transposed matrix of a.
	at.rows = a.cols;
	at.cols = a.rows;
	at.terms = a.terms;

	//transpose
	while (ai < a.terms) {
		at.data[ati].row = a.data[ai].col;
		at.data[ati].col = a.data[ai].row; //col and row are switched.
		at.data[ati].value = a.data[ai].value; //value must be same.

		ai++, ati++; //loop for transposing every element
	}

	//transposed matrix B^T should also be saved in a row-wise manner
	at = sparse_matrix_sort(at);
	//sort the matrix in row-wise manner


	return at;
}

void sparse_matrix_print(SparseMatrix a) {
	int ai = 0;

	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			if (i == a.data[ai].row && j == a.data[ai].col) {
				printf("%d ", a.data[ai].value);
				ai++;
			}
			else
				printf("%d ", 0);
		}
		printf("\n");
	}
}

void main()
{
	//Add B as an input. 
	SparseMatrix B = { {{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},6,6,7 };
	//Rearrange the matrix in row-wise manner just in case. Sparse matrix is saved in a row-wise manner.
	B = sparse_matrix_sort(B);

	//Perform the transpose operation
	SparseMatrix BT = sparse_matrix_transpose(B);

	//Print out B and B^T in a dense matrix form to check 
	//whether the operation works correctly.
	printf("B =  \n");
	sparse_matrix_print(B);
	printf("\n");
	printf("B^T= \n");
	sparse_matrix_print(BT);

}