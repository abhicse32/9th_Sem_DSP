#ifndef BST_H
#define BST_H
#include <stdbool.h>

typedef struct Node_BST{
	int data;
	struct Node_BST *left;
	struct Node_BST *right;
}Node_BST;

// create a new Node_BST
Node_BST* new_node(int);

//insert data in bst
Node_BST* insert(Node_BST*, int data);

//find the node with the maximum value and return the key(-1 if root is null)
int find_max(Node_BST*);

//find the node with the minimum value and return the key(-1 if root is null)
int find_min(Node_BST*);

// print level-wise traversal of the tree
void print_level_wise(Node_BST*);

// search for the given key in the bst and return 1 if found 0 otherwise
Node_BST* search(Node_BST*, int);

//delete the node with the given key
Node_BST* delete(Node_BST*, int);

// print the inorder travesal of the tree
void inorder_traversal(Node_BST*);
#endif
