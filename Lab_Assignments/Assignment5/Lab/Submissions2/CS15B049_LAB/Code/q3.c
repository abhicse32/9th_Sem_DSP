/*
* Lab assignment 5 q3
* cs15b049 lokesh koshale

*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"

//to find next large element
void nextG(int a[],int n);

int main()
{
	//test cases	
	int t;
	scanf("%d",&t);

	//iterarting for t times
	while(t>0)
	{
		//no of elements	
		int n;
		scanf("%d",&n);
		
		int a[n];  //to store input elements
		int i;     //counter

		//input array elemnts
		for(i=0;i<n;i++)	
		{
			scanf("%d",&a[i]);
		}
		
		//function to find next large elemnt
		nextG(a,n);
		
		printf("\n");	//next line
		
		t--;

	}//end while

}//end main

//to find and print next large element
void nextG(int a[],int n)
{

	int b[n];	//temporary array to store next large of element at index

	stack* s = stack_new();		//new satck
	
	stack_push(s,0);	//pushing the first index =0

	int i;			//counter

	int curr,pop;		//curr value of array elemnt and poped value from stack

	//traverse till last 
	for(i=1;i<n;i++)
	{
		//stack is not empty 
		if(stack_is_empty(s)==false)
		{
			pop = stack_pop(s);	//pop from satck
		
			curr = a[i];		//curr is a[i]
	
			//if curr is greater than poped
			while(curr > a[pop])
			{
				b[pop]=curr;	//next large element is current
			
				//satck empty break
				if(stack_is_empty(s)==true)
				{
					break;
				}
								
				pop = stack_pop(s); //not empty pop again				
			}
			
			//if curr is less than or equal to pop push pop back in stack
			if(curr<=a[pop])
			{
				stack_push(s,pop);		
			}//end if	
	
		}//end if	

		stack_push(s,i); //push curr in stack to find next large of it
	
	}//end for

	
	//if there are still elemnts in stack 
	while(stack_is_empty(s)==false)
	{
		int x = stack_pop(s);  //pop them and assign -1
		b[x] = -1;
	}

	//print the next large elements
	for(i=0;i<n;i++)
	{
		printf("%d ",b[i]);		
	}

}//end fn


