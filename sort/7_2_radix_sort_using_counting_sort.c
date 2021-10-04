#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// # of input data
#define NUM 1000

//function to generate random numbers
void random_num(int list[])
{
    for (int i = 0; i < NUM; i++) //generate NUM numbers
    {
        int sum = 0;
        int num = 1;
        //generate 24 bit number randomly
        for (int k = 0; k < 24; k++) {
            if (rand() % 2 == 1) //generate in binary
                sum += num; //sum converted number
            num *= 2; //change each bit into decimal number
        }
        list[i] = sum; //put the final decimal number into the list.
    }
}

//function to return the maximum number in list[]
int get_max(int list[])
{
    int max = list[0];
    for (int i = 1; i < NUM; i++)
        if (max < list[i])
            max = list[i];
    return max;
}

//function to do the counting sort for the given array. 
void counting_sort(int list[], int exp)
{
    int output[NUM]; //output array 
    int histogram[64] = { 0 }; //initialize every number in array into zero.
    //r=6 and # of digits is 4. 6 bits are 0~63. 
    //The array that saves the accumulated number needs 64 size to be used as histogram.

    //save frequencies for the digit in histogram[] 
    for (int i = 0; i < NUM; i++)
        histogram[(list[i] / exp) % 64]++;

    //accumulating to find the position
    for (int i = 1; i < 64; i++)
        histogram[i] += histogram[i - 1];

    //find the position and put into the ouput array
    for (int i = NUM - 1; i >= 0; i--) {
        output[histogram[(list[i] / exp) % 64] - 1] = list[i];
        histogram[(list[i] / exp) % 64]--; //decrease the frequncy of that number
    }

    //move output data to list[]
    for (int i = 0; i < NUM; i++)
        list[i] = output[i];
}

//function to do radix sort for list[]
void radix_sort(int list[])
{
    int max = get_max(list, NUM);

    //do counting sort for each digit
    //deal with the data as it is 64 base number to divide each data into 4 digits 
    //sort values at each digit from LSD to MSD
    for (int exp = 1; max / exp > 0; exp *= 64)
        counting_sort(list, exp);
}

//function to print the array 
void print(int list[])
{
    for (int i = 0; i < NUM; i++)
        printf("%d\n",list[i]);
}

//function to check if list[] is sorted corrctly
bool check_sort_results(int list[])
{
    bool index = 1;
    for (int i = 0; i < NUM - 1; i++)
        if (list[i] > list[i + 1])
        {
            index = 0;
            break;
        }
    return index;
}

int main()
{
    srand(time(NULL));

    int arr[NUM];
    random_num(arr); //generate the random numbers
    radix_sort(arr); //sort
    print(arr); //print the sorted numbers

    //check the result. 
    printf("\n\n");
    if (check_sort_results(arr))
        printf("Sorting result is correct.\n");
    else
        printf("Sorting result is wrong.\n");
    return 0;
}