#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex
{
  float a,b;
} complex;

void add(complex c1,complex c2)
{
  complex sum;
  sum.a=c1.a+c2.a;
  sum.b=c1.b+c2.b;
  if(sum.b>=0) printf("%.6f+%.6fi\n",sum.a,sum.b);
  if(sum.b<0) printf("%.6f-%.6fi\n",sum.a,-sum.b);
}

void sub(complex c1,complex c2)
{
  complex diff;
  diff.a=c1.a-c2.a;
  diff.b=c1.b-c2.b;if(diff.b>=0) printf("%.6f+%.6fi\n",diff.a,diff.b);
  if(diff.b<0)  printf("%.6f-%.6fi\n",diff.a,-diff.b);
}

void prod(complex c1,complex c2)
{
  complex prod;
  prod.a=((c1.a)*(c2.a))-((c1.b*c2.b));
  prod.b=((c1.a)*(c2.b))+((c1.b*c2.a));
  if(prod.b>=0) printf("%.6f+%.6fi\n",prod.a,prod.b);
  if(prod.b<0)  printf("%.6f-%.6fi\n",prod.a,-prod.b);
}

void divc(complex c1,complex c2)
{
  complex res;
  complex temp1;
  complex conj2;
  if(c2.a==0&&c2.b==0) return;
  conj2.a=c2.a;
  conj2.b=-c2.b;
  temp1.a=((c1.a)*(conj2.a))-((c1.b*conj2.b));
  temp1.b=((c1.a)*(conj2.b))+((c1.b*conj2.a));
  float x;
  x=(c2.a*c2.a+c2.b*c2.b);
  res.a=temp1.a/x;
  res.b=temp1.b/x;
  if(res.b>=0) printf("%.6f+%.6fi\n",res.a,res.b);
  if(res.b<0) printf("%.6f-%.6fi\n",res.a,-res.b);
 }

void dist(complex c1,complex c2)
{
  float dist;
  dist=sqrt(((c1.a-c2.a)*(c1.a-c2.a))+((c1.b-c2.b)*(c1.b-c2.b)));
  printf("%.6f\n",dist);
}


int main()
{
 complex c1,c2;
 int c=10;
 int z=0;
 
 while(1)
{
  scanf("%f%f",&c1.a,&c1.b);
  scanf("%f%f",&c2.a,&c2.b);
  if(c2.a==0&&c2.b==0) continue;
  scanf("%d",&c);
  switch(c){
   case 0:z=1; break;
   case 1:add(c1,c2); break;
   case 2:sub(c1,c2); break;
   case 3:prod(c1,c2); break;
   case 4:divc(c1,c2); break;
   case 5:dist(c1,c2); break;
  }
 if(z==1) break;
 }
 return 0;
}










































 

