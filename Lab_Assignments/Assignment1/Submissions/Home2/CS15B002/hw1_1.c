#include<stdio.h>
int main()
{
	int n,i,max,nextmax,d,j,k,x,p,c=0;
	scanf("%d",&n);
	d=(2 * n)-2;j=n/2 +1;
	int a[d];
	int y[j];
	for( i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
	for(i=0;i<d;)
	{
		if(a[i]>a[i+1]) a[n+(i/2)]=a[i];
		else a[n+(i/2)]=a[i+1];
		i=i+2;
	}
	max=a[d];
	for(x=d;x>=0;)
	{
		p=d-2-(2*(d-x));
		if(a[p]>a[p+1]) {y[c]=a[p+1];x=p;}
		else  {y[c]=a[p];x=p+1;}
		c++;
	}
	
	nextmax=y[0];
	for(i=1;i<c;i++)
	{
		if(y[i]>nextmax) nextmax=y[i];
	}
	printf("%d %d\n",max,nextmax);
	return 0;
}
