#include<stdio.h>
int main()
{
    long int x;
    char arr[x];
	scanf("%ld",&x);
	int i=0;
	int j;
	int k;
	int c;
	while(x/16!=0)
	{
		if(x%16>9)
		{
			if(x%16==10)
			{
				arr[i]='a';
			}
			if(x%16==11)
			{
				arr[i]='b';
			}
			if(x%16==12)
			{
				arr[i]='c';
			}
			if(x%16==13)
			{
				arr[i]='d';
			}
			if(x%16==14)
			{
				arr[i]='e';
			}
			if(x%16==15)
			{
				arr[i]='f';
			}
			
		}
		else
		{
			arr[i]=x%16+48;
		}
		x=x/16;
		i++;
	}
	if(x%16>9)
		{
			if(x%16==10)
			{
				arr[i]='A';
			}
			if(x%16==11)
			{
				arr[i]='B';
			}
			if(x%16==12)
			{
				arr[i]='C';
			}
			if(x%16==13)
			{
				arr[i]='D';
			}
			if(x%16==14)
			{
				arr[i]='E';
			}
			if(x%16==15)
			{
				arr[i]='F';
			}
			
		}
		else
		{
			arr[i]=(x%16)+48;
		}
		x=x/16;
		for(j=i;j>=0;j--)
		{
			printf("%c",arr[j]);
		}
		return 0;
		
	
}
