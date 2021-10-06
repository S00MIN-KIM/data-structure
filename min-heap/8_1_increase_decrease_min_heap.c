#include <stdio.h>
#include <stdlib.h>


#define MAX_ELEMENT 100

typedef struct {
    int heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

void init(HeapType* h) {
    h->heap_size = 0;
}

//function to set the min_heap. insert the key in the heap.
void insert_min_heap(HeapType* h, int key) {
    int i;
    //increase the heap size. starting from the bottom of the tree
    i = ++(h->heap_size);
    //find the location to insert
    while ((i != 1) && (key < h->heap[i / 2])) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = key;
}

//decrease ith node to key keeping priority
void decrease_key_min_heap(HeapType* h, int i, int key) {
    //if the given key is bigger than or same with original key, decrease function is not needed.
    if (key >= h->heap[i])
        printf("error new key is not smaller than current key ");

    //move from ith node to the root node comparing the key value with its parent in every iteration.
    h->heap[i] = key;
    int tmp;
    int parent = i/2;
    while ((i > 1) && (h->heap[i] < h->heap[parent])) { 
        //if key of child node is bigger than parent node, break the loop
        //otherwise, keep swaping child and parent node
        tmp = h->heap[i];
        h->heap[i] = h->heap[parent];
        h->heap[parent] = tmp;
        parent /= 2;
        i = parent;
    }
}

//increase ith node to key keeping priority
void increase_key_min_heap(HeapType* h, int i, int key) {
    //if the given key is smaller than or same with original key, increase function is not needed.
    if (key <= h->heap[i])
        printf("error : new key is not bigger than current key ");

    //move from ith node to the leaf node comparing the key value with its child in every iteration.
    h->heap[i] = key;
    int parent=i;
    int child = parent * 2;;
    while (child <= h->heap_size) { //until reaching the leaf nodes
        //find a smaller child node
        if ((child+1 <= h->heap_size) &&
            h->heap[child] > h->heap[child + 1])
            child++;
        //if parent is smaller than  child, break
        if (child <= h->heap_size && key <= h->heap[child])
            break;
        //change the location of child node
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    //put the key into the empty index
    h->heap[parent] = key;
}

void main(void) {
    HeapType h;
    //set the heap
    init(&h);
    int a[10] = { 1,4,2,7,5,3,3,7,8,9 };
    for (int i =0;i<10;i++)
        insert_min_heap(&h, a[i]);
    //print the original heap
    for (int i = 1; i <= h.heap_size; i++)
        printf("%d\n", h.heap[i]);

    //decrease fourth node to 3
    decrease_key_min_heap(&h, 4, 3);
    //print after decreasing
    printf("decrease---------\n");
    for (int i = 1; i <= h.heap_size; i++)
        printf("%d\n", h.heap[i]);

    //increase third node to 10
    increase_key_min_heap(&h, 3, 10);
    //print after decreasing and increasing
    printf("increase---------\n");
    for (int i = 1; i <= h.heap_size; i++)
        printf("%d\n", h.heap[i]);
}