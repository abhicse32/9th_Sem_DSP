/*
 To operate on complex numbetrs by defining an abstract datatype
*/
#include<stdio.h>
#include<math.h>
struct Complex
{
  float a;
  float b;
};
typedef struct complex Complex;                               //Defininig an abstract datatype Complex
struct Complex add(struct Complex p,struct Complex q)         //Addition of complex numbers
{
  struct Complex sum;
  sum.a = p.a + q.a;
  sum.b = p.b + q.b;
  return sum;
}
struct Complex subtract(struct Complex p,struct Complex q)     //Subtraction of complex numbers 
{
  struct Complex difference;
  difference.a = p.a - q.a;
  difference.b = p.b - q.b;
  return difference;
}
struct Complex multiply(struct Complex p,struct Complex q)     //Multiplication of complex numbers
{
  struct Complex product;
  product.a = (p.a * q.a)-(p.b * q.b);
  product.b = (p.a * q.b)+(p.b * q.a);
  return product;
}
struct Complex divide(struct Complex p,struct Complex q)       //Division of complex numbers
{
  struct Complex quotient;
  float mod = (q.a * q.a)+(q.b * q.b);
  quotient.a = ((p.a * q.a)+(p.b * q.b))/(mod);
  quotient.b = ((p.b * q.a)-(p.a * q.b))/(mod);
  return quotient;
}
float distance(struct Complex p,struct Complex q)              //Distance between 2 complex numbers
{
  struct Complex d;
  float dist;
  d.a = p.a - q.a;
  d.b = p.b - q.b;
  dist = (d.a * d.a)+(d.b * d.b);
  dist = sqrt(dist);
  return dist;
}
int main()
{
  int choice;
  float a1;
  float a2;
  float b1;
  float b2;
  struct Complex m;
  struct Complex n;
  struct Complex x;    
  while(1)
  {
    scanf("%f %f",&a1,&a2);
    scanf("%f %f",&b1,&b2);
    scanf("%d",&choice);                                       //Taking user's choice  
    if(choice == -1)
    {
      break;
    }
    m.a = a1;
    m.b = a2;
    n.a = b1;
    n.b = b2;
    switch(choice)
    {
      case 1: x=add(m,n);
              printf("%f + %fi",x.a,x.b);
              break;
      case 2: x=subtract(m,n);
              printf("%f + %fi",x.a,x.b);
              break;
      case 3: x=multiply(m,n);
              printf("%f + %fi",x.a,x.b);
              break;
      case 4: x=divide(m,n);
              printf("%f + %fi",x.a,x.b);
              break;
      case 5: printf("%.6f",distance(m,n));
              break;
      default:break;
    }
  }
  return 0;
}
 
             	 	
