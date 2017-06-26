/*
 * Author: Pramod Munemanik
 * Binary Tree data structure
 * Date: 20-9-16
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct Node_ {
	char* data;
	struct Node_ *left;
	struct Node_ *right;
	int verticalorder;	
} Node;

//Creating a new node with given data
Node* new_node(char* data);

//Print post-order traversal of a binary tree
void print_postorder(Node* root);

//Print pre-order traversal of a binary tree
void print_preorder(Node* root);


#endif

