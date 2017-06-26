#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];	int c[26]={0},d[26]={0};
	int la,lb,i,k,l,x;	
	scanf("%s %s",a,b);
	la=strlen(a);
	lb=strlen(b);
	if(la!=lb)
	{	
		printf("0\n");	
		return 1;
	}
	for(i=0;i<la;i++)
	{
		k=a[i]-'a';
		c[k]+=1;
		l=b[i]-'a';
		d[l]+=1;
	}
	for(i=0;i<26;i++)
	{
		if(c[i]!=d[i])  
		{
			x=0; 
			break;
		}
		else x=1;
	}
	printf("%d \n",x);
	return 0;
}
