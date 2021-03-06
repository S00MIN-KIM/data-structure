##실행
Visual Studio 2019
버전 16.5.3
--------------------------------------------------------------------------------------------------------------------------
##Project 1.
6_1_heap_sort.c
: program to build and sort heap

1) typedef struct element
: structure of node in heap
It has key(int)

2) typedef struct HeapType
: structure of heap
It has heap(element *), heap_size(int)

3) int random(int n)
: generate the random number between 0 and n-1
- parameter
	int n: range of the random number
- return the generated random number

4) void init(HeapType* h)
: initialize given heap
- parameter
	HeapType* h: heap to initialize

5) void insert_max_heap(HeadType* h, element item)
: insert the item at heap h
- parameter
	HeadType* h: heap that item is inserted to
	element item: inserting item

6) element delete_max_heap(HeapType* h)
: delete the root at heap h
- parameter
	HeapType* h: heap that deleting root is located in
- return the deleted item(==root)

7) void build_max_heap(HeapType* h)
: max heapify and change the location of nodes
- parameter
	HeadType* h: heap to heapify

8) void heap_sort(HeapType* h, element* a, int n)
: sort the heap by calling build_max_heap and put element in decedning order(key)

9) bool check_sort_results(element* output, int n)
: check if the sorting is complete correctly
- return 0(wrong) or 1(correct)

---------------------------------------------------------------------------------------------------------------------------
##Project 2.
:  program to encode and decode an input data using Huffman binary tree 

1) typedef struct input_huff
: input data for huffman code
It has data(char *), freq(int *), size(int)

2) typedef struct TreeNode
: structure for huffman binary tree
It has data(char), key(int), bits(int), bit_size(int), l(TreeNode), r(TreeNode)

3) typedef struct bits_stream
: structure for bits stream
It has stream(int *), length(int)

4) typedef struct element
: structure for element used in the heap
It has ptree(TreeNode *), key(int)

5) typedef struct HeapType
: structure for heap
It has heap(element), heap_size(int)

6) int init(HeadType* h)
: function to initialize the heap
- parameter
	HeadType* h: heap to initialize

7) int is_empty(HeapType* h)
: function to check if heap is empty.
- parameter
	HeadType* h: heap to check
- return true when it is empty and return false when it is not empty

8) void insert_min_heap(HeapType* h, element item)
: function to insert new node
- parameter
	HeadType* h: heap that new node is inserted at
	element item: new node

9) element delete_min_heap(HeapType* h)
: delete the root heap
- parameter
	HeadType* h: heap that node is deleted from
- return the deleted node

10) TreeNode* make_tree(TreeNode* left, TreeNode* right)
: function to generate node in binary tree
- parameter
	TreeNode *left: left child of generated node
	TreeNode *right: right child of generated node
- return generated node 

11) void destroy_tree(TreeNode* root)
: function to remove the binary tree
- parameter
	TreeNode* root: root node of binary to remove

12) element huffman_tree(input_huff* huff)
: function to generate the Huffman binary tree
- parameter
	input_huff* huff: input data for huffman code
- return the root node of huffman_tree

13) void huffman_traversal(TreeNode* node)
: function to generate and save the huffman codeward from the huffman binary tree
- parameter
	TreeNode* node: root node of the huffman binary tree

14) int** mem_2D_int(int row, int col)
: function to allocate the memory of 2D array
- parameter
	int row: #of row
	int col: # of col
- return allocated matrix

15) void print_codeword()
: function to print the codeword of each character

16) void huffman_encoding(char* str, bits_stream* bits_str)
: function to generate encoded bits stream of given character string
- parameter
	char* str: characters to encode
	bits_stream* bits_str: array to save the encoded bits stream generated by the huffman binary tree

17) int huffman_decoding(bits_stream* bits_str, TreeNode* node, char* decoded_str)
: function to decode the bits stream into character string
- parameter
	bits_stream* bits_str: bits stream to decode
	TreeNode* node: root node of huffman binary tree
	char* decoded_str
- return the length of the decode_str(index_char)
