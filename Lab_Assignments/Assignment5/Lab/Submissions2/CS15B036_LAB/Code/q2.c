#include<stdio.h>
#include"stack.h"
int main()
{
int test,z;
scanf("%d",&test);
for(z=0;z<test;z++)
{
char arr[1005];
scanf("%s",&arr);
int t=0,i=0;
while(arr[i]!='\0')
{
	t++;
	i++;
}
stack* str = stack_new();
if((t)%2==0)
{
	int i,count=0;
	i=0;
	int temp;
	while(i<t)
	{
		if(arr[i]=='{')
		{
			stack_push(str,'{');
		}
		if(arr[i]=='}'&& stack_size(str)==0)
		{
			count++;
			stack_push(str,'{');
			i++;
			continue;
		}
		if(arr[i]=='}')
		{
			temp=stack_pop(str);
		}
		
		i++;
	}
	int size= stack_size(str);
	if(size%2==0)
	{
	count=count + size/2;
	printf("%d\n",count);
	}
	else
	printf("-1\n");
}
else
printf("-1\n");
}
return 0;
}
