#include<stdio.h>
#include<sys/time.h>     //for calculating time

int fib1(int n)          //function involving fibonacci without recursion

{int i,t;
 int f=0;
 int s=1;
if(n==0)
 return 0;
 else if(n==1)
 return 1;
 else
{
  for(i=2;i<=n;i++)
  {t=f+s;
   f=s;
   s=t;
  }
}

 return t;
}

int fib2(int n)              //function involving fib with recursion
{if(n==0)
 return 0;
 if(n==1)
 return 1;
 else
 return fib2(n-1)+fib2(n-2);
 }

 void main()                   //begining of main
{int n,i;double diff;
struct timeval t1,t2;
 FILE *fp;                     //file pointer
 fp=fopen("output.csv","w");
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  printf("%d ",fib1(i));
  
  }
  

  
 printf("\n");
for(i=1;i<=n;i++)
 {
 printf("%d ",fib2(i));
 
}
for(i=1;i<=n;i++)                           //for getting time calculation
 {gettimeofday(&t1,NULL);
  fib1(i);
  gettimeofday(&t2,NULL);
  
  diff=(double)((t2.tv_usec-t1.tv_usec)-(t2.tv_sec-t1.tv_sec)*1000000);
  fprintf(fp,"%lf,",diff);

 gettimeofday(&t1,NULL);
  fib2(i);
  gettimeofday(&t2,NULL);
  
  diff=(double)((t2.tv_usec-t1.tv_usec)-(t2.tv_sec-t1.tv_sec)*1000000);
  fprintf(fp,"%lf\n",diff);
}
 fclose(fp);
}


