#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//allocate 3D array of double
double*** mem_alloc_3D_double(int d1, int d2, int d3) //d1, d2, d3 are the dimension of each length, width, and height
{
	double*** array = (double***)malloc(sizeof(double***) * d1);
	for (int i = 0; i < d1; i++) {
		array[i] = (double**)malloc((sizeof(double**)*d2));//similar 2D array
		for (int j = 0; j < d2; j++) {
			array[i][j] = (double*)malloc(sizeof(double) * d3);//allocate every elements of each d3 using the first element in d2.
		}
	}

	return array;
}

double*** elements_3D(double*** a, int d1, int d2, int d3, double start_value) //put the value in allocated array
{
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			for (int k = 0; k < d3; k++) {
				*(*(*(a + i) + j) + k) = ++start_value;
				printf_s("%f  ", *(*(*(a + i) + j) + k));
			}
			printf("\n");
		}
	}
	printf("\n");

	return a;
}

double*** addition_3D(double*** a, double*** b, int d1, int d2, int d3)//add two array
{
	double*** c = mem_alloc_3D_double(d1, d2, d3);
	for (int i = 0; i < d1; i++) {
		for (int j = 0; j < d2; j++) {
			for (int k = 0; k < d3; k++) {
				*(*(*(c + i) + j) + k) = *(*(*(a + i) + j) + k) + *(*(*(b + i) + j) + k);
				printf_s("%f  ", *(*(*(c + i) + j) + k));
			}
			printf("\n");
		}
	}
	printf("\n");

	return c;
}

void deallocate(double*** a)//deallocate
{
	if (a != NULL) {
		free(a[0][0]);
		free(a[0]);
		free(a);
		a = NULL;
	}
}

void main() {
	int d1 = 3, d2 = 3, d3 = 3;

	//Define two matrices A and B using 'mem_alloc_3D_double'
	double*** A = mem_alloc_3D_double(d1, d2, d3);
	double*** B = mem_alloc_3D_double(d1, d2, d3);
	
	//put the value in each array
	printf("A:\n");
	A = elements_3D(A, d1, d2, d3, 0);
	printf("\nB:\n");
	B = elements_3D(B, d1, d2, d3, 1);

	//Perform addition of two matrices using 'addition_3D()'
	printf("\nA+B:\n");
	double*** C = addition_3D(A, B, d1, d2, d3);

	//Deallocate A and B
	deallocate(A);
	deallocate(B);
	deallocate(C);
}