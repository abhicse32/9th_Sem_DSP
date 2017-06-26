#include<stdio.h>
#include<stdlib.h>
#include "stack.h"


int main()
{
	int l;   			//number of test cases
	scanf("%d",&l);

     int z;
	     
     char x1 = getchar();

	for(z=0;z<l;z++)
	
		{
		  stack* S;

	S = stack_new();
     
     x1 = getchar();

	while(x1 != '\n')
		
		{
		  stack_push(S, x1);
		  x1 = getchar();
		}
		  
		  	if(stack_size(S) % 2 == 1) printf("-1\n");

    else

		{   
		    int i, j, k, x;
			x = 0;
			i = 0;
			j = 0;

		 	char z;
		 		 z = stack_pop(S);   
		     if(z == '{') x++;
		      j++;

			int size = stack_size(S);
	        for(k = 2; k<=size; k++)
			
			  {
			    z = stack_pop(S);
				if(z == '{') i++;
				if(z == '}') j++;
				if( i > j) {x++; i--; j++;}
			  }
			 z = stack_pop(S);   
		     if(z == '}')   x++; 
		     i++;
		     x = x+abs(j-i)/2;

			printf("%d\n",x);
		}
		}
}



