#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "hash_map.h"
#include "bst.h"
#define MAX_SIZE 1024

//Function that hashes the key
int find_hash_index(unsigned int key)
{
    int hash=5893,temp;
    while(key!=0)
    {
        temp=key&255;
        hash<<=4;
        hash^=temp;
        key>>=8;
    }
    return hash%1024;
}

// initialize the map
map* new_map()
{
    map *newmap=malloc(sizeof(map));
    newmap->size=0;
    newmap->root=malloc(1024*sizeof(Node_BST *));
    return newmap;
}

/*insert the key*/
void put(map* map_, int key, int val)
{
    int index=find_hash_index(key);
    map_->root[index]=insert(map_->root[index],key,val);
    map_->size++;
}

// return the value corresponding to the key, INT_MIN otherwise
int find(map* map_, int key)
{
    int index=find_hash_index(key);
    Node_BST *temp=search(map_->root[index],key);
    if(temp!=NULL)
    	return temp->data.value;
    else
    	return INT_MIN;
}

// check if map is empty
bool is_empty(map* map_)
{
    if(map_->size==0)
    	return true;
    else
    	return false;
}

// return the size of the map
int size(map *map)
{
    return map->size;
}

// erase the entire map and free the container
void clear(map* map_)
{
    int i;
    for(i=0;i<1024;i++)
    {
        (map_->root)[i]=NULL;
    }
    map_->size=0;
}

// delete the key and corresponding value from the map
void erase(map* map_, int key)
{
    int index=find_hash_index(key);
    map_->root[index]=delete(map_->root[index],key);
    map_->size--;
}
