#include <stdio.h>

int main(void)
{
	int n,i, max, nxtmax;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	}
	if(arr[0]>arr[1]){
	    max=arr[0];
	    nxtmax=arr[1];
	}
	else
	{
	    max=arr[1];
	    nxtmax=arr[0];
	}
	for(i=2;i<n;i++)
	{
	    if(max<=arr[i])
	    {
	        nxtmax=max;
	        max=arr[i];
	    }
	    else if(nxtmax<=arr[i])
	    {
	        nxtmax=arr[i];
	    }
	}
	printf("%d %d",max,nxtmax);
	return 0;
}

