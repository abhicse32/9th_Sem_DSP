#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node{
	char data;
	Node* left,*right;
};

Node* new_node(char data){
	Node* node= (Node*)malloc(sizeof(Node));
	node->data= data;
	node->left= node->right= NULL;
	return node;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	printf("%c",root->data);
	inorder(root->right);
}

void preorder(Node* root){
	if(!root)
		return;
	printf("%c",root->data);
	preorder(root->left);
	preorder(root->right);
}

Node* insert(Node* root, char data){
	if(!root)
		return new_node(data);
	else if(data <= root->data)
		root->left= insert(root->left,data);
	else root->right= insert(root->right,data);

}

int main(){
	Node* root=NULL;
	char buff[100];
	scanf("%s",buff);
	int len= strlen(buff);
	for(int i=0;i<len;++i)
		root= insert(root,buff[i]);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
}
