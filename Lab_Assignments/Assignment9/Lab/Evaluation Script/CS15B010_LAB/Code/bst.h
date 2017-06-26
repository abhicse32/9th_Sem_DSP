#ifndef BST_H
#define BST_H

typedef struct Node_ pair;
struct Node_{
	int key;
	int value;
};

typedef struct Node_BST{
	pair data;
	struct Node_BST *left;
	struct Node_BST *right;
}Node_BST;

// create a new Node_BST
Node_BST* new_node(int, int);

//insert data in bst
Node_BST* insert(Node_BST*, int , int);

// search for the given key in the bst and return the node if found, NULL otherwise
Node_BST* search(Node_BST*, int);

//delete the node with the given key
Node_BST* delete(Node_BST*, int);

// inorder successor
Node_BST* inorder_succ(Node_BST*);

// print the inorder travesal of the tree
void inorder_traversal(Node_BST*);
#endif