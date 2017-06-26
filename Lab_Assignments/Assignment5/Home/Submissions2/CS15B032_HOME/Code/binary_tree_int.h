
#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct Node_ {
	int data;
	struct Node_ *left;
	struct Node_ *right;	
} Node;

//Creating a new node with given data
Node* new_node(int data);

//Print post-order traversal of a binary tree
void print_postorder(Node* root);

//Print in-order traversal of a binary tree
void print_inorder(Node* root);

//Print pre-order traversal of a binary tree
void print_preorder(Node* root);


#endif