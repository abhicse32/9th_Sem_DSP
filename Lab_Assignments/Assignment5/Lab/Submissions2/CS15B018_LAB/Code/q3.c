#include<stdio.h>
#include"List.h"
#include"stack.h"
 
void print(int arr[], int n)
{
	//stack for storing next greater element 
    	stack *s = stack_new();
    	
    	//staack for storing its index
    	stack *s1 = stack_new();
    	int element, next,index;
    	int result[n];
    	int flag= 0; 
    	int i = 0; 
    	for (i=0; i<n; i++)
    	{
    		//first return -1 for every element
    		result[i] = -1;
    		if(stack_is_empty(s))	{
    						stack_push(s,arr[i]);
    						stack_push(s1,i);
    						continue;
    					}
    						
        	next = arr[i];
        	if (!stack_is_empty(s))
        	{
        	    	element = stack_pop(s);
        	    	index = stack_pop(s1);
 			while (element < next)
            		{
            			//if next > element
            			//pop element
				result[index] = next;            		
                		if(!stack_is_empty(s))
                		{
                		  element = stack_pop(s);
                		  index = stack_pop(s1);
                		}
                		//if the element is popped,index also gets popped
                		
                		else 
                		{
                			flag=1;
                			break;
                		}
            		}
 			
            		if (flag==0)
            	    	{
            	    		stack_push(s, element);
            	    		stack_push(s1, index);
            	    	}
        	}
        	//push next and store it 
        	stack_push(s, next);
        	stack_push(s1, i);
        	flag = 0;
    	}
    	
    	// print the result
    	for(i=0;i<n;i++)	printf("%d ",result[i]);
    	printf("\n");	
}

int main()
{
	int i, t;
	
	//no. of test cases
	scanf("%d",&t);
	for(i = 0; i < t; i++)
	{
		int j, n;
		scanf("%d",&n);
		int a[n];
		for(j = 0; j < n; j++) 
		{
			scanf("%d",&a[j]);
		}
		print(a, n);
	}
	return 0;
}
