#include<stdio.h>
#include<string.h>
#include "stack.h"
#include "List.h"
int check(char c,char d)
{
	if(c=='('&& d==')')
	return 1;
	else if(c=='['&& d==']')
	return 1;
	else if(c=='{'&& d=='}')
	return 1;
	else return 0;
}
	

int para(char arr[])
{
	int i=0,t;
	char temp;
	stack *str = stack_new();
	while(arr[i])
	{
		if(arr[i]=='{'||arr[i]=='('||arr[i]=='[')
		{
			stack_push(str,arr[i]);
		}
		if(arr[i]=='}'||arr[i]==')'||arr[i]==']')
		{
			if(stack_size(str)==0)
			return 0;
			else
			{
				temp=(char)stack_pop(str);
				t=check(temp,arr[i]);
				if(t==0)
				return 0;
				
			}
		}
		i++;
	}

	if(stack_size(str)==0)	return 1;
	else return 0;

}

 int main()
{
	int t,z;
	scanf("%d",&t);
	for(z=0;z<t;z++)
{
	char arr[1005] ;
	

	
	
	scanf("%s", arr) ;
	
//	printf("%s\n" , arr);

	int q = para(arr);
	if(q==1)	printf("1\n");
	else		printf("0\n");
}
	return 0;
}
