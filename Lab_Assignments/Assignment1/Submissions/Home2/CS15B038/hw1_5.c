#include<stdio.h>

int main()
{
 int n, i;
 double s;

 scanf("%d",&n);
 s=1;

 for(i=1;i<20;i++)
  {
   s=(s+(n/s))/2;
  }

 printf("%.15lf",s);
}


