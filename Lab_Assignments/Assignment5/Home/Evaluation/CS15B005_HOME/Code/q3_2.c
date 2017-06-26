#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "List.h"

int operation ( int op1, int op2, char x)
{
    if( x == '+' )
       	return ( op1 + op2 );
    if( x == '-')
        return ( op1 - op2 );
    if( x == '*')
        return ( op1 * op2 );
    if( x == '/')
    	return ( op1 / op2 );
    if( x == '%')
    	return ( op1 % op2 );
    if( x == '|')
    	return ( op1 | op2 );
    if( x == '&')
    	return ( op1 & op2 );
    if( x == '^')
    	return ( op1 ^ op2 );
}

int operator(char x)
{
	if( x == '+' || x == '*' || x == '/' || x == '%' || x == '|' || x == '&' || x == '^' || x=='-')	return 1;
	else	return 0;
}

int number(char x)
{
	if ( (x=='0') || (x=='1') || (x=='2') || (x=='3') || (x=='4') || (x=='5') || (x=='6') || (x=='7') || (x=='8') || (x=='9') )	return 1;
	else	return 0;
}

void main()
{
	int i=0;
	
	while ( i != 10)
	{
		char arr[100];
		
		scanf("%[^\n]%*c", arr);
		
		int len = strlen(arr);
		
		int j;
		
		stack* S = stack_new();
		
		for ( j = 0  ;  j < len  ;  j++)
		{
			if ( number ( arr[j] ) )
			{
				int temp = arr[j] - 48 ;
				
				stack_push ( S, temp );
				
				j++;
				
				for ( ;  arr[j] != ' ' ; j++)
				{
					int temp = 10*stack_pop(S) + arr[j] - 48;
					
					stack_push ( S , temp );					
				}
			}
			else if ( ( arr[j] == '-' ) && ( number( arr[j+1] ) ) )
			{
				stack_push ( S , arr[j+1] - 48 );
				
				j = j+2;
				
				for ( ;  arr[j] != ' ' ; j++)
				{
					int temp = 10*stack_pop(S) + arr[j] - 48;
					stack_push ( S, temp );	
				}
				
				stack_push( S , - stack_pop(S));
			}
			else if ( operator ( arr[j] ))
			{
				int temp = operation ( stack_pop(S) , stack_pop(S) , arr[j] );
				stack_push ( S , temp );
			}
		}
		
		stack_print( S );
		printf("\n");
		i++;			
	}
	return ;
}
