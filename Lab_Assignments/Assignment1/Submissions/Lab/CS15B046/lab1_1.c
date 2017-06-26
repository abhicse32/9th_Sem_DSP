/*This program has modules for addition,subtraction,division,multiplication and distance between complex numbers.
  Author: CS15B046 Jahnvi Patel 
  Date: August 8, 2016*/
#include <stdio.h>
#include <math.h>


struct complex
{
 float re;//Real part
 float im;//Complex part
};
/*The functions listed below aim to perform computations on complex numbers as listed in comments below.
  Each of them takes up two complex numbers as arguments
  Return type: Complex structure except modulus function that returns float value*/

struct complex add(struct complex c1, struct complex c2)//To add complex numbers
{ 
 struct complex sum;
 sum.re=c1.re+c2.re;
 sum.im=c1.im+c2.im;
 return sum;
}

struct complex sub(struct complex c1, struct complex c2)//To subtract compplex numbers
{ 
 struct complex diff;
 diff.re=c1.re-c2.re;
 diff.im=c1.im-c2.im;
 return diff;
}

struct complex multi(struct complex c1, struct complex c2)//To multiply complex numbers
{ 
 struct complex prod;
 prod.re=c1.re*c2.re-c2.im*c1.im;
 prod.im=c1.im*c2.re+c2.im*c1.re;
 return prod;
}

struct complex div(struct complex c1, struct complex c2)// To divide complex numbers
{ 
 struct complex quo;
 float mod=c2.re*c2.re+c2.im*c2.im;
 quo.re=(c1.re*c2.re+c2.im*c1.im)/mod;
 quo.im=(c1.im*c2.re-c2.im*c1.re)/mod;
 return quo;
}

float mod(struct complex c1, struct complex c2)// To find distance between complex numbers
{ 
 float modulus=sqrt((c1.re-c2.re)*(c1.re-c2.re) + (c1.im-c2.im)*(c1.im-c2.im));
 return modulus;
}



void main()
{ 
 int ch;
 struct complex cmplx1;
 struct complex cmplx2;
 
 
  do
{
 	scanf("%f %f",&(cmplx1.re),&(cmplx1.im));
  	scanf("%f %f",&(cmplx2.re),&(cmplx2.im));
  	scanf("%d",&ch);
/* Choice is 0 for quit*/
  	if(ch==1)
         {
            struct complex sum=add(cmplx1,cmplx2);
            if(sum.im>=0)
              	printf("%f + %fi ",sum.re,sum.im);
            else 
              	printf("%f - %fi ",sum.re,(-sum.im));
          }
  	else if(ch==2) 
         { 
         	struct complex diff=sub(cmplx1,cmplx2);
            if(diff.im>=0)
              	printf("%f + %fi",diff.re,diff.im);
            else 
              	printf("%f - %fi",diff.re,(-diff.im));
         }
  	else if(ch==3) 
        {  
        	struct complex prod=multi(cmplx1,cmplx2);
          	if(prod.im>=0)
            	printf("%f + %fi",prod.re,prod.im);
          	else
            	printf("%f - %fi",prod.re,(-prod.im));
        }
  	else if(ch==4) 
       	{ 
       		struct complex quo=div(cmplx1,cmplx2);
         	if( cmplx2.re==0 && cmplx2.im==0)
           		printf("Divide by 0 error\n");
         	else
         		{
                  	if(quo.im>=0)
                  		printf("%f + %fi",quo.re,quo.im);
                  	else
                   		printf("%f - %fi",quo.re,(-quo.im));
                }
        }
 	else if(ch==5) 
 		{
 			float modulus=mod(cmplx1,cmplx2);
          	printf("%.6f",modulus);
        }
  
}while(ch!=-1);
}

