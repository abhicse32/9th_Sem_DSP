#include<stdio.h>
//COMMON PRIME FACTORS
int gcd(int,int);

int main()
{
	int a,b,g;
	scanf("%d",&a);
	scanf("%d",&b);
	gcd(a,b);
	g = gcd(a,b) ;
	int i,j,k;
	i = 1;
	while (i <= g)
	{
       		k = 0;
        	if (g % i == 0)
        	{
            		j = 1;
            		while (j <= i)
            		{
               	 		if (i%j == 0)
                    		k++;
                		j++;
            		}
            		if (k == 2)
                	printf("%d\n", i);
        	}		
       	        i++;
	}

}

int gcd(int a, int b)
{
    
	if (a == b)		return a;
        
 	if (a > b)		return gcd(a-b, b);
        
    	return gcd(a, b-a);

}

