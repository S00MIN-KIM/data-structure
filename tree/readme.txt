##실행
Visual Studio 2019
버전 16.5.3
--------------------------------------------------------------------------------------------------------------------------
##Project 2.
5_2_find_a_successor.c
: finds a successor of node sequentially from the leftmost node in the inorder traversal

1) typedef struct TreeNode
: structure of node in tree
It has data(int), and left, right, parent(TreeNode*)

2) TreeNode* tree_successor(TreeNode* p)
: function that  finds a successor of given node in the inorder traversal and returns it
- parameter
	TreeNode* p:  predecessor node of finding node
- return the successor node of p
---------------------------------------------------------------------------------------------------------------------------
##Project 3.
5_3_find_a_predecessor.c
: finds a predecessor of node sequentially from the leftmost node in the inorder traversal.

1) typedef struct TreeNode
: structure of node in tree
It has data(int), and left, right, parent(TreeNode*)

2) TreeNode* tree_predecessor(TreeNode* p)
: function that finds a predecessor of given node in the inorder traversal and returns it.
- parameter
	TreeNode* p: seccessor of fining node
- return the predecessor of p
---------------------------------------------------------------------------------------------------------------------------
##Project 4.
5_4_insertion_deletion_predecessor
: insert and delete node in tree using linked list. 
The predecessor at the left subtree is used when delete the node which has two child nodes

1) typedef struct TreeNode
: structure of node in tree
It has key(int), and left, right(TreeNode*)

2) void insert_node(TreeNode** root, int key)
: function to insert the node
- parameters
	TreeNode** root: root node of the tree which a new node is inserted at
	int key: data of new node

3) void delete_node(TreeNode** root, int key)
: function to delete the node
- parameters
	TreeNode** root: root node of the tree which a node is deleted at
	int key: data of node to be deleted

4) void inorder(TreeNode* root)
: function to print node by inorder traversal
- parameter
	TreeNode* root: root node of the tree which will be printed

