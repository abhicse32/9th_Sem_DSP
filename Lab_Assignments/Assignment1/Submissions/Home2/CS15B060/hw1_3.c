#include<stdio.h>
#include<math.h>    //for using sq root function

int prime(int n)       //function to chec if a number is prime
{ int i;
  i=0;
  for(i=2;i<=sqrt(n);i++)
  { if(n%i==0)
     return 0;
   }
   return 1;
}


  void main()                  //begining of main program
{int a,b,i,c=0;
   scanf("%d %d",&a,&b);
   if(a<=0||b<=0)
     printf("+ve nos only \n");
   else
 {  for(i=2;i<=a &&i<=b;i++)
  
       if(!(a%i) && !(b%i))
     {  
         if(prime(i))
     {   printf("%d ",i);   //printing prime factors
          c++;                
        }
         }
    
    if(c==0)
    printf("no prime factors \n"); //to check for existance of prime factors


 }
 
}

