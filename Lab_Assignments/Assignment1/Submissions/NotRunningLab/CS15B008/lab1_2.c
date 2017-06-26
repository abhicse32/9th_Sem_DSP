//Code to Maximum and Minimum of an array
//Code written by B.Nikhil Baba on 8th Aug,2016
#include<stdio.h>                                //Importing  all the standard libraries
int main()                                       //Entering into main function
{
  int n,i;                                       //Declaring size of array
  printf("Enter the size of array:");            //Prompting to enter size of array
  scanf("%d",&n);
  int array[n];
  for(i=0;i<n;i++)                               //Taking all the elements of array from user
   { 
   scanf("%d",&array[i]);
   }
  
  if(n%2==0)                                     //Considering the case where n is even
  {
   int p,max,min;
    max=array[0];
    min=array[0];
   for(p=0;p<n-1;p=p+2)
   { 
     int tempmax,tempmin;                        //Declaring temporary minimum and maximum balues in a loop
    if(array[p]>array[p+1])
     {
      tempmax=array[p];
      tempmin=array[p+1];
     }
    else
     {
      tempmin=array[p];
      tempmax=array[p+1];
     }
    if(max<tempmax)                              //Updating the minimum and maximum values in each iteration 
    {
      max=tempmax;
    }
    if(min>tempmin)
    {
      min=tempmin;
    }
   }
 printf("%d %d",min,max);                        //Printing the maximum and minimum values
 }
  if(n%2==1)                                     //Considering the case where size of array is odd
  {
    int p,max,min;
    max=array[0];
    min=array[0];
   for(p=0;p<n-2;p=p+2)
   { 
     int tempmax,tempmin;
    if(array[p]>array[p+1])
     {
      tempmax=array[p];
      tempmin=array[p+1];
     }
    else
     {
      tempmin=array[p];
      tempmax=array[p+1];
     }
    if(max<tempmax)                             //Updating temporary maximum and minimum values for each iteration
    {
      max=tempmax;
    }
    if(min>tempmin)
    {
      min=tempmin;
    }
   }
   if(array[n-1]>max)
    {
     max=array[n-1];
    }
   if(array[n-1]<min)
    {
     min=array[n-1];
    }
     printf("%d %d",min,max);                   //Printing minimum and maximum values
 }
 
 
return 0;                                       //Concluding the program
}
    
    

 
  
  
