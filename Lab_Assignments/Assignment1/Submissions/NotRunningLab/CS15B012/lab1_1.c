#include<stdio.h>
#include<math.h>
typedef  struct Complex // defining stuct
    {
     double p;
     double q;
    }complex;

 add(complex comp1,complex comp2)
   {
     complex comp3;
     comp3.p=comp1.p+comp2.p;
     comp3.q=comp1.q+comp2.q;
     char a;
if (comp3.q>=0)
a='+';
     printf("%lf%c%lfi\n",comp3.p,a,comp3.q);
   }

 sub(complex comp1,complex comp2)
   {
     complex comp3;
     comp3.p=comp1.p-comp2.p;
     comp3.q=comp1.q-comp2.q;
     char a;
if (comp3.q>=0)
a='+';
     printf("%lf%c%lfi\n",comp3.p,a,comp3.q);
   }

 mul(complex comp1,complex comp2)
   {
     complex comp3;
     comp3.p=(comp1.p*comp2.p)-(comp1.q*comp2.q);
     comp3.q=(comp1.p*comp2.q)+(comp1.q*comp2.p);
     
     char a;
if (comp3.q>=0)
a='+';
printf("%lf%c%lfi\n",comp3.p,a,comp3.q);
   }

 
int main(void)
 {
     complex comp1,comp2;
     int opn;
  
	do
        {
          scanf("%lf %lf",&comp1.p,&comp1.q);
          scanf("%lf %lf",&comp2.p,&comp2.q);
         scanf("%d",&opn);
         switch(opn)
         {case 1: add(comp1,comp2);
                  break;
	  case 2: sub(comp1,comp2);
                  break;
  	  case 3: mul(comp1,comp2);
	          break;
 	  case 4: div(comp1,comp2);
		  break;
          case 5: mod(comp1,comp2);
		  break;
	  
        }
       }while(opn!=0); 

return 0;
}
div(complex comp1,complex comp2)
   {
     complex comp3;
     comp3.p=(comp1.p*comp2.p)+((double)(comp1.q*comp2.q)/(double)sqrt(comp2.p*comp2.p+comp2.q*comp2.q));
     comp3.q=(comp1.q*comp2.p)-((double)(comp1.p*comp2.q)/(double)sqrt(comp2.p*comp2.p+comp2.q*comp2.q));
     
     char a;
if (comp3.q>=0)
a='+';
printf("%lf%c%lfi\n",comp3.p,a,comp3.q);
   }

 mod(complex comp1,complex comp2)
   {
     double y;
     y=sqrt((comp1.p-comp2.p)*(comp1.p-comp2.p)+(comp1.q-comp2.q)*(comp1.q-comp2.q));
      printf("%10.6lf\n",y);
   }
 
