#include <stdio.h>
#include <stdlib.h>
//struct of doubly linked list
typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

//initialize the doubly linked list
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}
//print the linked list
void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<- %d -> ", p->data);
	}
	printf("\n");
}
//insert "new_node" right after the "before" node
//access "after" node by using "before" node.
void dinsert_node(DListNode* before, DListNode* new_node)
{
	new_node->llink = before;
	new_node->rlink = before->rlink; //before->rlink == after
	before->rlink->llink = new_node; //before->rlink == after
	before->rlink = new_node;
}

//completely same with dinsert_node. Only the name of function and parameter variable is changed.
//insert "new_node" in the beginning of the doubly linked list. (right after the "head" node)
void dinsert_first_node(DListNode* head, DListNode* new_node) 
{
	new_node->llink = head;
	new_node->rlink = head->rlink; //head->rlink == previous first node
	head->rlink->llink = new_node; //head->rlink == previous first node
	head->rlink = new_node;
}

//insert "new_node" at the end of the list. 
//"tail" node correspond with "before" node, and "head" correspond with "after" node.
//access "tail" node by using "head" node. 
void dinsert_last_node(DListNode* head, DListNode* new_node)
{
	new_node->rlink = head;
	new_node->llink = head->llink; //head->llink == tail
	head->llink->rlink = new_node; //head->llink == tail
	head->llink = new_node;
}

//test code
int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	DListNode* new_node_2 = (DListNode*)malloc(sizeof(DListNode));
	new_node_2->data = 2;
	dinsert_first_node(head, new_node_2);
	//   <- 2 ->

	DListNode* new_node = (DListNode*)malloc(sizeof(DListNode));
	new_node->data = 1;
	dinsert_node(new_node_2, new_node);
	//   <- 2 -> <- 1 ->

	DListNode* new_node_3 = (DListNode*)malloc(sizeof(DListNode));
	new_node_3->data = 3;
	dinsert_last_node(head, new_node_3);
	//   <- 2 -> <- 1 -> <- 3 ->

	DListNode* new_node_4 = (DListNode*)malloc(sizeof(DListNode));
	new_node_4->data = 0;
	dinsert_first_node(head, new_node_4);
	//   <- 0 -> <- 2 -> <- 1 -> <- 3 ->

	DListNode* new_node_5 = (DListNode*)malloc(sizeof(DListNode));
	new_node_5->data = 9;
	dinsert_last_node(head, new_node_5);
	//   <- 0 -> <- 2 -> <- 1 -> <- 3 -> <- 9 ->

	//print
	print_dlist(head);

	free(head);
	return 0;
}
