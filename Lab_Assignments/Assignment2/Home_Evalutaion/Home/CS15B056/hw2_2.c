#include <stdio.h>
int check (int n,int a[][n],int r,int c);
void queen(int n,int a[][n],int r,int c[n+1]);
void Print (int n,int c[n+1]);
int main ()
{
	int n,i,j,r;
	scanf("%d",&n);
	int a[n][n],c[n+1];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
	r=0;
	c[n]=0;
	queen(n,a,r,c);
	printf("%d",c[n]);
	return 0;
	
	
}

void queen(int n,int a[][n],int r,int c[n+1])
{
	int i,l,flag;
	
	
	
	
	for(i=0;i<n;i++)
	{
		a[r][i]=1;
		
		for(l=0;l<n;l++)
			if(l!=i)
			{
				a[r][l]=0;
			}
		flag=check(n,a,r,i);
		if(flag==0)
		{
			c[r]=i;
			if (r==n-1)
				Print(n,c);
			else
				queen (n,a,r+1,c);
		}
		
	}
}


int check (int n,int a[][n],int r,int c)
{
	int flag=0,i,j;
	for(i=r-1;i>=0;i--)
	{
		if(a[i][c]==1)
			flag=1;
	}
	for(i=r-1,j=c+1;i>=0&&j<n;i--,j++)
	{
		if(a[i][j]==1)
			flag=1;
	}
	for(i=r-1,j=c-1;j>=0&&i>=0;i--,j--)
	{
		if(a[i][j]==1)
			flag=1;
	}
	
	return flag;
}
	
void Print (int n,int c[n+1])
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",c[i]);
	printf ("\n");
	c[n]++;
}
	