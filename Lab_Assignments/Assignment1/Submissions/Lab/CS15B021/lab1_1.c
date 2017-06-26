#include<stdio.h>

#include<stdlib.h>

#include<math.h>

void  ADD_COMPLEX( float,float,float,float );

void  SUB_COMPLEX( float,float,float,float );

void  MULT_COMPLEX( float,float,float,float );

void  DIV_COMPLEX( float,float,float,float );

void  MOD_COMPLEX( float,float,float,float );

struct imag_num {

  float real; 

  float imag;

};


int main()
{
int num=1;

struct imag_num n1;

struct imag_num n2;

while( num!=0 && num!=-1 )
{
  
  scanf( "%f %f",&(n1.real),&(n1.imag) );

  scanf( "%f %f",&(n2.real),&(n2.imag) );
 
  scanf( "%d",&num );

  switch(num) {
        case 1 : ADD_COMPLEX( n1.real, n1.imag, n2.real, n2.imag );
                break;

        case 2 : SUB_COMPLEX( n1.real, n1.imag, n2.real, n2.imag );
                break;

        case 3 : MULT_COMPLEX( n1.real, n1.imag, n2.real, n2.imag );
                break;

        case 4 : DIV_COMPLEX( n1.real, n1.imag, n2.real, n2.imag );
                break;

        case 5 : MOD_COMPLEX( n1.real, n1.imag, n2.real, n2.imag );
                break;
            }
}

return 0;

}


void  ADD_COMPLEX( float a, float b, float c, float d )
{

  printf("%f+%fi\n",a+c,b+d);

}

void  SUB_COMPLEX( float a, float b, float c, float d )
{

  printf("%f+%fi\n",a-c,b-d);

}

void  MULT_COMPLEX( float a, float b, float c, float d )
{

  printf("%f+%fi\n",(a*c-b*d),(a*d+b*c));

}

void  DIV_COMPLEX( float a, float b, float c, float d )
{

  float i=c*c+d*d;

  printf("%f+%fi\n",(a*c+b*d)/i,(b*c-a*d)/i);

}

void  MOD_COMPLEX( float a, float b, float c, float d )
{

  float i,j,k;

  i=(a-c)*(a-c);

  j=(b-d)*(b-d);

  k=sqrt(i+j);

  printf("%.6f\n",k);

}


