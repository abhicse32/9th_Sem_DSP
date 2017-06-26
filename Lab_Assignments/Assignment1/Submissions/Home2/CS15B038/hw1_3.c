#include<stdio.h>

int P(int n);
int G(int max,int min);
int main()
{
int a, b, n, min, max, gcd;
scanf("%d",&a);
scanf("%d",&b);
if(a<b)min=a,max=b ;else min=b,max=a;
gcd=G(max,min);
for(n=2;n<gcd+1;n++)
{
if(gcd%n==0&&P(n)==0) printf("%d ",n);
}
}
int P(int n)
{
int x;
for(x=2;x<n;x++)
{
if(n%x==0) return 1;
}
return 0;
}
int G(int max,int min)
{

if(max%min==0) return min;
else return G(min,max%min);
}
