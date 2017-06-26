#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"
#include "stack.h"
#include "queue.h"
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
	
	
	stack *S=stack_new();
	queue *Q=queue_new();
	Node* x=root;
	enqueue(Q,x);
	Node* senti=new_node("#"); 		//# sentinel to define a level
	enqueue(Q,senti);
	while(1)
	{
		x=dequeue(Q);
		if(x==NULL)
			break;
		if(x->data[0]=='#'&&!queue_is_empty(Q)) 		//if element is # push a # to end(except for final #)
		{
			enqueue(Q,new_node("#"));
			stack_push(S,x);
		
			continue;
		}
		
		stack_push(S,x);
		if(x->right!=NULL)
			enqueue(Q,x->right);
		if(x->left!=NULL)
			enqueue(Q,x->left);


	}
	x=stack_pop(S); 			//to pop out first #



	while(!(stack_is_empty(S)))
	{
		x=stack_pop(S);
		if(x->data[0]=='#')
			printf("\n");
		else
			printf("%s ",x->data);
	}
			

}

