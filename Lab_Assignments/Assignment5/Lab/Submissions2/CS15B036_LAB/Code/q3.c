#include<stdio.h>
#include"stack.h"
int main()
{
int test,z,j,temp;
scanf("%d",&test);
for(z=0;z<test;z++)
{
int n,i;
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
{
	scanf("%d",&arr[i]);
}
stack *str=stack_new();
i=0;
while(i<n-1)
{
	stack_push(str,arr[i]);
	j=i+1;
	while(j<n)
	{
		temp=stack_pop(str);
		if(arr[j]>temp)
		{
			printf("%d ",arr[j]);
			break;
		}
		else
		{
			stack_push(str,temp);
			j++;
		}
	}
	if(j>n-1)
	{
		printf("-1 ");
	}
	i++;
}
printf("-1\n");
}
return 0;
}
			
