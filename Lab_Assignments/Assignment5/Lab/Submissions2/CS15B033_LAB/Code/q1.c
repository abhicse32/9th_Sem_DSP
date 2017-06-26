#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);		//testcases
	int i;
	char a[1000];		//string for input
	for(i=0; i<t; i++)
	{
		char A[1000];		//stack
		int top = -1;
		
		int flag = 1;	
	
		scanf("%s", a);
		int l = strlen(a);
		int j;
		for(j=0; j<l; j++)
		{
			switch( a[j])
			{
				case '(':
				case '[':
				case '{':{
							top++;
							A[top] = a[j];		// if it is open bracket, push in the stack.
							break;
						}
				case ')':
				case ']':
				case '}':{
							if(A[top] == '{' && a[j] == '}' || A[top] == '(' && a[j] == ')' || A[top] == '[' && a[j] == ']')
								top--;
							else			//else if it is closed and matches with last open, continues else it is not valid
								{
									flag = 0;
									break;
								}
							break;
						}
				}
			if( flag == 0)//exits once expression is not valid
				break;
		}
		if( top != -1)// if stack is not empty finally
			flag = 0;
		printf("%d\n", flag);
	}
	return 0;
}
