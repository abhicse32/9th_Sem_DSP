#include<stdio.h>
int prime(int x)/*using a function to find a number is prime or not */
{
  int z;
  for(z=2;z < x;z++)
  {
    if(x%z == 0)
    return -1;
  }
   return 0;
}
int main()
{
  int a,b,i,k;
  scanf("%d",&a);/*taking input two numbers*/
  scanf("%d",&b);
	if(a<b)/*interchanging a & b if a is less than b */
	{
	  i=a;
	  a=b;
	  b=i;
	}
		for(k=2;k<b+1;k++)
		{
		  if(prime(k)==0)/*calling the prime function */
		  {
		    if((a%k == 0)&&(b%k == 0))/*checking for common prime factor */
		    printf("%d ",k);/*printing the common factor */
		  }
		}
	printf("\n");
}
