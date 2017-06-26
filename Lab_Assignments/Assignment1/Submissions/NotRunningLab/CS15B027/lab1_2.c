#include<stdio.h>
int main()
{
	int i,n;
	scanf("%d",&n);/* prompting user to enter n value */
	int a[100];/*declaring an array of size 100 */
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);/* taking input into array */
	}
	int j,max,min;
	max = a[0];
	min = a[0];

	for(j=0;j<n-1;j=j+2)/*using tournament method */
	{
	if(a[j] < a[j+1]){
	   if(max < a[j+1])
	   max = a[j+1];/* comparing  with max and min */
		if(min > a[j])
		min = a[j];
			}
	else {
	   if(max < a[j])
	   max = a[j];
		if(min > a[j+1])
		min = a[j+1];
	     }
	}
		if(max < a[n-1])
		max = a[n-1];/* comparing with the last element */
		  if(min > a[n-1])
		  min = a[n-1];
			printf("%d %d\ns",min,max);/* printing the values of maximum and minimum */
return 0;
}
