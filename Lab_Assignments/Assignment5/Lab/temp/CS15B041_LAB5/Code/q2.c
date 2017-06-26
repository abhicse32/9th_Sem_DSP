#include<stdio.h>

int main()
{
 	
	//enter the string 
        char ch[1000];
	 
	scanf("%s",&ch);
	stack* s;
	s=stack_new();
int j=0;
int min=0;
int co=0;

while(ch[j]!='\0')
{
	if(stack_is_empty(s))
	{
		stack_push(s,ch[j]);
		j++;
		co++;
	}
	
	else
	{
		if(ch[j]!=ch[j-1])
			{
			stack_pop(s);
			j++;
			co--;
			}
		else
			{
			stack_push(s,ch[j]);
			j++;
			co++;
			}
	}
	
}
		if(co%2!=0)
			printf("-1");
		else
			{
				int d=1;
				int m;
				m=co/2;
				while(d<=m)
				{
				if(stack_pop(s)!='{')
				min++;
				d++;
				}
				while(d>m && d<=co)
				{
					if(stack_pop(s)!='}')
				min++;
				d++;
					
				}
			}
printf("%d ",min);
}


