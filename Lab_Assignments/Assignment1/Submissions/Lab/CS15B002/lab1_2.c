#include<stdio.h>
int main()
{
	int n,i,j,k,min,max,w,l;
	scanf("%d",&n);
	int a[n];
	for( i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
	w=n/2;
	l=n/2;
	int win[w],lose[l];					
	if(n%2==0) k=n;
	else k=n-1; 
	for( i=0;i<k;i+=2)						//comparing pair of numbers and making arrays of larger numbers and smaller numbers
	{
		j=i/2;
		if(a[i]>a[i+1]) {win[j]=a[i]; lose[j]=a[i+1];}
		else {win[j]=a[i+1]; lose[j]=a[i];}
	}
	max=win[0];min=lose[0];						//comparing for maximum and minimum among the arrays 
	for(i=0;i<w;i++)
	{
		if(win[i]>max) max=win[i];		
		if(lose[i]<min) min=lose[i];
	}
	if(n%2!=0){							//if nis odd then checking the a[n-1] term with maximum and minimum values
		if(max<a[n-1])max=a[n-1];
		if(min>a[n-1])min=a[n-1];}
	printf("%d %d\n",min,max);
	return 0;
}
