#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "List.h"

int operator(char x)
{
	if( x == '+' || x == '*' || x == '/' || x == '%' || x == '|' || x == '&' || x == '^' || x=='-')	return 1;
	else	return 0;
}

int operand(char ch)
{
    if (   (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ( ch >= '0' && ch <= '9')  )
    	return 1;
	return 0;
}

int prec(char ch)
{
    switch (ch)
    {
    	case '|':
    		return 0;
    	case '^':
    		return 1;
    	case '&':
    		return 2;
    	
    	case '+':
    	case '-':
    	    return 3;

	    case '*':
	    case '/':
	    case '%':
	        return 4;
    }
    return -1;
}

void main()
{
    int i;
    for ( i = 0 ; i < 10 ; i++)
    {
    	char arr[1000];
    
    	scanf("%[^\n]%*c", arr);
    
    	int j;
    
    	stack* S = stack_new();
    	
    	int len = strlen(arr);
    
    	//printf("%d\n",len);
    
    	for ( j = 0 ; j < len ; j++)
    	{
    	    if (operator(arr[j]))
    	    {
    	        while ( ( !stack_is_empty(S) ) && ( prec ( arr[j] ) <= prec ( S->top->head->data ) )  )
    	        {
    	            printf("%c ",stack_pop(S));
    	        }
    	        
    	        stack_push(S, arr[j]);
    	        
    	        j++ ;
    	    }
    	    
    	    else if( arr[j] == '(')
    	    
    	    {
    	        stack_push( S, arr[j]);
    	        j++;
    	    }
    	    
    	    else if( arr[j] == ')')
    	    
    	    {
    	        while (  !stack_is_empty(S) && (S->top->head->data != '(')  )
    	        {
    	            printf("%c ",stack_pop(S));
    	        }
    	        if(S->top->head->data == '(')
    	        {
    	        	stack_pop(S);
    	        }
   	     	}
   	     	
   	     	else if ( operand ( arr[j] ) )
        	
        	{	
        	    printf("%c",arr[j]);
        	    j++;
       		    for( ; ((arr[j] !=' ') && (j < (len)) ) ; j++)
     		    {
     	           printf("%c",arr[j]);
        	    }
            
      	        printf(" ");
        	}
        
    	}
    	
  		while(!stack_is_empty(S))
    	{
    	    
    	    printf("%c ",stack_pop(S));
    	}
    	
    	printf("\n");
    }
    
    return ;
}
