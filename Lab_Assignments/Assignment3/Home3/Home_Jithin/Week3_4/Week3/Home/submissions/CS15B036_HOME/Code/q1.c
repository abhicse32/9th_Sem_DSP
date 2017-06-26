#include<stdio.h>
int main()
{
	int k,n,i,j,p,l;
	scanf("%d",&k);
	for(l=0;l<k;l++)
	{
	
	scanf("%d",&n);
	scanf("%d",&p);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int count[n],index[n],out[n];
	int cnt;
	for(i=0;i<n;i++)
	{
		cnt=0;
		for(j=0;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				cnt++;
			}
		}
		count[i]=cnt;
	}
	for(i=0;i<n;i++)
	{
		cnt=0;
		for(j=0;j<n;j++)
		{
			if(arr[j]<arr[i])
			{
				cnt++;
			}
			
		}
		index[i]=cnt;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<count[i];j++)
		{
			out[index[i]+j]=arr[i];
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",out[i]);
	}
}
	return 0;
	
}
