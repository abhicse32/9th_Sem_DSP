#include<stdio.h>
int main()
{
	int a,i,k,d;
	char x[10]={'0','0','0','0','0','0','0','0','0','0'};
	x[9]='0';
	x[8]='x';
	scanf("%d",&a);
	for(i=0;a!=0;i++)
	{
		k=a%16;
		if(k<10) x[i]=k+'0';
		if(k>=10)x[i]=k+'a'-10;
		a=a/16;
	}
	for(i=9;i>=0;i--)
	{
		printf("%c",x[i]);
	}
	return 0;
}
