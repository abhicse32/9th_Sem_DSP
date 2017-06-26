#include<stdio.h>
/*
  To print common prime factors of 2 numbers
*/
int factors(int n)                  //To find number of factors(except 1)
{
  int j;
  int c = 0;                        //Counter varable to find number of factors
  for(j=2;j<=n;j++)
  {
    if(n%j==0)
      c++;
  }
  return c;
}
int main()
{
  int a;
  int b;
  scanf("%d",&a);                   //Taking 2 numbers as input
  scanf("%d",&b);
  int i;
  int max;
  if(a>b)                           //Finding bigger of 2 number
    max=a;
  else
    max=b;
  for(i=2;i<=max/2;i++)
  {
    if(factors(i)==1)               //Checking if a number is prime or not
    {
      if(((a%i)==0)&&((b%i)==0))    //Checking if the prime number is a factor or not
        printf("%d ",i);            //Printing the output
    }
  }
  return 0;
}
