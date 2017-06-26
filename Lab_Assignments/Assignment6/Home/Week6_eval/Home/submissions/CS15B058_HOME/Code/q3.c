//Program to print vertical order of tree, Author: B Arjun, CS15B058
#include <stdio.h>
#include "binary_tree1.h"
#include "stack.h"
#include "queue.h"
#include "List.h"
#include <string.h>
#include <stdlib.h>
void itoa(int x,char *s) //function to convert integer to string
{

	sprintf(s,"%d\0",x);	
}

void recfind(int arr[],int index,Node* bt,int n) //function to construct tree
{
	int i;
	int flag=0;
	for(i=0;i<3*n&&flag!=2;i+=3) 		//flag becomes 2 if both children already found
	{
		if(arr[i]==arr[index+1]&&arr[index+1]!=0)
		{
				char s[100];
				itoa(arr[i],s);
				bt->left=new_node(s);
				flag++;
				recfind(arr,i,bt->left,n);
		}
		if(arr[i]==arr[index+2]&&arr[index+2]!=0)
		{
				char s[100];
				itoa(arr[i],s);
				bt->right=new_node(s);
				flag++;
				recfind(arr,i,bt->right,n);
		}
	}	
}

void setvertorder(Node* bt,int v,int *maxv,int *minv) 		//to set vertical order for all elements
{
	if(bt!=NULL)
	{
		bt->verticalorder=v;
		if(v>*maxv)
			*maxv=v;
		if(v<*minv)
			*minv=v;
		setvertorder(bt->left,v-1,maxv,minv);
		setvertorder(bt->right,v+1,maxv,minv);
	}
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int *arr=(int*)malloc(3*n*sizeof(int)); 	
	int i;
	scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
	char s[100];
	itoa(arr[0],s);
	Node* root=new_node(s);
	
	for(i=3;i<3*n;i+=3)
		scanf("%d %d %d",&arr[i],&arr[i+1],&arr[i+2]);
	recfind(arr,0,root,n);

	int maxv=0,minv=0; 					//to store least order and highest order
	setvertorder(root,0,&maxv,&minv);
	queue **qarray=(queue**)malloc((maxv-minv+1)*sizeof(queue*)); 		//array of queues
	for(i=0;i<maxv-minv+1;i++)
		qarray[i]=queue_new();
	queue *Q=queue_new();
	Node* x=root;
	enqueue(Q,x);
	while(1) 					//level order traversal to get correct order for printing
	{
		x=dequeue(Q);
		if(x==NULL)
			break;		
		enqueue(qarray[x->verticalorder-minv],x);
		if(x->left!=NULL)
			enqueue(Q,x->left);
		if(x->right!=NULL)
			enqueue(Q,x->right);
	}
	for(i=0;i<maxv-minv+1;i++)
	{
		queue_print(qarray[i]);
		printf("\n");
	}

	return 0;
}