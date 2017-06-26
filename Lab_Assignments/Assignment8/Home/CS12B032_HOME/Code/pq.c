#include "pq.h"
#include "heap.h"
#include <stdlib.h>
#define MAX_SIZE 100

pq* pq_new(){
	pq* pqueue= (pq*)malloc(sizeof(pq));
	pqueue->array= (node*)malloc(sizeof(node)*MAX_SIZE);
	pqueue->size=0;
	return pqueue;
}