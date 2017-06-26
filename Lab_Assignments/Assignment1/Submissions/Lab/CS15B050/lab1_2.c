            //Code to find Maximum and Minimum Element in an array
			//Author:M.Prasanna Kumar
			//Date:08/08/2016
#include<stdio.h>
int main()
{
int n;                                                    //Array Size
int i,j,k;                                                //Counter Variables
scanf("%d",&n);
int arr[n];                                               //Declaring an array
int Minarr[(n/2)+1];                                      //Declaring Min array
int Maxarr[(n/2)+1];                                      //Declaring Max array
int max,min;
for(i=0;i<n;i++) scanf("%d",&arr[i]);
if(n%2==0)
{ 
    for(i=0,j=0,k=0;i<n-1;i=i+2,j=j+1,k=k+1)
    {
    if(arr[i]<=arr[i+1])
      {
       Maxarr[j]=arr[i+1];
       Minarr[k]=arr[i];
      }
    if(arr[i]>arr[i+1])
      {
       Maxarr[j]=arr[i];
       Minarr[k]=arr[i+1];
      }
    }
}
else
{
    Maxarr[0]=arr[n-1];
    Minarr[0]=arr[n-1];
    for(i=0,j=1,k=1;i<n-1;i=i+2,j=j+1,k=k+1)
    {
      if(arr[i]<=arr[i+1])
      {
       Maxarr[j]=arr[i+1];
       Minarr[k]=arr[i];
      }
      if(arr[i]>arr[i+1])
      {
       Maxarr[j]=arr[i];
       Minarr[k]=arr[i+1];
      }
    }
}
    max=Maxarr[0];
    min=Minarr[0];
    for(i=1;i<j;i++)
        {
        if(max<=Maxarr[i]) max=Maxarr[i];
        }
    
    for(i=1;i<k;i++) 
     {
     if(min>=Minarr[i]) min=Minarr[i];
     }
    
printf("%d %d\n",min,max);
return 0;
}
