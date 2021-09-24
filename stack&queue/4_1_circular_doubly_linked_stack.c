#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure of node in stack
typedef int element;
typedef struct StackNode {
	element item;
	struct StackNode* llink;
	struct StackNode* rlink;
} StackNode;

//structure of stack
typedef struct {
	StackNode* top;
} LinkedStackType;

//initialize the stack
void init(LinkedStackType* s, StackNode* head)
{
	head->rlink = head->llink = s->top =head;
}

//check if the stack is empty
int is_empty(LinkedStackType* s, StackNode* head)
{
	return (s->top == head);//if top is NULL, return 1(true). Otherwise, return 0(false).
}

//push the item into the stack
void push(LinkedStackType* s, element item, StackNode* head)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode)); //memory allocation for using temp node. temp node == new node
	if (temp == NULL) { 
		printf("Memory allocation error\n"); 
		return; //end the function
	}
	else {
		temp->item = item; //put the data into new node
		temp->llink = head; //connect the new node with head node
		head->rlink = temp; //connect head node with new node
		temp->rlink = s->top; //connect new node with previous top node
		s->top->llink = temp;//connect previous top node with new node
		s->top = temp;//top node is new node now.
	}
}

//pop the top node of the stack
element pop(LinkedStackType* s, StackNode* head)
{
	if (is_empty(s, head)) { //check if stack is empty. If so, there is nothing to pop.
		printf("Stack is empty\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top; //temp == node to be removed == s->top
		int item = temp->item; 
		head->rlink = temp->rlink; //temp->rlink = second node. connect head with second node.
		temp->rlink->llink = head; //connect seconde node with head node.
		s->top = temp->rlink; //top node is second node new. 

		free(temp);
		return item;
	}
}

element peek(LinkedStackType* s, StackNode* head)//peek return the data of the top node without removing it.
{
	if (is_empty(s, head)) { //if the stack is empty, there is nothing to return. 
		printf("Stack is empty\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

void main()
{
	LinkedStackType s;
	StackNode* head = (StackNode*)malloc(sizeof(StackNode)); //set the head node.
	init(&s, head); //initialize the stack s.
	push(&s, 1, head); //push 1 into the stack.
	push(&s, 2, head); //push 2 into the stack.
	push(&s, 3, head); //push 3 into the stack.

	//Stack
	//3 <-top
	//2
	//1

	printf("%d\n", pop(&s, head)); //pop 3
	printf("%d\n", pop(&s, head)); //pop 2
	printf("%d\n", pop(&s, head)); //pop 1
}