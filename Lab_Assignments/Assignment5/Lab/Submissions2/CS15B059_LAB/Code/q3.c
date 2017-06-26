/*
        K ALEKHYA REDDY
        CS15B059
        16SEPT16
        USING ONLY STACKS TO FIND THE NEXT GREATEST NUMBER
        */
#include<stdio.h>
#include"stack.h"
//using a stack to store the indices
void print(stack *popped, stack * pushed, int *a,int n );
void main()
{
	int t;
	scanf("%d",&t); //stores the number of test cases
	int i;
	for(i=0;i<t;i++)
	{
		int n;  //the size of each test case
		scanf("%d",&n);
		int j,a[n];
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);      //input all the elements of a test case
		}
	
	
	stack* present =stack_new();    //contains the present indices
	stack* popped=stack_new();      //contains the popped indices
	stack* pushed=stack_new();      //contains the indices of the element due to which it got popped
	
	int i;
	for(i=0;i<n;i++)
	{
	        int x,y;
	        if(stack_is_empty(present))
	        {
	        stack_push(present,i);        //first element to be inserted then push it
	        }        
	        else
	        {
	                x=stack_pop(present);
	                if(a[x]>a[i])
	                {
	                        stack_push(present,x);
	                        stack_push(present,i);        //if the element to be inserted is lesser than the popped element just push the new element as well
	                }
	                else
	                {
	                        
	                        while(a[x]<a[i])        //pop all elements which are lesser than this 
	                        {
	                            
	                                
	                                stack_push(popped,x);   //push the popped index
	                                stack_push(pushed,a[i]);        //push the value which popped the other number
	                        
	                                if(present->top->head!=NULL)
	                                {
	                                x=stack_pop(present);
	                                }
	                                else
	                                break;
	                        }
	                        if(a[x]>=a[i])
	                        {
	                        stack_push(present,x);
	                        stack_push(present,i);  //because we already popped an element we have to push it now
	                        }
	                        else
	                        stack_push(present,i);
	                     
	                        
	                                 //if the element to the be inserted is greater then pop all the elements till you encounter an element of greater value
	                }
	                
	        }
	  
	}
	
	while( !stack_is_empty(present))
	{
	        int p;
	        p=stack_pop(present);
	        stack_push(popped,p);   //pop the index and store it in popped stack
	        stack_push(pushed,-1);
	}
	
	print(popped,pushed,a,n);   //function which prints the elements
	}
}

//function prints all the elements 
void print(stack *popped, stack * pushed, int *a,int n )
{
        int x,y;
        while(!stack_is_empty(popped)) //till the stacks become empty
        {
                x=stack_pop(popped);
                y=stack_pop(pushed);
                a[x]=y;//changes the array 
        }
        
        int i;
        for(i=0;i<n;i++)
        {
                printf("%d ",a[i]);     //prints all the elements
        }
        printf("\n");
}








