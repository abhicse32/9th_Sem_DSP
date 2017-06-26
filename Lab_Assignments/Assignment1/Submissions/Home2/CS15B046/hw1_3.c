/*A program to find the common prime factors of the entered numbers
  Author:CS15B046 Jahnvi Patel
  Date:August 10, 2016 */

#include <stdio.h>
#include <math.h>
/* A function to check if the number passed to it is prime or not*/  

int isprime(int n)
{
 int i,pr=1; 
 if(n%2==0&&n>2)
  pr=0;
 else
 {
  for(i=3;i<=sqrt(n);i+=2) //Checking till the square root of number
   if(n%i==0)
    pr=0;
 }
 return pr;
}

void main()
{
 int a,b; //The two input numbers
 int i;
 scanf("%d %d",&a,&b);
if(a<=1||b<=1)
 printf("No prime");
/* For printing common prime factors*/
 for(i=2;i<=a&&i<=b;i++)
{
   if(a%i==0 && b%i==0)
  { 
   if(isprime(i)==1)
    printf("%d ",i);
  }

}
}

