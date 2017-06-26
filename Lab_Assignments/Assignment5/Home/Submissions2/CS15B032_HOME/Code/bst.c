#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"
#include "queue.h"

// create a new Node_BST
Node_BST* new_node(int data)
{
  Node_BST *newnode;
  newnode=(Node_BST*)malloc(sizeof(Node_BST));
  if(newnode==NULL)
  printf("MALLOC ERROR");
  else
  {
    newnode->data=data;
    newnode->left=NULL;
    newnode->right =NULL;
  }
}

//insert data in bst
Node_BST* insert(Node_BST* node, int data)
{
  if(node==NULL)
  return new_node(data);
  if(data<node->data)
     node->left=insert(node->left,data);
  else if(data>node->data)
     node->right=insert(node->right,data);
  return node;
}

//find the node with the maximum value and return the key(-1 if root is null)
int find_max(Node_BST* root)
{
  if(root==NULL) return -1;
  else
  while(root->right!=NULL)
  {
    root=root->right;
  }
  return root->data;
}

//find the node with the minimum value and return the key(-1 if root is null)
int find_min(Node_BST* root)
{
if(root==NULL) return -1;
  else
  while(root->left!=NULL)
  {
    root=root->left;
  }
  return root->data;
}


// print level-wise traversal of the tree
void print_level_wise(Node_BST* root)
{
  queue *q;
  q=queue_new();
  Node_BST* x;
  x=(Node_BST*)malloc(sizeof(Node_BST));
  x=root;
  if(x!=NULL)
  {
  enqueue(q,x);
  while(1)
  {
    //x=dequeue(q);
    //if(x==NULL)
    //break;
    //printf(""x->data);
    int count = queue_size(q);
    if (count == 0)
    break;
        for(;count > 0;count--)
        {
            x = dequeue(q);
            int val = x->data;
            printf("%d ",val);
            //enqueue(q, data)
            if (x->left != NULL)
                enqueue(q,x->left);
            if (x->right != NULL)
                enqueue(q,x->right);
        }
        printf("\n");

}
}
}

// search for the given key in the bst and return 1 if found 0 otherwise
Node_BST* search(Node_BST* root, int key)
{
     if (root == NULL || root->data == key)
       return root;
    if (root->data < key)
       return search(root->right, key);
    else if(root->data > key)
    return search(root->left, key);
   /*if(node==NULL)
  return NULL;
  if(node->data==key)
  return node;
  else if(node->data>key)
   search(node->left,key);
  else if(node->data<key)
   search(node->left,key);*/
  
}
//delete the node with the given key
Node_BST* delete(Node_BST* root, int key)
{
   if(root==NULL)
   return root ;
    if(key<root->data)
     root->left=delete(root->left,key);
   else if(key>root->data)
     root->right=delete(root->right,key);
      else if(key==root->data)
   {
    if(root->left==NULL&&root->right==NULL)
    return NULL;
     else if (root->left==NULL)
        return root->right;
     else if (root->right==NULL)
        return root->left;
      
  int min =find_min(root->right);
  root->data=min;
  root->right=delete(root->right,min);
   }
   return root;   
}

// print the inorder travesal of the tree
void inorder_traversal(Node_BST* root)
{
  if(root!=NULL)
  {
     inorder_traversal(root->left);
     printf("%d \n",root->data);
     inorder_traversal(root->right);
  }
}

