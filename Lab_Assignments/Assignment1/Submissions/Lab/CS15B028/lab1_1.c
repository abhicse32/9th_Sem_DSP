/*various functions related to operations of complex numbers*/
#include<stdio.h>
#include<math.h>

struct complex{
     float p,q;
     } ;


void  sum(struct complex x,struct complex y)              /*function for addition*/
{
   struct complex c3;
   c3.p = x.p + y.p;
   c3.q = x.q + y.q;
   printf("%f + i%f\n",c3.p,c3.q);
}
void  sub(struct complex x,struct complex y )             /*for substraction*/
{
   struct complex c3;
   c3.p = x.p - y.p;
   c3.q = x.q - y.q;
   printf("%f + i%f\n",c3.p,c3.q);
}
void  mult(struct complex x,struct complex y )            /*for multiplication*/
{
   struct complex c3;
   c3.p = ((x.p*y.p)-(x.q*y.q));
   c3.q = ((x.p*y.q)+(x.q*y.p));
   printf("%f + i%f\n",c3.p,c3.q);
}
void  divs(struct complex x,struct complex y )           /*for division*/
{
   struct complex c3;
   c3.p = ((x.p*y.p) + (x.q*y.q))/(y.p*y.p + y.q*y.q);
   c3.q = ((x.p*y.q) - (x.q*y.p))/(y.p*y.p + y.q*y.q);
   printf("%f + i%f\n",c3.p,c3.q);
}
float dist(struct complex x,struct complex y)             /*for calculationg the distance between the complex numbers*/
{
   float sd = ((x.p-y.p)*(x.p-y.p) + (x.q-y.q)*(x.q-y.q));
   float d = sqrt(sd);
   return d;
}


int main()
{
    float p1,q1,p2,q2;
    int i;
    struct complex c1,c2;
    scanf("%f%f",&p1,&q1);
    scanf("%f%f",&p2,&q2);
    c1.p = p1;
    c1.q = q1;
    c2.p = p2;
    c2.q = q2;
    scanf("%d",&i);
    if(i == 1) sum(c1,c2);
    else
    if(i == 2) sub(c1,c2);
    else
    if(i == 3) mult(c1,c2);
    else
    if(i == 4) divs(c1,c2);
    else
    if(i == 5) { double r;  r = dist(c1,c2); printf("%f\n",r); }
}
