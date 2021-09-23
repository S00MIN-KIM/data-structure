##실행
Visual Studio 2019
버전 16.5.3
--------------------------------------------------------------------------------------------------------------------------
##Project 1.
3_1_Doubly_linked_list_insert.c
: insert a new node in the beginning or at the end of in doubly linked list. 

1) typedef int element
: define element in doubly linked list
- The type of element is integer.

2) typedef struct DListNode
: structure of Node in doubly linked list.
- It has data(element), *llink(DListNode), *rlink(DListNode). 
Node is connected to right linked node and left linked node.

3) void init(DListNode* phead)
:  function to initialize the given doubly linked list
- parameters
	DListNode* phead: the head node of given doubly linked list. 

4) void print_dlist(DListNode* phead)
: function to print the doubly linked list.
- parameters
	DListNode* phead: the head node of given doubly linked list. 

5) void dinsert_node(DListNode* before, DListNode* new_node)
: function to insert "new_node" right after the "before" node
- parameters
	DListNode* before: before node of new_node
	DListNode* new_node: new node to insert

6) void dinsert_first_node(DListNode* head, DListNode* new_node) 
:function to insert "new_node" in the beginning of the doubly linked list. (right after the "head" node)
- parameters
	DListNode* head: the head node of given doubly linked list. 
	DListNode* new_node: new node to insert

7) void dinsert_last_node(DListNode* head, DListNode* new_node)
: function to insert "new_node" at the end of the list. 
- parameters
	DListNode* head: the head node of given doubly linked list. 
	DListNode* new_node: new node to insert

8) main
: test code
define the head node and initialize it. 
insert 2 in the beginning, insert 1 after 2, insert 3 at the end, insert 0 in the beginning, insert 9 at the end.
---------------------------------------------------------------------------------------------------------------------------
##Project 2.
3_2_Merge_linked_list.c
: merge linked list "a" and linked list "b" in ascending order and save in list "c". "a" and "b" are sorted in ascending order.

1) typedef int element
: define element in linked list
- The type of element is integer.

2) typedef struct ListNode
: structure of node in linked list. 
- It has data(element), and *link(ListNode)

3) typedef struct ListType
: structure of linked list. 
- It has *head(ListNode), *tail(ListNode), length(int)

4) void error(char *message)
: fuction to print the error message and exit the program.
- parameters
	char* message: message to print out. 

5) ListType* create()
: function to create the linked list.
- return the allocated and initialized linked list. 

6) void insert_last(ListType* list, int data)
: function to insert new node at the end of the linked list.
- parameters:
	ListType* list: where node is going to be inserted in. 
	int data: data of new node.

7) void print_list(ListType* list)
: function to print the linked list. 
- parameter
	ListType* list: linked list to print.

8) void merge(ListType* list1, ListType* list2, ListType* list3)
: merge two lists(list1 and list2) in ascending order and saved in list3. 
- parameters
	ListType* list1: list a to merge
	ListType* list2: list b to merge
	ListType* list3: merged list c

9) main
: test code. 
create the list1, list2, list3 and put the elements in list1 and list2. 
merge list1 and list2, and save in list3. print three lists to check. 
---------------------------------------------------------------------------------------------------------------------------
##Project 3.
3_3_ListADT.c
: re-implement all functions in ‘List ADT’ (p55-p61) as well as add_first, add_last, delete_first, delete_last

1) typedef int element
: define element in linked list
- The type of element is integer.

2) typedef struct ListNode
: structure of node in linked list. 
- It has data(element), and *link(ListNode)

3) typedef struct ListType
: structure of linked list. 
- It has *head(ListNode), *tail(ListNode), length(int)

4) void error(char *message)
: fuction to print the error message and exit the program.
- parameters
	char* message: message to print out. 

5) void init(ListType* list)
: function to initialize the given linked list
- parameters
	ListType* list: linked list to initialize 

6) int is_empty(ListType* list)
: function to check if the given linked list is empty or not.
- parameters
	ListType* list: linked list to check
- return 1 if the given linked is empty, and return 0 if not.

7) int get_length(ListType* list)
: function to return the length of the given linked list.
- parameter
	ListType* list: linked list to get length	
- return the length of the given linked list. 

8) ListNode* get_node_at(ListType* list, int pos)
: function to return the node at given pos(position) in given linked list
- parameter
	ListType* list: linked list to find the node
	int pos: position of the node to find
- return found node

9) element get_entry(ListType* list, int pos)
: get the data of the node which is located at pos in linked list.
- parameter
	ListType* list: linked list to find the node
	int pos: position of the node to find
- return the data of found node

10) void display(ListType* list)
: function to print the given linked list
- parameter
	ListType* list: the given linked list to print

11) int is_in_list(ListType* list, element item)
: function to check whether item is in the linked list of not.
- parameters
	ListType* list: linked list to find item
	element item: element to be found
- return FALSE if item is not found and return TRUE if item is found.

12) void insert_node(ListNode** phead, ListNode* before, ListNode* new)
: function to insert new node right after the before node
- parameters
	ListNode** phead: double pointer of first node
	ListNode* before: previous node of new node
	ListNode* new: new node to insert
	
13) void add(ListType* list, int position, element data)
: function to add node at given position in given list and put data.
- parameters
	ListType* list: linked list to insert new node in
	int position: position of new node
	element data: data of new node 

14) void add_first(ListType* list, int value)
: function to add node at first.
- parameters
	ListType* list: linked list to insert new node in
	int value: data of new node 
- call the void add(ListType* list, int position, element data). position = 0.

15) void add_last(ListType* list, int value)
: function to add node at last.
- parameters
	ListType* list: linked list to insert new node in
	int value: data of new node 
- call the void add(ListType* list, int position, element data). position = get_length(list).

16) void remove_node(ListNode** phead, ListNode* before, ListNode* removed)
: fuction to remove node which is linked with before node. 
- parameters
	ListNode** phead: double pointer of first node
	ListNode* before: previous node of removed node
	ListNode* removed: node to remove

17) void delete(ListType* list, int pos)
: function to delete the node that is located at the pos in the linked list.
- parameters
	ListType* list: linked list to remove node from
	int position: position of removed node

18) void delete_first(ListType* list)
: function to delete the first node.
- parameters
	ListType* list: linked list to remove node from
- call the void delete(ListType* list, int pos). position = 0

19) void delete_last(ListType* list)
: function to delete the last node. 
- parameters
	ListType* list: linked list to remove node from
- call the void delete(ListType* list, int pos). position = get_length(list)-1.

20) main
: test code. 

