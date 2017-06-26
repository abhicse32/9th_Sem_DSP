#ifndef PQ_H
#define PQ_H
#include <stdbool.h>

typedef struct PQ pq; 
typedef struct PQ_Node node;

struct PQ_Node{
	int element;
	int priority;
};

struct PQ{
	node* array;
	int size;
};

pq* pq_new();
// create new priority queue.

//insert element into priority queue.Compare with MAX_SIZE to check if queue is not full.
void push_pq(pq* pqueue, int item, int priority);

//remove the element/node with the highest priority
void pop_pq(pq* pqueue);

// check if the pq is empty
bool is_empty(pq* pqueue);

// get the top element from the priority queue(do not remove it)
node* top_pq(pq*); 

// int return the size of the queue(though we are mainting a size variable but think of the 
//situation when you want to keep the implementation details hidden from the user and make size as private variable)
int size_pq(pq*);

#endif 
