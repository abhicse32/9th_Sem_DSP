#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"

// create a new Node_BST
Node_BST* new_node(int key, int val){
	pair p;
	p.key= key;
	p.value= val;
	Node_BST* node=(Node_BST*)malloc(sizeof(Node_BST));
	node->data = p;
	node->left= node->right= NULL;
	return node;
}

//insert data in bst
Node_BST* insert(Node_BST* root, int key, int val){
	Node_BST* node= new_node(key,val);
	if(root==NULL)
		return node;
	Node_BST* temp= root;
	while(true){
		if((temp->data).key < key){
			if(temp->right==NULL){
				temp->right= node;
				break;
			}
			temp= temp->right;
		}else if((temp->data).key == key){
			(temp->data).value = val;
			break;
		}
		else{
			if(temp->left==NULL){
				temp->left= node;
				break;
			}
			temp= temp->left;
		}
	}
	return root;
}

// search for the given key in the bst and return 1 if found 0 otherwise
Node_BST* search(Node_BST*root, int key){
	if(!root)
		return NULL;
	if((root->data).key == key)
		return root;
	return (root->data).key < key ? search(root->right,key): 
							  search(root->left,key);
}
//inorder successor
Node_BST* inorder_succ(Node_BST* root){
	Node_BST* node= root;
	while(node->left)
		node = node->left;
	return node;
}

//delete the node with the given key
Node_BST* delete(Node_BST*root, int key){
	if(root){
		if(key < (root->data).key)
			root->left= delete(root->left,key);
		else if(key> (root->data).key)
			root->right= delete(root->right,key);
		else{
			if(root->left==NULL){
				Node_BST* temp= root;
				root= root->right;
				free(temp);
			}else if(root->right==NULL){
				Node_BST* temp= root;
				root= root->left;
				free(temp);
			}else{
				Node_BST* succ= inorder_succ(root->right);
				root->data= succ->data;
				root->right= delete(root->right,(succ->data).key);
			}
		}
	}
	return root;
}

// print inorder traversal of the tree
void inorder_traversal(Node_BST* root){
	if(!root)
		return;
	inorder_traversal(root->left);
	printf("%d ",(root->data).key);
	inorder_traversal(root->right);
}
