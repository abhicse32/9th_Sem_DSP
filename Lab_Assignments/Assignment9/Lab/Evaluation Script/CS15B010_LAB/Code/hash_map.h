#ifndef HASH_H
#define HASH_H
#include "bst.h"
#include <stdbool.h>

typedef struct HashMap map;

struct HashMap{
	Node_BST** root;
	size_t size;
};

// initialize the map
map* new_map();

/*insert the key*/
void put(map*, int key, int val);

// return the value corresponding to the key, INT_MIN otherwise
int find(map*, int key);

// check if map is empty
bool is_empty(map*);

// return the size of the map
int size(map*);

// erase the entire map and free he container
void clear(map*);

// delete the key and corresponding value from the map
void erase(map*, int key);

#endif
