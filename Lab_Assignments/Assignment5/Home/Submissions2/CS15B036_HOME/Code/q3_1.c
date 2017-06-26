#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"stack.h"
int main()
{
	char *arr=(char*)malloc(100*(sizeof(char)));
	char temp;
	gets(arr);
	int i=0,j=0;
	stack *S = stack_new();
	while(arr[i]!='\0')
	{
		if((int)arr[i]<123&&(int)arr[i]>96)
		{
			while((int)arr[i]!=32)
			{
			printf("%c",arr[i]);
			i++;
			}
			printf(" ");
		}
		else if(arr[i]==')')
		{
			while(stack_size!=0)
			{
				
				temp=(char)stack_pop(S);
				if(temp=='(')
				break;
				printf("%c ",temp);
			}
				
		}
		else
		{
			if((int)arr[i]!=32)
			stack_push(S,(int)arr[i]);
		}
	i++;
	}

	while(stack_size(S)!=0)
	{
		temp=(char)stack_pop(S);
		if(temp!='(')
		printf("%c ",temp);
	}
	printf("\n");
return 0;
}
