#include<stdio.h>
int main()
{
 int n,max,nextmax,i,j;/*declaration of variables*/
 int a[n];
 scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);/*taking input into array */
	if(a[0]>a[1])
	{
	  max=a[0];/* initialising max,nextmax accordingly */
	  nextmax=a[1];
	}
	  else
	  {
	     max=a[1];
	     nextmax=a[0];
	  }
	        for(j=2;j<n;j++)
		{
	        if(a[j]>max)/*comparing the elements in the array to find max and next max*/
		  {
	 	     nextmax=max;
	             max=a[j];
	          }
		       else if(a[j]>nextmax)
		       nextmax=a[j];
		 }
		             printf("%d %d\n",max,nextmax);/*printing max and next max accordingly */
  return 0;
}/*end of main */

