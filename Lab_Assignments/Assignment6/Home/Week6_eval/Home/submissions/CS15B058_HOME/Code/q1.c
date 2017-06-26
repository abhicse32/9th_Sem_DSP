#include <stdio.h>
#include "binary_tree1.h"
#include "stack.h"
#include <string.h>
#include "List1.h"
#include <ctype.h>
typedef struct huff_
{
	char *huffstr;
	int hufffreq;
}huffman;
/*Function to swap two numbers(For quickSort)*/
void swap(huffman *a1,huffman *a2)
{
	huffman temp=*a1;
	*a1=*a2;
	*a2=temp;
}

void quickSort(huffman a[],int i1,int i2)
{
	if(i1!=i2)					//Base case:i1==i2 means 1 element
	{
		int pivot=a[i1].hufffreq;			//We take the start index of the array as pivot
		int pivotpos=i1;
		int j1=i1+1,j2=i2;			//j1 and j2 are indices to traverse array from both sides to swap elements
		while(j1<j2)			//if j1>=j2, the array has been partitioned to (less than pivot),pivot,(greater than pivot)
		{
			if(a[j1].hufffreq<pivot&&a[j2].hufffreq>pivot)
				{
					j1++;
					j2--;
				}
			else if(a[j1].hufffreq<pivot)
				j1++;
			else if(a[j2].hufffreq>pivot)
				j2--;
			else
			{
				swap(&a[j1],&a[j2]);		//When a[j1]>=pivot and a[j2]<=pivot we swap them
				j1++;j2--;
			}	

		}
		if(a[j1].hufffreq<=pivot)				//To place the pivot in between the 2 parts
		{
			swap(&a[i1],&a[j1]);			//Either it will be at j1 or j1-1
			pivotpos=j1;

		}
		else 
		{
			swap(&a[i1],&a[j1-1]);
			pivotpos=j1-1;
		}

		if(pivotpos!=i1)				//If after arranging pivot is at start index we dont have to shift it
		quickSort(a,i1,pivotpos-1);		//recursive call to sort the partition 1
		if(pivotpos!=i2)				//If after arranging pivot is at last index we dont have to shift it
		quickSort(a,pivotpos+1,i2);		//recursive call to sort the partition 2


	}

}
void printhuff(Node* T,char* a)
{
	if(!(T->data[0]=='#'&&strlen(T->data)==1))
	{
		printf("%s: %s\n",T->data,a);
	}
	else
	{
		int l=strlen(a);
		a[l]='0';
		a[l+1]='\0';
		printhuff(T->left,a);
		a[l]='1';
		a[l+1]='\0';
		printhuff(T->right,a);
	}
}

int main()
{
	char str[1000];
	fgets(str,999,stdin);
	int l=strlen(str);
	str[l-1]='\0';
	//printf("%s",str);
	huffman dataset[100];
	int i=0;
	dataset[i].huffstr=strtok(str," ");
	while(dataset[i].huffstr!=NULL)
	{
		
		//printf("%s ",dataset[i].huffstr);
		i++;
		dataset[i].huffstr=strtok(NULL," ");
	}
	int n=i;
	for(i=0;i<n;i++)
		scanf("%d",&dataset[i].hufffreq);
	//for(i=0;i<n;i++)
	//	printf("%s %d\n",dataset[i].huffstr,dataset[i].hufffreq);
	quickSort(dataset,0,n-1);
	LList *nodelist=llist_new();
	for(i=0;i<n;i++)
	{
		Node* data=new_node(dataset[i].huffstr);
		data->verticalorder=dataset[i].hufffreq;
		llist_append(nodelist,data);
	}
	//llist_print(nodelist);
	while(llist_size(nodelist)>1)
	{
		Node* neweledata=new_node("#");
		neweledata->verticalorder=nodelist->head->data->verticalorder+nodelist->head->next->data->verticalorder;
		neweledata->left=nodelist->head->data;
		neweledata->right=nodelist->head->next->data;
		list* newele=node_new(neweledata);
		llist_remove_first(nodelist);
		llist_remove_first(nodelist);
		list* np=nodelist->head;
		if(np!=NULL)
		{
			while(np->next!=NULL)
			{
				if(np->next->data->verticalorder>neweledata->verticalorder)
					break;
				np=np->next;
			}

			list* temp=np->next;
			np->next=newele;
			newele->next=temp;
		}
		else
			nodelist->head=newele;
	}
	//	print_preorder(nodelist->head->data);
	char bincode[100];
	bincode[0]='\0';
	printhuff(nodelist->head->data,bincode);




}