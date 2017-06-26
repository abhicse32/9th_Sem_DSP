#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "set.h"

//create a new Set of given element
Node* makeSet (int value){
	Node *new;
	new=(Node *)malloc(sizeof(Node));	
	new->value = value;
	new->rank=0;
	new->parent = NULL;
	return new;
}

//initialize the Map. Map is just an array of Node pointers
//i.e it stores the pointers to sets
void initializeMap ( int* arr){
    map = (Map *)malloc(sizeof(Map));
    map->node = (Node **)malloc(SIZE*sizeof(Node *));
    int i;
    for(i=0;i<SIZE;i++){
        (map->node)[i] = makeSet(arr[i]);
        }
}

//get Set from the Map. i.e get pointer to the node having value=value 
Node* getNode(int value){
    int i;
    for(i=0;i<SIZE;i++){
        if(map->node[i]->value == value)
            return map->node[i];}
           
    return NULL;
}

//find an element x ( return the representative/root of the set which x belongs to ) 
Node* find(int value){
    Node *cur;
    cur = getNode(value);
    if(cur)
    {
        while(cur->parent!=NULL)
            cur = cur->parent;
        return cur;
    }
    else
        return NULL;
}

//find an element x ( return the representative/root of the set which x belongs to ) 
//along with the path compression
Node* findWithPathCompression(int value){
    Node *p = getNode(value);
    if(p->parent == NULL)
    	return p;
    else
    	p->parent = findWithPathCompression((p->parent)->value);
    return p->parent;
  	  
}

//implement union of two sets by "union by rank algorithm"
//i.e (xVal, yVal) these may not represent the root nodes, 
//so you should first get the representatives of these nodes and then take union of them 
Node* Union (int xVal , int yVal){
    Node *rootx, *rooty;
    rootx = find(xVal);
    rooty = find(yVal);

    if(rootx && rooty)
    {
        if(rootx->value == rooty->value)
            return rootx;
        if(rootx->rank < rooty->rank)
        {
            rootx->parent = rooty;
            return rooty;
        }
        else
        {
            if(rootx->rank == rooty->rank)
                rootx->rank++;
            rooty->parent = rootx;
            return rootx;
        }
    }
    else
        return NULL;
}

//Membership. i.e Do (xVal, yVal) belongs to same set 
bool isMember ( int xVal, int yVal) {
    Node *rootx, *rooty;
    rootx = findWithPathCompression(xVal);
    rooty = findWithPathCompression(yVal);
    if(rootx && rooty)
    {
        if(rootx->value == rooty->value)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

//cardinality of set containing given value/node
int cardinality (int value){
    int count=0, i;
    Node *root;
    
    root=find(value);
    for(i=0;i<SIZE;i++)
        if(find(map->node[i]->value) == root)
            count++;
    return count;
}

//Print the path from this node to it's representative
void printNode ( Node* node){
    if(node==NULL)
        return;
    
    while(node->parent)
    {
        printf("%d ", node->value);
        node=node->parent;
    }
    printf("%d\n", node->value);
}

//This will print path from each node to it's representative
//make use of printNode function
void printMap (){
    int i;
    for(i=0;i<SIZE;i++)
        printNode(map->node[i]);
}
