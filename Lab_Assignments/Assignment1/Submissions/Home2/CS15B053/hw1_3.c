#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int findgcd(int n1, int n2)
{
	if (n2!=0)
       		return findgcd(n2, n1%n2);
    	else 
       		return n1;
}


int computeprimefactors(int gcd, int *primefactors)
{
	int count=0;
	
	while(gcd%2==0)
	{
		primefactors[count++]=2;
		gcd = gcd/2;
	}
	int i;
	for(i=3; i<=sqrt(gcd); i=i+2)
	{
		while (gcd%i == 0)
        	{
            		primefactors[count++]=i;
       			gcd = gcd/i;
        	}
	}
	if(gcd>2)
		primefactors[count++]=gcd;
	return count;
}

int eliminateduplicates(int *primefactors, int count)
{
	int i,j,k;
	for(i=0; i<count; i++) 
   	{
      		for(j=i+1; j<count; )
      		{
        	 	if(primefactors[j] == primefactors[i])
       			{
            			for(k=j; k<count;k++) 
            			{
              				 primefactors[k] = primefactors[k+1];
           			 }
          			count--;
         		}
        		else
       	 		{
        		    j++;
        		}
      		}
  	}
  	return count;
}


void main()
{
	int n1, n2, gcd;
	scanf("%d %d", &n1, &n2);
	gcd = findgcd(n1, n2);
	
	int primefactors[100];
	int count=computeprimefactors(gcd, primefactors);
	
	int newcount = eliminateduplicates(primefactors, count);
	
	int j;
	for(j=0; j<newcount; j++)
		printf("%d ", primefactors[j]);	
}
	
	
