#include<stdio.h>
int main()
{
	int Max, next_Max,i,n;
	scanf("%d",&n);
 	int a[2*n-1],j=n-1;
 	for(i=n-1;i<2*n-1;i++)
 	{
 		scanf("%d",&a[i]);
 	}
 	for(i=2*n-2;i>0;i=i-2)
 	{
 		j--;
 		if(a[i]>a[i-1])
 		a[j]=a[i];
 		else
 		a[j]=a[i-1];
 			
 	}
 	Max=a[0];
 	if(a[0]==a[1])
 	{
 		next_Max=a[2];
 	}
 	else
 	{
 		next_Max=a[1];
 	}
 	for(i=0;i<n;i++)
 	{
 		if(a[i]==a[2*i+1])
 		{   
 			if(a[2*i]>next_Max)
 			next_Max=a[2*i];
 			i=2*i+1;
 		}
 		else
 		{
 			if(a[2*i+1]>next_Max)
 			next_Max=a[2*i+1];
 			i=2*i+2;
 		}	
 	}
 	printf("%d  %d\n",Max,next_Max);
	return 0;
}
