#include<stdio.h>

#include<math.h>

int PrimeCheck( int );

int main()
{
int m, n, x, p, i, cpf;

scanf("%d",&m);

scanf("%d",&n);

if( m<=n )
  {
     p = (m/2);
  }
else
  {
     p = (n/2);
  }

for(i=2; i<=p; i++)
{
  if( n%i==0 )
  {
    if( m%i==0 )
    {
         x=PrimeCheck(i);
  
         if( x==1 )
	 {
           cpf=i;

           printf("%d ",cpf);
	 }
    }
  }
}
printf("\n");

return 0;
}


int PrimeCheck( int a )
{
  int i,b=sqrt(a);

  for(i=2; i<=b; i++)
  {
    if( a%i==0 )
    { 
      return 0;
    }
  }
return 1;
} 
