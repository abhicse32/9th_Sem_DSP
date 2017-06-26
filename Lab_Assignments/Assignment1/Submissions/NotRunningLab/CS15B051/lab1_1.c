#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct complex
 {
   float real;
   float imag;
 };

typedef struct complex Complex;
 
Complex complex_number(float real,float imag)
  {   
    
     Complex c1; 
     c1.real = real; 
     c1.imag = imag; 
     return c1;
  }   
Complex add_complex(Complex a,Complex b)
{
  
  Complex addn;
  addn.real = a.real + b.real;  
  addn.imag = a.imag + b.imag;  

  return addn; 
}
 Complex sub_complex(Complex a,Complex b)
{
   
  Complex subt;
  subt.real = a.real - b.real;  
  subt.imag = a.imag - b.imag;  
  
  return subt;
}
Complex mul_complex(Complex a,Complex b)
{
  Complex mult;
  mult.real = ((a.real)*(b.real))-((a.imag)*(b.imag));
  mult.imag = ((a.real)*(b.imag))+((a.imag)*(b.real));

  return mult;
}

Complex div_complex(Complex a,Complex b)
{
  Complex divn;
  float temp;
  temp=sqrt((b.real)*(b.real)+(b.imag)*(b.imag));
  divn.real=((a.real)*(b.real))+((a.imag)*(b.imag))/temp;
  divn.imag=((a.imag)*(b.real)-(a.real)*(b.imag))/temp;
  
  return divn;
}

float mod_complex(Complex a,Complex b)
{
   float modl,temp1,temp2;
   temp1= a.real - b.real;
   temp2= a.imag - b.imag;
   modl=sqrt(temp1*temp1+temp2*temp2);
   
  return modl;
}



int main()
{
  Complex p,q,c;
  int choice;
  float m;
  float r1,r2,i1,i2;
 while(1)
 {
  scanf("%f%f",&r1,&i1);
  p=complex_number(r1,i1);
  scanf("%f%f",&r2,&i2);
  q=complex_number(r2,i2);
    /*    MENU OPTIONS
    printf("Press 1 to add two complex numbers.\n");
    printf("Press 2 to subtract two complex numbers.\n");
    printf("Press 3 to multiply two complex numbers.\n");
    printf("Press 4 to divide two complex numbers.\n");
    printf("Press 5 to find dist btwn two complex numbers.\n");
    printf("Press 0 to exit.\n");
    printf("Enter your choice\n");*/
    scanf("%d",&choice);
    switch(choice)
    {
      case 0: exit(0);
              break;
      case 1: c = add_complex(p,q);
              printf("%f",c.real);
              printf("+%fi",c.imag);
              break;
      case 2: c = sub_complex(p,q);
              printf("%f",c.real);
              printf("+%fi",c.imag);
              break;
      case 3: c = mul_complex(p,q);
              printf("%f",c.real);
              printf("+%fi",c.imag);
              break;
      case 4: c = div_complex(p,q);
              printf("%f",c.real);
              printf("+%fi",c.imag);
              break;
      case 5: m = mod_complex(p,q);
              printf(".6f",m);
              break;
      
     }
 }
 return 0;
  
}
