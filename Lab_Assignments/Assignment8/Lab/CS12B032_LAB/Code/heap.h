#ifndef HEAP_H
#define HEAP_H

typedef struct Heap heap;
struct Heap{
	int* arr;
	int size;
};

heap* heap_new();
// used to maintain the heap-property(here, min-heap)
void min_heapify(heap*, int);

//Build a min-heap
void build_min_heap(heap*);

//sort array elements in ascending order
void heapsort(heap*);

// insert an element in the heap
void heap_insert(heap*, int);

// extract the minimum element from the heap
void heap_extract_min(heap*);

// decrease the value of key at index @param_2 to the value @param_3 
// perform operations to ensure that heap-property holds after the operations
void heap_decrease_key(heap*,int,int);
 
void heap_increase_key(heap*,int,int);

// get the smallest heap element
int heap_min(heap*);

// print the heap, levelwise, in a single line
void print_heap(heap*);
#endif