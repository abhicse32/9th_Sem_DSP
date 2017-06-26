//DETERMINANT VALUE
//det function is called recursively
#include <stdio.h>
long long int det (int a,long long int [][a]);
int main()
{
	int n,i,j,k,l,m=1;
	scanf("%d",&n);
	long long int a[n][n],b[n-1][n-1];
	long long int ans=0;
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	{
		scanf("%lld",&a[i][j]);                //scans matrix inputs
	}
	}
	ans=det(n,a);
	printf("%lld",ans);                             //prints determinant value
	return 0;
	
}

long long int det (int n,long long int b[][n])
{
	if (n==1)                                        //terminating condition
	{
		long long int ans;
		 ans=b[n-1][n-1];
		return ans;
	}
	else
	{
		int i,j,l,k,m=1;
		long long int c[n-1][n-1];
		long long int ans=0;
		for (i=0;i<n;i++)
	{
		for (j=1;j<n;j++)
	{
		for(k=0;k<n-1;)
		{
			for (l=0;l<n;l++)
			if(l!=i)
			{
				c[k][j-1]=b[l][j];       //creates a smaller matrix
				k++;
			}
		}
	
			
		
	}
		ans=b[i][0]*det(n-1,c)*m+ans;            //calls recursively and passes smaller matrix and calculates determinant
			m=m*(-1);
	}
		return ans;
	}
}
		
