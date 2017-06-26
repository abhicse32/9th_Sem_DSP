#include<stdio.h>
#include"stack.h"
#include<string.h>

int main()
{
	int t;
	int i;
	scanf("%d",&t);
	//Initialize stack
	stack *S = stack_new() ;
	//Iterate for each testcase
	for(i=0;i<t;i++)
	{
		int j; 		
		char exp[10000] ;
		//Take input expression
		scanf("%s",exp);
		
		int steps = 0 ;
		int exp_l = strlen(exp) ;
		//In final exp -->   some no. of }}}... followed by {{{...
		//count1 --> no. of } in final exp
		//count2 --> no. of { in final exp		
		//{ & } are of same parity in final exp
		int count1=0,count2=0 ;
		//If string length is odd --> cannot be balanced 
		if(strlen(exp) % 2 != 0)
		{
			steps = -1 ;
		}
		else
		{		
			for(j=0;j<exp_l;j++)
			{
				//Push an {
				if(exp[j] == '{')
				{
					stack_push(S,(int)exp[j]) ;
					count2++;
				}
				//If character is } --> a)Pop if stack top is { 
				//b)Push otherwise
				else if(stack_is_empty(S) == false)
				{			
					if(exp[j] == '}' && S->top->head->data ==(int)'{' )
					{
						int x = stack_pop(S) ;
						count2-- ;
					}
					else
					{
						stack_push(S,(int)exp[j]) ;
						count1++ ;	
					}				
				}
				else
				{
					stack_push(S,(int)exp[j]) ;
					count1++ ;	
				}				
			}
			//If both count of { & } are even reverse half brackets of each part
			if(count1 % 2 == 0 && count2 % 2 == 0)
			{
				steps = count1/2 + count2/2 ;
			}
			//If both count of { & } are odd --> Reverse 1st and last(+2) & again apply even case for remaining
			else
			{
				steps = count1/2 + count2/2 + 2 ;
			}
			
		}
		//Empty stack
		while(stack_is_empty(S) ==false)
			stack_pop(S);
		//Print answer
		printf("%d\n",steps);		
	}
}
