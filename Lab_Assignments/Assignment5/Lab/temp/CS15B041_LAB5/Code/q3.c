#include<stdio.h>

void print(stack* ss)
		{	int x;
			while(!stack_is_empty(ss))
			{
				x=stack_pop(ss);
				printf("%d ",x);
			}			
		}


int main()
{	
	
	int test;
	int j=0;
 	int i=0;
	int num;
	scanf("%d",&test);

	stack* s;
	s=stack_new();

	//test cases
	for(i=0;i<test;i++)
	{	
		scanf("%d",&num);
		int a[num];
		for(j=0;j<num;j++)
		{
			scanf("%d",&a[j]);
		}
		stack* s;
		s=stack_new();
		int k,l;
		for(k=0;k<num-1;k++)
		{
			for(l=k+1;l<num;l++)
			{
				if(a[l]>a[k])
				{
				stack_push(s, a[l]);
				break;	
				}
				else
				stack_push(s,-1);
			}
		}
						
		
		
		
	}

	stack_push(s,-1);
		print(s);
			

					
}


						
			
		
















	
			
			
				
		
		

	

