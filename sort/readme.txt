##실행
Visual Studio 2019
버전 16.5.3
--------------------------------------------------------------------------------------------------------------------------
※ explanation of the stable sorting result is in "./Technical Report.docx"
--------------------------------------------------------------------------------------------------------------------------
##Project 1.
7_1_selection_sort_stable.c
: program that produces the stable sorting result.

1) typedef struct data
: structure of the data
- It has id(int* ), score(int* )

2) #define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
: function to swap x and y using t

3) void selection_sort_stable(data* list, int n)
: function to do selection sort with stablility
- parameter
	data* list: array to sort
	int n: length of the list
---------------------------------------------------------------------------------------------------------------------------
##Project 2.
7_2_radix_sort_using_counting_sort.c
: program that does radix sort using counting sort

1) #define NUM 1000
: # of input data

2) void random_num(int list[])
: function to generate random numbers
- parameter
	int list[]: where the generated random numbers stored at

3) int get_max(int list[])
: function to return the maximum number in list[]
- parameter
	int list[]: where find the maximum number from
- return the maximum number in list[]

4) void counting_sort(int list[], int exp)
: function to do the counting sort for the given array
- parameter
	int list[]: array to be sorted by counting sort
	int exp: exponential to divide the digits == r

5) void radix_sort(int list[])
: function to do radix sort for list[]
- parameter
	int list[]: array to be sorted by radix sort

6) void print(int list[])
: function to print the array
- parameter
	int list[]: array to be printed

7) bool check_sort_results(int list[])
: function to check if list[] is sorted corrctly
- parameter
	int list[]: array to check

