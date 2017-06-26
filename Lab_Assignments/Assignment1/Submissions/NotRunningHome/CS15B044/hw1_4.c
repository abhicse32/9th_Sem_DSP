#include<stdio.h>
int main()
{
	char  a[100],b[100];
	scanf("%s%s",a,b);
	int length_a=0,length_b=0;
	while(a[length_a]!='\0')
	{
		length_a++;
	}
	while(a[length_b]!='\0')
	{
		length_b++;
	}
	if(length_a!=length_b)
	printf("0\n");
	else
	{
		int i=0,j=0,k=1;
		while(i<length_a && k==1)
		{
			k=0;
			j=0;
			while(k==0 && j<length_b-i)
			{   
				if(a[i]==b[j])
				{
					k=1;
					char temp;
					temp=b[j];
					b[j]=b[length_b-i-1];
					b[length_b-i-1]=temp;
				}
				j++;
			}
			if(k==0)
			{
				printf("0\n");
				break;
			}
			i++;			
		}
		if(k==1)
		printf("1\n");
	}
	return 0;
}
