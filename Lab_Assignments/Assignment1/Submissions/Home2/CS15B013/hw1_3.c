//CS15B013 COMMON PRIMES

#include <stdio.h>

void checkprime(int num);

int main()
{
 int a,b,temp,i;
 scanf("%d %d",&a,&b);

 if(a>b)
   {temp=a;
    a=b;
    b=temp;
   }

 for(i=2;i<=a;i++)
    {
     if(a%i==0 && b%i==0)
      checkprime(i);
    }

return 0;
}


 void checkprime(int num)
      {  int a=num;
         int i,prime=1;
         for(i=2;i<=a/2 && prime==1;i++)
            {
              if(a%i==0)
               prime=0;

             }
         if(prime==1)
           printf("%d  ",a);

       }
