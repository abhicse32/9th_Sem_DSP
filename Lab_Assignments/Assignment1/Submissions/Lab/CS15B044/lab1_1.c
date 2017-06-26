#include<stdio.h>
#include<math.h>
struct Complex
{
 float real;
 float imaginary;
};

struct Complex Add(struct Complex p, struct Complex q)
{
 struct Complex add;
 add.real= p.real + q.real;
 add.imaginary= p.imaginary + q.imaginary;
 return add;
}
 
struct Complex Sub(struct Complex p, struct Complex q)
{
 struct Complex sub;
 sub.real= p.real - q.real;
 sub.imaginary= p.imaginary - q.imaginary;
 return sub;
}

struct Complex Mult(struct Complex p, struct Complex q)
{
 struct Complex mult;
 mult.real= p.real*q.real - p.imaginary*q.imaginary;
 mult.imaginary= p.imaginary*q.real + p.real*q.imaginary;
 return mult;
}

float Mod (struct Complex p)
{
 float mod;
 mod=sqrt(p.real*p.real+ p.imaginary*p.imaginary);
 return mod;
}

float Dist (struct Complex p,struct Complex q)
{
 struct Complex a;
 float dist;
 a=Sub(p,q);
 dist= Mod(a);
 return dist; 
}

struct Complex Div(struct Complex p, struct Complex q)
{
 struct Complex div,a;
 float c,d;
 a.real=q.real;
 a.imaginary= -1* q.imaginary;
 c= Mod(a);
 d=c*c;
 div=Mult(p,q);
 div.real=div.real/d;
 div.imaginary=div.imaginary/d;
 return div;
} 

int main()
{
 struct Complex a,b,c;
 int tab;
 float dist;
  scanf("%f%f", &a.real, & a.imaginary);
  scanf("%f%f", &b.real, & b.imaginary);
  scanf("%d", &tab);
 
 while(tab<6 && tab>0)
 {
  if(tab==1)
  {
   c=Add(a,b);
   if(c.imaginary>0)
   printf("%f + %fi",c.real,c.imaginary);
   else if(c.imaginary==0)
   printf("%f",c.real);
   else
   printf("%f - %fi",c.real,c.imaginary);
  }
  else if(tab==2)
  {
   c=Sub(a,b);
   if(c.imaginary>0)
   printf("%f + %fi",c.real,c.imaginary);
   else if(c.imaginary==0)
   printf("%f",c.real);
   else
   printf("%f - %fi",c.real,c.imaginary);
  }
  else if(tab==3)
  {
   c=Mult(a,b);
   if(c.imaginary>0)
   printf("%f + %fi",c.real,c.imaginary);
   else if(c.imaginary==0)
   printf("%f",c.real);
   else
   printf("%f - %fi",c.real,c.imaginary);
  }
  else if(tab==4)
  {
   c=Div(a,b);
   if(c.imaginary>0)
   printf("%f + %fi",c.real,c.imaginary);
   else if(c.imaginary==0)
   printf("%f",c.real);
   else
   printf("%f - %fi",c.real,c.imaginary);
  }
  else if(tab==5)
  {
   dist=Dist(a,b);
   printf("0.6%f",dist);
  }
  scanf("%f%f", &a.real, & a.imaginary);
  scanf("%f%f", &b.real, & b.imaginary); 
  scanf("%d", &tab);
 }
 return 0;
}
