//Homework Assignment 1.5 by Raghavan S CS15B034: To print the square root of an integer input
//I have used Newton Raphson method to calculate square root
#include<stdio.h>
#include<math.h>
#define cmax 25                         //no of iterations to be done
/*ab() takes a long double number as argument and calculates modulus or absolute value of that number
and returns the output long double*/
long double ab(long double x)
{
  if(x<0)
    return (-1*x);
  else
    return x;
}
int main()
{
int n;                                  //input integer
long double x,x2;                            //x is a loop parameter,x2 is the next parameter obtained after loop execution is done
int count=0;                            //iterator
long double sqr;                             //square root of n
scanf("%d",&n);                         //scanning input
if(n==1)
  sqr=1.0;
else
{
  x=(n+1)/2;                            //initial x: note that (n+1)/2 is more than sq.root of n for all n>1
/*the following loop pushes x towards sq.root of n*/
  do
  {
    count++;
    x=1.0*(x+n/x)/2;                //function: f(x)=x*x-n, x[i+1]=x[i]-f(x[i])/f'(x[i]), x[i+1]=(x[i]*x[i]+n)/(2*x[i])
  } while (count<cmax);                 //only cmax iterations
  sqr=x;
}
printf("%0.15Lf\n",sqr);                //printing sqrt(n)
return 0;
}
