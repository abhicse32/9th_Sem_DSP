#include<stdio.h>
#include<string.h>
int main()
{
	char string1[20];
	char string2[20];
	gets(string1);
	gets(string2);
	int i;
	int j;
	int n;
	int count=0;
	n=strlen(string1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(string1[i]=string2[j])
			{
				string2[j]='\0';
				string1[i]='\0';
				
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if((string2[i]='\0')&&(string1[i]='\0'))
		{
			count++;
		}
	}
	if(count==n)
	{
		printf("\n1");
		
	}
	else
	{
		printf("\n0");
	}
	printf("\n h \n");
	printf("%d",count);
	printf("%d",n);
	for(i=0;i<n;i++)
	{
	
	printf("%c",string1[i]);
}
	return 0;
}
