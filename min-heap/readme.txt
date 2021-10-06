##실행
Visual Studio 2019
버전 16.5.3
--------------------------------------------------------------------------------------------------------------------------
##Project 1.
8_1_increase_decrease_min_heap.c
: program that increase and decrease the key in the min-heap.

1) typedef struct HeapType
: structure of the heap
- It has heap[](int), heap_size(int)

2) void init(HeapType* h)
: function to initialize heap
- parameter
	HeapType* h: heap to be initialized

3) void insert_min_heap(HeapType* h, int key)
: function to set the min_heap. It inserts the key in the heap
- parameter
	HeapType* h: heap to insert the key at
	int key: new node to be inesrted

4) void decrease_key_min_heap(HeapType* h, int i, int key)
: function to decrease ith node to key keeping priority
- parameter
	HeapType* h: where the node to be decreased is in
	int i: location of the node to be decreased
	int key: new key of the node to be decreased

5) void increase_key_min_heap(HeapType* h, int i, int key)
: function to increase ith node to key keeping priority
- parameter
	HeapType* h: where the node to be increased is in
	int i: location of the node to be increased
	int key: new key of the node to be increased
---------------------------------------------------------------------------------------------------------------------------
##Project 2.
8_2_prim_min_heap.c
: program that does radix sort using counting sort

1) typedef struct vertex
: structure of each vertex
- It has edge(int), v(int), parent(vertex*)

2) typedef struct HeapType
: structure of heap
- It has heap[](vertex*), heap_size(int)

3) vertex* vertices[MAX_VERTICES]
: list of vertices(MST)

4) void vertex_init(int num, HeapType* h)
: function to initialize each vertex, and to put into vertices[] and heap.
- parameter
	int num: used as vertex number and index
	HeapType* h: where the vertex is inserted in

5) void build_min_heap(HeapType* h)
: build the min_heap
- parameter
	HeapType* h: heap to build with priority

6) vertex* delete_min_heap(HeapType* h)
: function to delete the vertex whic has least edge value in min_heap
- parameter
	HeapType* h: where the vertex is deleted from
- return least vertex

7) int check(HeapType* h, int v)
: function to check if the node whose vertex number is v is in the heap
- parameter
	HeapType* h: heap to search
	int v: vertex number
- return TRUE(1) or FALSE(0)

8) void decrease_key_min_heap(HeapType* h, int i, int key)
: function to decrease the edge of ith vertex to key
- parameter
	HeapType* h: where the node to be decreased is in
	int i: location of the node to be decreased
	int key: new key of the node to be decreased

9) int find_index(HeapType* h, int v)
: function to find the index of the vertex whose vertex number is v in heap
- parameter
	HeapType* h: heap to search
	int v: vertex number
- return the index of vertex in heap

10) void print_prin()
: function to print MST in preorder

11) prim(int s)
: function to make MST by prim's algorithm
- parameter
	int s: vertex number starting vertex
