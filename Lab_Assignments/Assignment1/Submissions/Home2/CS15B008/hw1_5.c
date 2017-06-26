//A program to determine square root of a number without inbuilt libraries.
//Program is written by Nikhil Baba.B CS15B008 on 9th August,2016


#include<stdio.h>

int main()                                  //Defining the main function
{
 double n,x0;
 scanf("%lf",&n);                           //Reading the variable  
 double h=1,h1=1;
 x0=n;
 while((h1)>0.00000000000005)              //Error calculation
 {
  
  double a,b;
  a=(x0*x0)-n;                              //Newton Raphson method
  b=x0*2.0;
  h=(double)a/(double)b;
  x0=x0-h;
  if(h<0)
  {
   h1=-h;
  }
  else
  {
   h1=h;
  }
 
   
 
 }
  printf("%.15lf",x0);                      //Printing the square root upto 15 decimal digits
 
 return 0;
}
		
 
