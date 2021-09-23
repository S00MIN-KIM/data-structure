#include <stdio.h>
#include <stdlib.h>

//structure of linked list
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
typedef struct {
	ListNode* head;// Head pointer
	ListNode* tail;//tail pointer
	int length;// # of nodes
} ListType;

//print the error message and exit the program. 
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//create the linked list.
ListType* create()
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->length = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

//insert node at the end
void insert_last(ListType* list, int data)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("Memory allocation error!");
	temp->data = data;
	temp->link = NULL; //tail node linked with NULL
	if (list->tail == NULL) { //if there is no tail node, 
		list->head = list->tail = temp; //head node == tail node == new node (== temp)
	}
	else { //if tail node exists, 
		list->tail->link = temp; //link previous tail node to temp. 
		list->tail = temp; //change the tail node to temp.
	}
	list->length++; //increase the length. 
}

//print the linked list. 
void print_list(ListType* list)
{
	for (ListNode* p = list->head; p != NULL; p = p->link)
		printf("%d-> ", p->data);
	printf("NULL \n");
}

//merge two lists(list1 and list2) in ascending order and saved in list3. 
void merge(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* a = list1->head;
	ListNode* b = list2->head;

	//since list1 and list2 is already sorted in ascending order, 
	//we can merge two lists in ascending order by comparing nodes sequentially.
	while (a && b) { //until the a or b is not true. If one of the two is NULL, escape the loop. 
		if (a->data <= b->data) { //if data of a is smaller than data of b, 
			insert_last(list3, a->data); //save the a node at the end of list3. 
			a = a->link; //move a pointer to compare next node. 
		}//if (a->data == b->data), it doesn't matter which node is saved early. 
		else {//if data of b is smaller than data of a,
			insert_last(list3, b->data); //save the b node at the end of list3.
			b = b->link; //move b pointer to compare next node. 
		}
	}
	//check if there are remained nodes and put them into list3 sequentially. 
	for (; a != NULL; a = a->link)
		insert_last(list3, a->data);
	for (; b != NULL; b = b->link)
		insert_last(list3, b->data);

}

//test code
int main(void)
{
	ListType* list1, * list2, * list3;

	list1 = create();
	list2 = create();
	list3 = create();
	
	//a = {1,2,5,10,15,20,25}
	insert_last(list1, 1);
	insert_last(list1, 2);
	insert_last(list1, 5);
	insert_last(list1, 10);
	insert_last(list1, 15);
	insert_last(list1, 20);
	insert_last(list1, 25);
	printf("a : ");
	print_list(list1);
	
	//b = {3,7,8,15,18,30}
	insert_last(list2, 3);
	insert_last(list2, 7);
	insert_last(list2, 8);
	insert_last(list2, 15);
	insert_last(list2, 18);
	insert_last(list2, 30);
	printf("b : ");
	print_list(list2);

	merge(list1, list2, list3);
	//c = {1,2,3,5,7,8,10,15,15,18,20,25,30}
	printf("c : ");
	print_list(list3);

	return 0;
}