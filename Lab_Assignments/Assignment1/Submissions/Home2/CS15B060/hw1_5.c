//i am assuming that the input >=0...if input is -ve also error stat. can be added
#include<stdio.h>

#define l 0.000000000000001      //for producing sq root of integer upto 15 dec. places

  long double sq(int n,long double ll,long double ul)   //function for finding sq root using newton raphson method
{     long double mid=(ll+ul)/2;
   if((mid*mid-n)<l && (mid*mid-n)>-l)                    //recursive function
    return mid;
   else if((mid*mid-n)<0)
 
    return sq(n,mid,ul);

   else
    return sq(n,ll,mid);
 }

 void main()                                         //begining of main program
{  int n;

   scanf("%d",&n);

   printf("%.15Lf",sq(n,0,n));                      //.15 indicates precision (ie 15 dec. places)
}

