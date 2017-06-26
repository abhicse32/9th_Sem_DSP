/*
 * Author: Pramod Munemanik
 * Binary Tree data structure
 * Date: 20-9-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 #include <string.h>
#include "binary_tree.h"


//Creating a new node with given data
Node* new_node(char* data){
	Node* node;
	node = (Node*)malloc(sizeof(Node));
	node->data = strdup(data);
	node->left = NULL;
	node->right = NULL;
	return node;
}

//Print post-order traversal of a binary tree
void print_postorder(Node* root){
	
	if(root==NULL) return;
	
	print_postorder(root->left);
	print_postorder(root->right);
	
	printf("%s ",root->data);
}

//Print pre-order traversal of a binary tree
void print_preorder(Node* root){
	
	if(root==NULL) return;
	
	printf("%s ",root->data);	
	
	print_preorder(root->left);
	print_preorder(root->right);	
}
