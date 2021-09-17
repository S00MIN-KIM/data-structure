##실행
Visual Studio 2019
버전 16.5.3
--------------------------------------------------------------------------------------------------------------------------
##Project 1.
1_1_transpose_matrix.c
: For a sparse matrix represented by storing only non-zero elements, implement a transpose operation. 
 sparse matrix and transposed matrix are saved in a row-wise manner.

1) typedef struct element
: structure of element in sparse matrix
- It has row(int), col(int), value(int). row and col tell where the element is placed in matrix.
value means what the element is.

2) typedef struct SparseMatrix
: structure of sparse matrix
- It has rows(int) which is the number of rows, cols(int) which is the number of columns, 
terms(int) which is the number of elements.

3) SparseMatrix sparse_matrix_sort(SparseMatrix a)
:  function to sort the given matrix in row-wise manner
- parameters
	SparseMatrix: given matrix to sort
- return sorted "a".

4) SparseMatrix sparse_matrix_transpose(SparseMatrix a)
: function to transpose the given matrix and save in SparseMatrix at.
- parameters
	SparseMatrix: given matrix to transpose
- As transposed matrix should be saved in a row-wise manner, call the function 3) with giving at as parameter. 
- return the transposed matrix "at".

5)void sparse_matrix_print(SparseMatrix a)
: function to print the given matrix in a dense matrix to check whether the operation works correctly 
by printing the elements of the matrix one by one. If the value exists, print the value and if not, print "0".
- parameters
	SparseMatrix: given matrix to print

6)main
: add matrix B as an input(and sort by function 2) ) and perform the transpose operation with the function3). 
Then, print B and transposed matrix with function 4).
---------------------------------------------------------------------------------------------------------------------------
##Project 2.
1_2_alloc_3D_double
: allocate and define two 3D arrays of double. Add two arrays and deallocate both.

1)double*** mem_alloc_3D_double(int d1, int d2, int d3)
: function to allocate 3D array of double.
- parameters
	int d1, int d2, int d3: the dimension of each length, width, height of new array
- return the allocated array

2) double*** elements_3D(double*** a, int d1, int d2, int d3, double start_value)
: function to put the values in each element in allocated array 
- parameters
	double*** a: allocated array
	int d1, int d2, int d3: the dimension of each length, width, height of array "a"
	double start_value: the elements will increasing from start_value
- return array "a"

3) double*** addition_3D(double*** a, double*** b, int d1, int d2, int d3)
: function to add two array
- parameters
	double*** a, double*** b: operand to be added
	int d1, int d2, int d3: the dimension of a and b
- return result array "c"

4) void deallocate(double*** a)
: function to release the given array a
- parameters
	double*** a: array to be deallocated

5) main
: Define d1, d2, d3 of A and B. Define A and B with function 1). put the value in A and B by function 2). Add A and B by function 3).
Deallocate A and B by function 4).