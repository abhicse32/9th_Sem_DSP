#include "heap.h"
#include <stdlib.h>
#define max_size 1000

heap* heap_new(){
	heap* h= (heap*)malloc(sizeof(heap));
	h->arr= (int*)malloc(sizeof(int)*max_size);
	h->size=0;
	return h;
}