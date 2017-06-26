#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include"stack.h"
int main()
{
	char *arr=(char*)malloc(100*(sizeof(char)));
	gets(arr);
	
	int i=0;
	char temp;
	stack *S=stack_new();
	while(arr[i]!='\0')
	{
		if((int)arr[i]<58 && (int)arr[i]>47)
		{
			stack_push(S,(int)arr[i]-48);
		}
		else if(arr[i]!=' ')
		{
		int x = stack_pop(S);
		int y = stack_pop(S);
		switch(arr[i])
		{
		case '+' :
		stack_push(S,x+y);
		break;
		case '-' :
	  	stack_push(S,y-x);
		break;
		case '*' :
		stack_push(S,x*y);
		break;
		case '/' :
		stack_push(S,y/x);
		break;
		}
		}
	i++;
	}
printf("\n%d",stack_pop(S));
return 0;
}
