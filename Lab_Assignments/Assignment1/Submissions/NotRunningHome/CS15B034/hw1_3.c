//Homework Assignment 1.3 by Raghavan S CS15B034: to take 2 integers and prin the common prime factors
#include<stdio.h>
#include<math.h>
/*fprim() takes an integer n and an integer array p as arguments and checks and prints the prime factors of n
p[] is the prime check array*/
void fprim(int n,int p[])
{
int i;                            //iterator
if(n==1)                          //end of recursion
  return;
for(i=2;i<=n;i++)                 //go through all primes and check which divide n
{
  if(p[i]==1)
    if(n%i==0)                    //check if i divides n
    {
      printf("%d ",i);
      while(n%i==0)
      {
        n=n/i;                    //to get highest factor of n not divisible by i
      }
      fprim(n,p);                 //recursive call to print other prime factors
      break;
    }
}
}
int main()
{
int j,k;                          //iterators
int p[10001];                     //boolean array
p[1]=0;
for(j=2;j<=10000;j++)             //p[i]=0 if i is not a prime, 1 f it is a prime
{
  p[j]=1;
  for(k=2;k<=sqrt(j);k++)
    if(j%k==0)
    {
      p[j]=0;break;
    }
}
int t,r=1,s,q,gcd=1,i=1;
/*
t is a temp variable, in euclids division algo to find gcd, r is remainder, s,q are the input primes
and also the dividend and divisor respectively, i is an iterator and gcd is the hcf of s and q
*/
scanf("%d",&s);
scanf("%d",&q);                   //scanning the input integers
if(s<q)                           //making sure s>q by swapping if otherwise
{
  t=s;
  s=q;
  q=t;
}
while(r!=0)                       //euclid's division algo
{
  r=s%q;
  if(r==0)
    gcd=q;
  else
  {
    s=q;
    q=r;
  }
}
//printf("hy");
//printf("%d",gcd);
fprim(gcd,p);                    //print prime factors of gcd
return 0;
}
