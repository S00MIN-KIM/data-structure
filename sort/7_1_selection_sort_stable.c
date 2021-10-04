#include <stdio.h>

typedef struct data {
	int* id;
	int* score;
} data;

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort_stable(data* list, int n)
{
	int i, j, least, temp, k;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
			if (list->score[j] < list->score[least]) least = j; //get the index of data that has the least score.
		for (k = i + 1; k < n; k++) { //check before swap
			if (list->score[least] == list->score[k] && list->id[least] > list->id[k]) { 
				//check if there is the data having same score with least number 
				//but having earlier order originally (having less id number)
				least = k; //find the index of data which has the least id number
			}
		}
		SWAP(list->score[i], list->score[least], temp); //swap with data having the least score and  the least id
		SWAP(list->id[i], list->id[least], temp);
	}
}

int main()
{
	int data_id[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int data_score[] = { 30, 25, 10, 20, 80, 30, 25, 10 };

	int in_size = 8;
	data* input = (data*)malloc(sizeof(data));

	input->id = data_id;
	input->score = data_score;

	//Print out the input data
	printf("Input data\n");
	for (int i = 0; i < in_size; i++)
		printf("%d\t %d\n", input->id[i], input->score[i]);
	printf("\n");

	selection_sort_stable(input, in_size);

	//Print out the sorted data (stable)
	printf("Sorted data (stable)\n");
	for (int i = 0; i < in_size; i++)  
		printf("%d\t %d\n", input->id[i], input->score[i]);
	printf("\n");


	return 0;
}

