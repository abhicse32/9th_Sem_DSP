/*
 * Author: Pramod Munemanik
 * Binary Tree data structure
 * Date: 20-9-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree_int.h"


//Creating a new node with given data
Node* new_node(int data){
	Node* node;
	node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//Print in-order traversal of a binary tree
void print_inorder(Node* root){
	
	if(root==NULL) return;
	
	print_postorder(root->left);
	printf("%d ",root->data);
	print_postorder(root->right);

}

//Print post-order traversal of a binary tree
void print_postorder(Node* root){
	
	if(root==NULL) return;
	
	print_postorder(root->left);
	print_postorder(root->right);
	
	printf("%d ",root->data);
}

//Print pre-order traversal of a binary tree
void print_preorder(Node* root){
	
	if(root==NULL) return;
	
	printf("%d ",root->data);	
	
	print_preorder(root->left);
	print_preorder(root->right);	
}
