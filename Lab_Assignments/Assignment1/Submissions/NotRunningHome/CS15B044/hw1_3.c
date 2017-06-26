#include<math.h>
#include<stdio.h>
int min(int a, int b)
{
 if(a<b)
 return a;
 else
 return b;
}
int gcd ( int a, int b )
{
 if(a<b)
 {
  if(b%a == 0)
  return a;
  else
  b = b%a;
  return gcd(a,b);
 }
 else
 {
  if(a%b == 0)
  return b;
  else
  a = a%b;
  return gcd(a,b);
 }
 
}
int prime (int p)
{ int i;
 if(p>1)
 {
  for(i=2;i< p;i++)
  {
   if(p%i==0)
   return 0;
  }
  return 1;
 }
 else
 return 0;
}
int main()
{
 int a,b,i,gcd1;
 scanf("%d %d", &a,&b);
 gcd1= gcd(a,b);
 for(i=2;i<=gcd1;i++)
 {
  if(prime(i))
  { 
   if(gcd1%i==0)
   {
    printf("%d     ", i);
   }
  }
 }
 return 0;
}
