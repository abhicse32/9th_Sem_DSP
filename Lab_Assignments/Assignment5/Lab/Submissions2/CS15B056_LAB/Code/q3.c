//TO FIND THE NEXT MAX ELEMENT IN ARRAY
//AUTHOR-SARTHAK PANDEY
//CS15B056
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "List.h"
#include "stack.h"

int main()
{
	int n,j,i;
	scanf("%d",&n);
	stack *stk_tra,*stk_popin,*stk_val;                                                           //WE MAINTAIN 3 STACKS CONTAINING TRAVERSAL INDEX ,POP INDEX AND VALUE
	stk_tra=stack_new();
	stk_popin=stack_new();
	stk_val=stack_new();
	
	for(j=0;j<n;j++)
	{
		int k;
		scanf("%d",&k);
		int a[k],ans[k];
		for(i=0;i<k;i++)
			scanf("%d",&a[i]);
		for (i=0;i<k;i++)
		{	
			if (stack_size(stk_tra)!=0)                                                   //IF TRAVERSAL STACK IS NOT EMPTY,WE COMPARE THE CURRENT ARRAY ELEMENT WITH TRAVERSAL CORRESPONDIN
			{									      //ARRAY VALUE
				int m=a[stk_tra->top->head->data];
				while (a[i]>m&&stack_size(stk_tra)!=0)
				{
					stack_push(stk_popin,stack_pop(stk_tra));                     //TILL CURR>TRAVERSAL VAL, WE PUT CURR IN VALUE STACK
					stack_push(stk_val,a[i]);
					if (stack_size(stk_tra)==0)
						break;
					else
						m=a[stk_tra->top->head->data];
				}
			}
			
			stack_push(stk_tra,i);                                                        //WE INSERT CURRENT ELEMENT INDEX IN TRAVERSAL STACK
				
		}
		while(stack_size(stk_tra)!=0)
		{
			stack_push(stk_val,-1);
			stack_push(stk_popin,stack_pop(stk_tra));                                     //WE COMPLETE POP AND VAL STACKS HERE
		}
		
		while(stack_size(stk_popin)!=0)
		{
			ans[stack_pop(stk_popin)]=stack_pop(stk_val);                                 //STORE THE VALUES IN ANS ARRAY
		}
		for(i=0;i<k;i++)
			printf("%d ",ans[i]);                                                         //PRINTING ANS ARRAY
		printf("\n");
		while(stack_size(stk_tra)!=0)
			stack_pop(stk_tra);                                                           //CLEARING TRAVERSAL STACK(NOT NECESSARY,JUST AS PRECAUTION)
	}
	return 0;
	
	
}
			
		
			
	
