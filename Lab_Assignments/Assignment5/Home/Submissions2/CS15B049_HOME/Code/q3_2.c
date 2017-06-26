#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include "List.h"
#include "stack.h"

int convert(char a[],int size)
{
	if(size==1)
	{
		return (int)a[0];
	}
	else
	{
		int i,sum=0;
		for(i=size-1;i>=0;i--)
		{
			sum = sum+(int)a[i]*pow(10,i);
		}
		return sum;
	}
}


int main()
{
	char str[1000];
	char temp[100];
	scanf("%s",str);

	stack* s = stack_new();

	int i=0;
	while(str[i]!='\0')
	{
		int j=i;
		int x=0;
		while(str[j]!=' ')
		{
			temp[x]=str[j];
			int size = strlen(temp)
			int data= convert(temp,size);
			
			stack_push(s,data);
			x++;
			j++;
			i++;
		}
		
		i++;
	}

	stack_print(s);
}
