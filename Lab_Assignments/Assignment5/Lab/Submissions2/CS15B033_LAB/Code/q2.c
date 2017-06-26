#include <stdio.h>
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
		
		int count = 0;	
	
		scanf("%s", a);
		int l = strlen(a);
		
		if( l%2 != 0)		//if number of chars is odd, then it is not valid.
			printf("-1\n");
		else
		{
			int j;
			for(j=0; j<l; j++)
			{
				switch( a[j])
				{
					case '{':{
								top++;
								A[top] = a[j];		// if it is open bracket, push in the stack.
								break;
							}
					case '}':{
								if( top != -1 && A[top] == '{' && a[j] == '}')
									top--;
								else			//else if it is closed and matches with last open, continues else filps and pushes into stack
									{
										if( top == -1)
										{
											count ++;
											top++;
											A[top] = '{';
										}
									}
								break;
							}
					}
			}
			if( top != -1)// if stack is not empty finally , half of the chars are reversed
				count += (top+1)/2;
			printf("%d\n", count);
			
		}
	}
	return 0;
}
