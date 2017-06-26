/*This program finds the MAXIMUM and MINIMUM among the entered numbers.
  Author: CS15B046 Jahnvi Patel 
  Date: August 8, 2016*/
#include <stdio.h>
void find(int arr[],int n)//A function to find MAX and MIN
{
 /*In case no. of entries are odd add a dummy element to the end of the array to make it even*/
  if(n%2==1)
  {
    arr[n]=arr[n-1];
    n++;
  }

int win[n/2],los[n/2];// Arrays for storing the losing and winning part of arrays
int min,max;//To stroe MIN and MAX of given entries
int i,pos=0;
for(i=0;i<n-1;i+=2)
{
  if(arr[i]>arr[i+1])
  {
    win[pos]=arr[i];
    los[pos]=arr[i+1];
  }
  else
 {
   win[pos]=arr[i+1];
   los[pos]=arr[i];
 }
 pos++;
}
/*min is found among n/2 losers and max is found among n/2 winners
  Therefore, the time complexity of this algorithm is (3*n/2-2) */
 min=los[0];
 max=win[0];

 for(i=0;i<pos;i++)
{ 
  if(los[i]<min)
   min=los[i];
  if(win[i]>max)
   max=win[i];
}

 printf("%d %d",min,max);

}

void main()
{
  int n,i;
  scanf("%d",&n);
  int arr[n+1];
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  find(arr,n);
}


