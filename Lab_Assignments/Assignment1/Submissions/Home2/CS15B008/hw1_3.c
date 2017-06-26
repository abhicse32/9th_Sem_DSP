//A program to determine common prime factors of two integers.
//Program is written by Nikhil Baba.B CS15B008 on 9th August,2016


#include<stdio.h>
#include<math.h>                                      //Calling the necessary libraries  

int main()                                            //Defining the main function
{
  int a,b,i;                                          //Declaring the necessary variab;e
  scanf("%d",&a);
  scanf("%d",&b);
  for(i=2;i<=(gcd(a,b));i++)                          //Finding prime factors of gcd of two numbers
  {
   if(gcd(a,b)%i==0 && prime(i)==1)
   {
    printf("%d ",i);                                  //Printing the prime factors
   }
  }
return 0;                                             //Returning an integer 
}


int gcd(int a, int b)                                 //Defining a function to find GCD using recursion
{
    
    if (a == b)
        return a;
                                                      // a is greater
    if (a > b)
        return gcd(a-b, b);
  return gcd(a, b-a);
}
int prime(int a)                                     //Defining a function to find prime numbers less than a particular number
{ 
  int i,flag=0;
  for(i=2;i<(a);i++)
   {
    if(a%i==0)
    {
      return flag;                                  //Returning a false flag
      break;
    }
   }
   return flag=1;                                    //Returning a true flag
 }
