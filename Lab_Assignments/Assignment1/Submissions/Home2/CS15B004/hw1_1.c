#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);

	int *arr = (int*) malloc((n)* sizeof(int));    // dynamic allocation
	int max,nextmax;
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	if(arr[0]>arr[1])							//initialisation
	{	max=arr[0];
		nextmax=arr[1];
	}
	else
	{	max=arr[1];
		nextmax=arr[0];
	}	

	for(i=2;i<n;i++)
	{
		if(arr[i]>nextmax)							//checking max and nextmax
		{	if(arr[i]>max)
			{
				nextmax=max;
				max=arr[i];
			}
			else
			{
				nextmax=arr[i];
			}
		}	
	}

	printf("%d %d",max , nextmax);
	return 0;

}	