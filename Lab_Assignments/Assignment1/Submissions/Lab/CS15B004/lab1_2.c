//lab1_2 max and min

#include<stdio.h>
#include<malloc.h>
#include<limits.h>

void main()
{
	int n,i;
	int min,max;

	scanf("%d",&n);
	int* arr;
	arr = (int*)malloc(n*sizeof(int));   //dynamic allocation

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	

	max=INT_MIN;
	min=INT_MAX;

	for(i=0;i+1<n;i=i+2)
	{
		if(arr[i]>arr[i+1])
		{	
			if(arr[i]>max)
				max=arr[i];
			if(arr[i+1]<min)
				min=arr[i+1];
		}
		else
		{
			if(arr[i]<min)
				min=arr[i];
			if(arr[i+1]>max)
				max=arr[i+1];
		}
	}
	if((n%2)!=0)
	{
		if(max<arr[n-1])  max=arr[n-1];
		if(min>arr[n-1])  min=arr[n-1];
	}

	printf("%d %d",min,max);

	free(arr);

	
}
