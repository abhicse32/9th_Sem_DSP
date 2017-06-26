#include<stdio.h>
#include<math.h>

/* This program takes two complex numbers.
   Then performs operation according to the choices
   1: Addition of two Complex Numbers
   2: Subtraction of two Complex Numbers
   3: Multiplication of two Complex Numbers
   4: division of two Complex Numbers
   5: Modulus/Magnitude/Absolute value of a Complex Number
   0: to terminate the program
*/
struct cmp        // structure to represnt a complex number
 {
   double real;
   double img;
 } ;


struct cmp add ( struct cmp x, struct cmp y)   // function to add
 {
    struct cmp z;
    z.real=x.real+y.real;
    z.img=x.img+y.img;
    return z;
 }
struct cmp sub ( struct cmp x, struct cmp y)   // function to subtract
 {
    struct cmp z;
    z.real=x.real-y.real;
    z.img=x.img-y.img;
    return z;
 }
struct cmp mul ( struct cmp x, struct cmp y)   // function to multiply
 {
    struct cmp z;
    z.real=x.real*y.real-x.img*y.img;
    z.img= x.img*y.real+y.img*x.real;
    return z;
 }
struct cmp div ( struct cmp x, struct cmp y)   // function to divide
 {
    struct cmp z;
    z.real=(x.real*y.real+x.img*y.img)/(y.real*y.real+y.img*y.img);
    z.img= (x.img*y.real-y.img*x.real)/(y.real*y.real+y.img*y.img);
    return z;
 }

double mod ( struct cmp x)   // function to find modulus
 {
   return sqrt(x.real*x.real+x.img*x.img) ;
 }

void valinput ( struct cmp* x )      // function to input the value using pointer reference
 { scanf("%lf %lf", &x->real, &x->img );
 }

void display (struct cmp x)      // function to display the complex number
 { printf("%0.6lf",x.real);
 if(!(x.img<0))
 printf("+");
 printf("%0.6lfi",x.img);
 }

int main()
 { struct cmp x ,y;
   int n,flag=0;
    do{
        valinput(&x);
        valinput(&y);
        scanf("%d",&n);

        switch(n)
        {   case 1 :
	             display(add(x,y));
	             break;
           case 2 :
	             display(sub(x,y));
	             break;
           case 3 :
	             display(mul(x,y)); 
              	     break;
           case 4 :
	             display(div(x,y));
	             break;
           case 5 :
	             printf("%0.6lf",mod(sub(x,y)));   // to print distance as distance is modulus of subtrsction of the numbers
	             break;
           default:  
                     flag=1;   // for any other choices it will terminate the program
        }
       } while( flag==0);

  return 0;
 }