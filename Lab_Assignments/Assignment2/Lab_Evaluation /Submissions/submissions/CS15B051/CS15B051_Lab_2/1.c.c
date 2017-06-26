#include<stdio.h>
#include<sys/time.h>

struct timeval t1,t2;

int fib_iterative(int n)
  {
  int f1=0,f2=1,f;
   if (n==0)
       return 0;
   else if (n==1)
      return 1;
  else 
  for(;n>1;n--)
  {
    f=f1+f2;
    f1=f2;
    f2=f;
  }
    return f;
  }
int fib_recursive(int n)
{
   if (n==0)
       return 0;
   else if (n==1)
      return 1;
   else
   return fib_recursive(n-1) + fib_recursive(n-2);
}
 
int main ()
{
  int i,j,n,p,q;
  //Read the number 
  scanf("%d",&n);
   for(i=1;i<=n;i++)
  {
      gettimeofday(&t1,NULL);
     p=fib_iterative(i);  
      gettimeofday(&t2,NULL);
   double timetaken=(double)(t2.tv_usec-t1.tv_usec)+(double)((t2.tv_usec-t1.tv_usec)*1.000000);
     printf("%lf ",timetaken);
    //printf("%d ",p);  
  }
     //printf("\n");
   for(j=1;j<=n;j++)
  {
    gettimeofday(&t1,NULL);
    q=fib_recursive(j);  // by recursion
    gettimeofday(&t2,NULL);
    double timetaken=(double)(t2.tv_usec-t1.tv_usec)+(double)((t2.tv_usec-t1.tv_usec)*1.000000);
    printf("%lf\n",timetaken);
    // printf("%d ",q);
  } 
  
 }

  


