#include<stdio.h>
void root(int n);/*declaring root function*/
int main()
{
  int n;
  scanf("%d",&n);/*taking input */
  root(n);/*calling the function */
  return 0;
}
void root(int n)
{
	int i;
	double x=0;/*x=low*/
	double y=n;/*y=high*/
	for(i=0;i<100;i++)
        {
	  double z =(double)(x+y)/2;/*z=mid*/
	  if (z*z>=n)
	  y=z;
	  else
	  x=z;
	}
	    printf("%0.15lf\n",x);/*printing precisely upto 15 decimals,using double type*/
}


