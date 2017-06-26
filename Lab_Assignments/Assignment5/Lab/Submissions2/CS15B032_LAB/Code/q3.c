#include<stdio.h>
#include<string.h>

int main()
{
int t;
scanf("%d",&t);
int n,k;
int A[1000];
int B[1000];
int i;
for(;t>0;t--)
	{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",A+i);
	A[n]=-1;
	B[n]=n;
	B[n-1]=n;
	for(i=n-2;i>=0;i--)	
		{
		B[i]=i+1;
		while(A[i]>=A[B[i]]&&B[i]!=n)
		B[i]=B[B[i]];
		}
	for(i=0;i<n;i++)
	printf("%d ",A[B[i]]);
	printf("\n");
	}

return 0;
}


