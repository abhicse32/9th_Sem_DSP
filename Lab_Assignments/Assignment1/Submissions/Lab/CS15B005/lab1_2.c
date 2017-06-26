#include<stdio.h>

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int arr[n];
	int x=n/2;
	int A[x],B[x],min,max;
	if(n==1)
	{
		max=arr[0];
		min=arr[1];
		return 0;	
	}
	if(n==2)
	{
		if(arr[0]>arr[1])
			max=arr[0];
			min=arr[1];
			return 0;	
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	max=arr[0];
	min=arr[0];
	for(j=0;j<((2*x)-1);j=j+2)
	{
		if(arr[j]>arr[j+1])
			{
				A[j/2]=arr[j];
				B[j/2]=arr[j+1];
							
			}
		else
			{
				A[j/2]=arr[j+1];
				B[j/2]=arr[j];
							
			}
		if(max<A[j/2]){max=A[j/2];}
		if(min>B[j/2]){min=B[j/2];}

	}
	if(n%2==1)
		{
			if(max<arr[n-1])
				max=arr[n-1];
			if(min>arr[n-1])
				min=arr[n-1];		
		}
	printf("%d %d",min,max);
return 0;
}
