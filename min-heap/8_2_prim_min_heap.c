#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 8 // # of vertices
#define INF 1000L

//the given graph represented by matrix
int weight[MAX_VERTICES][MAX_VERTICES] =
{ { 0,3,INF,INF,INF,INF,INF,14 },
{ 3,0,8,INF,INF,INF,INF,10 },
{ INF,8,0,15,2,INF,INF,INF },
{ INF,INF,15,0,INF,INF,INF,INF },
{ INF,INF,2,INF,0,9,4,5 },
{ INF,INF,INF,INF,9,0,INF,INF },
{ INF,INF,INF,INF,4,INF,0,6 },
{ 14,10,INF,INF,5,INF,6,0 } };

//structure of each vertex
typedef struct vertex {
	int edge; //edge (distance)
	int v;    //vertex number
	struct vertex* parent;  //link with parent vertex
} vertex;

//// HeapType->heap and vertices[] contains same vertex*
//structure of heap
typedef struct {
	vertex* heap[MAX_VERTICES+1];  //min heap used as priority queue. (replace dist[])
	int heap_size;	//size of the heap
} HeapType;

vertex* vertices[MAX_VERTICES]; //list of vertices

//initialize each vertex and put into vertices[] and heap.
void vertex_init(int num, HeapType* h) {
	vertex* new = (vertex*)malloc(sizeof(vertex));
	if (num == 0) //edge of stating vertex is 0
		new->edge = 0;
	else
		new->edge = INF; //initial edge of rest of vertices
	new->v = num; 
	new->parent = NULL; 

	//difference of index between vertices[] and heap is important.
	vertices[num] = new;
	h->heap[num+1] = new; 
}

//build the min_heap
void build_min_heap(HeapType* h)
{
	int parent, child;
	vertex* tmp;
	for (parent = h->heap_size / 2; parent > 0; parent--) {
		child = parent * 2;
		if ((child +1 <= h->heap_size) &&
			h->heap[child]->edge > h->heap[child + 1]->edge)
			child++;
		if (child <= h->heap_size && h->heap[child]->edge < h->heap[parent]->edge) {
			tmp = h->heap[parent];
			h->heap[parent] = h->heap[child];
			h->heap[child] = tmp;
			build_min_heap(h);
		}
	}
}

//delete the least vertex in min_heap
vertex* delete_min_heap(HeapType* h) {
	int parent, child;
	vertex* item;
	vertex* temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child]->edge) > h->heap[child + 1]->edge)
			child++;
		if (temp->edge <= h->heap[child]->edge) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

//check if the node whose vertex number is v is in the heap
int check(HeapType* h, int v) {
	for (int i = 1; i < MAX_VERTICES + 1; i++) {
		if (h->heap[i]->v == v)
			return TRUE;

	}
	return FALSE;
}

//decrease the edge of ith vertex to key
void decrease_key_min_heap(HeapType* h, int i, int key) {
	if (key >= h->heap[i]->edge)
		printf("error new key is not smaller than current key ");
	h->heap[i]->edge = key;
	vertex* tmp;
	int parent = i / 2;
	while ((i > 1) && (h->heap[i]->edge < h->heap[parent]->edge)) {
		tmp = h->heap[i];
		h->heap[i] = h->heap[parent];
		h->heap[parent] = tmp;
		parent /= 2;
		i = parent;
	}
}

//find the index of the vertex whose vertex number is v in heap
int find_index(HeapType* h, int v) {
	for (int i = 1; i < MAX_VERTICES + 1; i++) {
		if (h->heap[i]->v == v)
			return i;
	}
	return -1;
}

//print MST in preorder
void print_prim() {
	for (int i = 1; i < MAX_VERTICES; i++) {
		printf("Vertex %d -> %d \t edge: %d\n", vertices[i]->parent->v, vertices[i]->v, vertices[i]->edge);
	}
}

//make MST by prim's algorithm
void prim(int s)
{
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	h->heap_size = 0;
	vertex* least;
	//initialize each vertex
	//and insert all vertices into the priority queue(heap)
	for (int i = 0; i < MAX_VERTICES; i++) {
		vertex_init(i, h);
		h->heap_size++;
	}
	build_min_heap(h);

	//construct MST and define parent and child relation
	for (int i = 0; i < MAX_VERTICES; i++) {
		least = delete_min_heap(h); //Extract_Min(Q)
		if (least->edge == INF) return;
		int u = least->v;
		//for each vertex whick adjacent to least
		for (int v = 0; v < MAX_VERTICES; v++) {
			if(weight[u][v] != INF)
				//if the vertex exists in queue(heap) and weight[u][v] < distance of vertex and that vertex is not least,
				if (check(h, v) == 1 && weight[u][v] < vertices[v]->edge && vertices[v] != least) {
					vertices[v]->parent = least; //v.parent = u
					int index = find_index(h, vertices[v]->v);
					if (index == -1) printf("Do not exist in heap! ERROR!");
					else decrease_key_min_heap(h, index, weight[u][v]); //dist[v] <- weight[u][v]
				}
		}
	}
	free(h);
}

void main() {
	prim(0); //starting from 0 vertex
	print_prim(); //print the result
	for(int i=0;i<MAX_VERTICES;i++)
		free(vertices[i]);
}


