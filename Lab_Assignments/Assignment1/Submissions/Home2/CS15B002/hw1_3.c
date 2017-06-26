#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,i,j,gcd,p=0;
	scanf("%d %d",&a,&b);	
	if(a<b) c=a;
	else c=b;
	for(i=c;i>0;i--)
	{
		if((a%i==0)&&(b%i==0))
		{
			gcd=i;
			break;
		}	
	}
	if(gcd==1) return 1;
	for(i=2;i<=(gcd)/2+2;i++)
	{
		if((gcd%i)==0)
		{
			if((i==2)||(i==3)) printf("%d ",i);
			else
			{			
				for(j=2;j<=(i)/2+2;j++)
				{
					if(i%j==0) p=1;
				} 
				if(p!=1) printf("%d ",i);
			}	
		}
	}
	printf("\n");
	return 0;
}
