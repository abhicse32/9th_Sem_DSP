
/* project completed 
	by R.D.Nishal Singh, CS15B032 on 13.8.16
*/

#include<stdio.h>

int main()
{
int m,n,i,j=0,p=1,A[10],k=0;
scanf("%d %d",&m,&n);
for(i=2;i<=m&&i<=n;i++)
{if(m%i==0)
	{
		if(n%i==0)
		{
		p*=i;
			if(j!=i)
			{A[k]=i;
			k++;}
		j=i;		
		m/=i;
		n/=i;
		i--;}
		else
		{m/=i;
		i--;}
	}
else
	{if(n%i==0)
		{n/=i;i--;}
	}
}
for(i=0;i<k;i++)
if(A[i]!=A[i-1]);
printf("%d ",A[i]);
return(0);
}
