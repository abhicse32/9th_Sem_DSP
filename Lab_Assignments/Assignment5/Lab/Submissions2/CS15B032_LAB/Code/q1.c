#include<stdio.h>
#include<string.h>

int main()
{
int t;
scanf("%d",&t);
int size;
char A[1000];
char p[1000];
int l,flag;
char ch[1];
for(;t>0;t--)
	{
	l=0;
	flag=1;
	scanf("%s",A);
	size=strlen(A);
	for(;size>0;size--)
		{
		
		switch(A[size-1])	
			{
			case ')':
			case ']':
			case '}':
			p[l]=A[size-1];
			l++;
			break;
			case '(':
			if(p[l-1]!=')')
				{
				size=0;
				flag=0;
				break;
				}	
			l--;			
			break;
			case '[':
			if(p[l-1]!=']')
				{
				size=0;
				flag=0;
				break;
				}	
			l--;			
			break;

			case '{':
			if(p[l-1]!='}')
				{
				size=0;
				flag=0;
				break;
				}	
			l--;			
			break;
			};
		}
if(l!=0)
flag=0;
	printf("%d\n",flag);
	}
return 0;
}


