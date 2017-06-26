#ifndef SET_H
#define SET_H

typedef struct Node_ Node ;
typedef struct Map_ Map ;

//value is data it holds
//rank is the height of the tree
//parent is a parent pointer
struct Node_{
	int value ;
	int rank ;
	Node* parent ;
};

//Map is just an array of Node pointers
//i.e it stores the pointers to sets
//this is required to get node corresponding to the given value
struct Map_{
	Node** node ;
};

int SIZE ;
Map* map ;


//create a new Set of given element
Node* makeSet (int value);

//initialize the Map. Map is just an array of Node pointers
//i.e it stores the pointers to sets
void initializeMap ( int* arr) ;

//get Set from the Map. i.e get pointer to the node having value=value 
Node* getNode(int value) ;

//find an element x ( return the representative/root of the set which x belongs to ) 
Node* find(int value) ;

//find an element x ( return the representative/root of the set which x belongs to ) 
//with path compression
Node* findWithPathCompression(int value) ;

//implement union of two sets by "union by rank algorithm"
//i.e (xVal, yVal) these may not represent the root nodes, 
//so you should first get the representatives of these nodes and then take union of them 
Node* Union (int xVal , int yVal) ;

//Membership. i.e Do (xVal, yVal) belongs to same set 
bool isMember ( int xVal , int yVal) ;

//cardinality
int cardinality (int value) ;

//Print the path from given node to it's representative
void printNode ( Node* node) ;

//This will print path from each node to it's representative
//make use of printNode function
void printMap () ;

#endif