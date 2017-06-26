#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include"stack.h"
void printnextmax(int k,int array[1000]);
void main()
{
    int n;
    scanf("%d",&n);
    int i;
    int j;
    for(i = 0;i < n;i++)
    {
        int k;
        scanf("%d",&k);
        int array[1000];
        for(j = 0;j < k;j++)
        {
            scanf("%d",&array[j]);
        }
        printnextmax(k,array);
     }
}
void printnextmax(int k,int array[1000])
{
    int temp;
    int pop;
    int c;
    stack *stack = stack_new();
    stack_push(stack,array[0]);
    int auxarray[1000];
    for(c = 0;c<k;c++)
    {
    	auxarray[c] = -1;
    }
    int i;
    int j;
    for(i = 1;i<k;i++)
    {	
    	temp = array[i];
    	if(stack_is_empty(stack) == false)
    	{
    		pop = stack_pop(stack);
    		while(pop < temp)
    		{
    			j = 0;
    			for(j = 0;j<k;j++)
    			{
    				if(array[j] == pop)
    				{
    					if(auxarray[j] == -1)
    					{
    						auxarray[j] = temp;
    						break;
    					}
    					
    				}
    			}
    			if(stack_is_empty(stack) == true)
    			{
    				break;
    			}
    			pop = stack_pop(stack);
    		}
    		if(pop >= temp)
    		{
    			stack_push(stack,pop);
    		}
    	}
    	stack_push(stack,temp);
    }
    int l;
    for(l = 0;l<k;l++)
    {
    	printf("%d ",auxarray[l]);
   	}
   	printf("\n");
}
     
