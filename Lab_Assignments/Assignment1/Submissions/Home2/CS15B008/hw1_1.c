//A program to determine maximum and next maximum numbers in an integer array.
//Program is written by Nikhil Baba.B CS15B008 on 9th August,2016





#include<stdio.h>                                  
int main()                               // Defining the main function
{
 int n,i;                                // Declaring the necessary integers
 scanf("%d",&n);                         //Scanning the integer
 int num[n],max,nextmax;
 scanf("%d",&num[0]);                    //Scanning first and second integers and intialising other variables to them
 scanf("%d",&num[1]);
 if(num[0]>=num[1])                      //Assigning max and nextmax
 {
  max=num[0];
  nextmax=num[1];
 }
 else
 {
  nextmax=num[0];
  max=num[1];
 }
 for(i=2;i<n;i++)                       //Running a for loop
 {
   scanf("%d",&num[i]);
   if(num[i]>max)                       //Comparing the new entry with max
   {
    nextmax=max;
    max=num[i];
   
   }
   else if(num[i]>nextmax)              //Comparring the new entry with nextmax
   {
    nextmax=num[i];
   }
 }
  printf("%d %d",max,nextmax);          //Printing max and nextmax
 return 0;                              //Returning an integer
} 
 
  
