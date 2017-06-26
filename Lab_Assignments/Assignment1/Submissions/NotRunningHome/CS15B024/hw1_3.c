#include <stdio.h>
int main()
{
	int a,b,flag=0;
	printf("enter the values of a and b");	
	scanf("%d %d",&a,&b);			
	int i,j,k;				
	int p[a];
	for(i=0;i<a;i++)
	{
		p[i]=0;
	}
	for(i=0;i<a;i++)        //forming an array of primes less than a
	{
		for(j=2;j<=a;j++)
		{
			for(k=2;k<j;k++){
			if(j%k==0)
                        {
			flag=1;
                        break;
                        }
			else flag=0;
			}
		        if(flag==0)
				{
					p[j-1]=j;
				}
		}
	}	
	for(i=0;i<a;i++)
	{
		if(p[i]!=0 && a%p[i]==0 && b%p[i]==0)   //printing the common factors which are prime from that array
		printf("%d ",p[i]);
	}
}
		
			
		
			
		
		
		
		
			











		




	
	
	

	
	
