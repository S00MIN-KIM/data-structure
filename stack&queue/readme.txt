##실행
Visual Studio 2019
버전 16.5.3
--------------------------------------------------------------------------------------------------------------------------
##Project 1.
1_1_circular_doubly_linked_list.c
: stack program using circular doubly linked list.

1) typedef int element
: data of node in stack

2) typedef struct StackNode
: structure of node in stack
It has item(element), llink(StackNode*), rlink(StackNode*)  

3) typedef struct LinkedStackType
: structure of stack
- It has top node.

4) void init(LinkedStackType* s, StackNode* head)
: function to initialize the stack. 
- parameters
	LinkedStackType* s: stack to initialize
	StackNode* head: head node of s

5) int is_empty(LinkedStackType* s, StackNode* head)
: function to check if the stack is empty.
- parameters
	LinkedStackType* s: stack to check
	StackNode* head: head node of s

6) void push(LinkedStackType* s, element item, StackNode* head)
: function to push the item into the stack s.
- parameter
	LinkedStackType* s: stack that item will be pushed into.
	element item: data of the new node that will be pushed into s.
	StackNode* head: head node of s

7) element pop(LinkedStackType* s, StackNode* head)
: function to pop the top node from the stack s.
- parameter
	LinkedStackType* s: stack that the top node will be pop from.
	StackNode* head: head node of s

8) element peek(LinkedStackType* s, StackNode* head)
: function to peek return the data of the top node without removing it.
- parameter
	LinkedStackType* s: stack that data of the top node will be returned from.
	StackNode* head: head node of s

9) void main()
: test code
---------------------------------------------------------------------------------------------------------------------------
##Project 2.
4_2_two_staffs_simulation.c
: bank service simulation which is applicating queue and assumed that there are two banks staff work. 

1)typedef struct element
: stucture of customer
- It has id(int), arrival_time(int), service_time(int)

2) typedef struct QueueType
: structure of queue 
- It has queue(element), front(int), rear(int)

3) double random()
: function to return the real random number between 0 and 1
- return the real number between 0 and 1

+) Glabal Variables
QueueType queue: queue to store the waiting customers
int duration: simulation time
double arrival_prob: Average number of customers arriving in one time unit
int max_serv_time: maximum service time for one customer
int clock: current time
int custoners: total number of customers
int served_customers: number of customers served
int waited_time: time the customers waited
int num_of_staff: number of staffs

4) int is_empty(QueueType* q)
: function to check if q is empty
- parameters
	QueueType* q: queue to check
- return 0 if q is not empty, and otherwise, return 1.

5) int is_full(QueueType* q)
: function to check if q is full
- parameters
	QueueType* q: queue to check
- return 0 if q is not full, and otherwise, return 1.

6) void enqueue(QueueType* q, element item)
: function to insert the item into the q
- parameters
	QueueType* q: queue that inserts the item into
	element item: item to be inserted

7) element dequeue(QueueType* q)
: function to delete the front item and return it.
- parameters
	QueueType* q: queue that gets the item from
- return the front item

8) int is_customer_arrived()
: function to check if customer is arrived by constant probabillity(arrival_prob)
- return false or true

9) int insert_customer(int arrival_time)
- parameters
	int arrival_time: arrival time of customer. get parameter to set the arrival time each.
- return customer.id

10) int remove_customer()
: function to retrieve the customer waiting in the queue and return the customer's service time.
return the service_time of next customer

11) void print_stat()
: function to print the statistics

12) void main()
: test code
