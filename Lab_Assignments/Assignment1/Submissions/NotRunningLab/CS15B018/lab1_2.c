#include<stdio.h>
int main()
{
	int n;
	int k;
	scanf("%d\n",&n);
	k = n/2;
	int a[k],b[k],c[n];

	if(n % 2 == 0)
	k=n-1;
	else 
	k=n-2;
	
	int i=0;
	if(n == 1)
		{
		scanf("%d",&c[0]);
		printf("%d %d",c[0],c[0]);
		}

	else{
		for(i=0;i < n;i++)
		scanf("%d",&c[i]);


		for(i=0;i<k;i=i+2)
		{
			if (c[i]>c[i+1])
				{
					a[i/2]=c[i];
					b[i/2]=c[i+1];
				}
			else
				{
					a[i/2]=c[i+1];
					b[i/2]=c[i];
				}
		}

	int max=a[0],min=b[0];

	for(i=0;i<n/2;i++)
		{
			if (a[i] > max) max=a[i];
				
		}
	
	for(i=0;i<n/2;i++)
		{
			if (b[i] < min) min=b[i];
		
		}

	if (n%2 != 0)
		{
			if(c[n-1] > max) max=c[n-1];
		
			if(c[n-1] < min) min=c[n-1];
		}
	printf("%d %d",min,max);}
}
