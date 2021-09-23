# include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define FALSE 0
#define TRUE 1

//struct of linked list
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
typedef struct {
	ListNode* head;// Head pointer
	ListNode* tail;// Tail pointer
	int length;// # of nodes
} ListType;

//print error message and exit the program
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//initialize the given linked list.
void init(ListType* list)
{
	if (list == NULL) return;
	list->length = 0;
	list->head = list->tail = NULL;
}

//check if the given linked list is empty(return 1) or not(return 0)
int is_empty(ListType* list)
{
	if (list->length == 0) return 1;
	else return 0;
}

//return the length of the given linked list.
int get_length(ListType* list)
{
	return list->length;
}
//return the node at given pos(position) in given linked list
ListNode* get_node_at(ListType* list, int pos)
{
	int i;
	ListNode* tmp_node = list->head;
	if (pos < 0) return NULL;
	for (i = 0; i < pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;
}

//get the data of the node which is located at pos in linked list.
element get_entry(ListType* list, int pos)
{
	ListNode* p;
	if (pos >= list->length) error("Positon error");
	p = get_node_at(list, pos);
	return p->data;
}
//print the given linked list
void display(ListType* list)
{
	int i;
	ListNode* node = list->head;
	printf(" ( ");
	for (i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}
	printf(")\n");
}
//check whether item is in the linked list of not.
int is_in_list(ListType* list, element item)
{
	ListNode* p;
	p = list->head;
	while ((p != NULL)) {
		if (p->data == item) break;
		p = p->link;
	}
	if (p == NULL) {
		return FALSE;
	}
	else return TRUE;

}

//insert new node right after the before node
void insert_node(ListNode** phead, ListNode* before, ListNode* new)
{
	if (*phead == NULL) {
		new->link = NULL;
		*phead = new;
	}
	else if (before == NULL) { //if before is NULL, in other words, if insert node in the beginning, 
		new->link = *phead; //link new node with head pointer
		*phead = new; //set head pointer to new node
	}
	else {
		new->link = before->link;
		before->link = new;
	}
}

//add node at given position in given list and put data.
void add(ListType* list, int position, element data)
{
	ListNode* p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		if (node == NULL) error("Memory allocation error");
		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}
//add node at first.
void add_first(ListType* list, int value)
{
	add(list, 0, value);
}
//add node at last. 
void add_last(ListType* list, int value)
{
	add(list, get_length(list), value);
}

//remove the node.
void remove_node(ListNode** phead, ListNode* before, ListNode* removed)
{
	if (before == NULL) {
		*phead = (*phead)->link;
	}
	else {
		before->link = removed->link;
	}
	free(removed);
}
//delete the node that is located at the pos in the linked list.
void delete(ListType* list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		ListNode* p = get_node_at(list, pos - 1); //before
		ListNode* removed = get_node_at(list, pos);
		remove_node(&(list->head), p, removed);
		list->length--;
	}
}
//delete the first node.
void delete_first(ListType* list)
{
	delete(&(list->head), 0);

}
//delete the last node
void delete_last(ListType* list)
{
	delete(&(list->head), get_length(list) - 1);
}

//test code
int main()
{
	ListType list1;
	init(&list1);
	add_first(&list1, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);
	add(&list1, 2, 70);
	display(&list1);

	delete(&list1, 2);
	delete_first(&list1);
	delete_last(&list1);
	display(&list1);

	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "TRUE" : "FALSE");
	printf("%d\n", get_entry(&list1, 0));
}