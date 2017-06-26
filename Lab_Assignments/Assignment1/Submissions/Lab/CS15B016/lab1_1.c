/* 
THIS PROGRAM DEALS WITH COMPLEX NUMBERS AND 5 OPERATIONS ASSOCIATED WITH THEM:
(a)  Addition of two Complex Numbers
(b)  Subtraction of two Complex Numbers
(c)  Multiplication of two Complex Numbers
(d)  division of two Complex Numbers
(e)  Modulus/Magnitude/Absolute value of a Complex Number

DATE: 8 AUG 2016
AUTHOR: GIRIDHAR S
*/
#include <stdio.h>
#include <math.h>

struct complex{
  float real;
  float imaginary;
};



/*FUNCTION TO READ COMPLEX NUMBER INPUT
  Returns the input complex number.*/

struct complex read_complex(){
  struct complex input;
  scanf("%f",&input.real);
  scanf("%f",&input.imaginary);
  return input;
}



/*FUNCTION FOR ADDING TWO COMPLEX NOS.
Takes as input two complex numbers in structure form.
Returns as output sum of the two complex numbers, as a complex number in structure form. */

struct complex add_complex(struct complex c1, struct complex c2){
  struct complex sum;
  sum.real=c1.real+c2.real;
  sum.imaginary=c1.imaginary+c2.imaginary;
  return sum;
}


/*FUNCTION FOR SUBTRACTING TWO COMPLEX NOS.
Takes as input two complex numbers in structure form.
Returns as output difference of the two complex numbers (first argument-second argument), as a complex number in 
structure form. */

struct complex subtract_complex(struct complex c1, struct complex c2){
  struct complex diff;
  diff.real=c1.real-c2.real;
  diff.imaginary=c1.imaginary-c2.imaginary;
  return diff;
}


/*FUNCTION FOR MULTIPLYING TWO COMPLEX NOS.
Takes as input two complex numbers in structure form.
Returns as output product of the two complex numbers, as a complex number in structure form. */

struct complex multiply_complex(struct complex c1, struct complex c2){
  struct complex product;
  product.real=c1.real*c2.real-c1.imaginary*c2.imaginary;
  product.imaginary=c1.real*c2.imaginary+c1.imaginary*c2.real;
  return product;
}


/*FUNCTION TO FIND DISTANCE BETWEEN TWO COMPLEX NUMBERS
INPUT: Two complex numbers
OUTPUT: distance in floating point. */

float distance_complex(struct complex c1, struct complex c2){
  float real_diff=c1.real-c2.real;
  float imaginary_diff=c1.imaginary-c2.imaginary;
  float modulus=sqrt((real_diff)*(real_diff)+(imaginary_diff)*(imaginary_diff));
  return modulus;
}




/*FUNCTION FOR DIVISION OF TWO COMPLEX NOS.
Takes as input two complex numbers in structure form.
Returns as output C1/C2, where C1 is the first argument and C2 is the second argument, as a complex number in 
structure form. */

struct complex divide_complex(struct complex c1, struct complex c2){
  struct complex quotient;
  struct complex c2_conj;
  c2_conj.real=c2.real; c2_conj.imaginary=(c2.imaginary*(-1));
  quotient=multiply_complex(c1,c2_conj);
  struct complex origin;
  origin.real=0;
  origin.imaginary=0;
  float modulus=distance_complex(c2, origin);
  float denominator=modulus*modulus;
  quotient.real/=denominator;
  quotient.imaginary/=denominator;
  return quotient;
}

//FUNCTION FOR PRINTING THE COMPLEX NUMBER

void print_complex(struct complex c1){
  if(c1.imaginary>=0){
     printf("%f + %fi",c1.real,c1.imaginary);
  }
  else if(c1.imaginary<0){
    printf("%f - %fi",c1.real,c1.imaginary*(-1));

  }
}


/*MAIN ALLOWS THE USER TO INPUT 2 COMPLEX NUMBERS, AND THE ASSOCIATED OPERATIONS, CALLS THE APT FUNCTIONS, PRINTS THE RESULT. */

int main(){
     
  struct complex output;
  float distance;
  int choice=1;
  
  do{
     struct complex input1, input2;
     input1=read_complex();
     input2=read_complex();
     scanf("%d",&choice);
     switch(choice){
     case 1: 
       output=add_complex(input1,input2);
       print_complex(output);
       break;

     case 2: 
       output=subtract_complex(input1,input2);
       print_complex(output);
       break;

     case 3: 
       output=multiply_complex(input1,input2);
       print_complex(output);
       break;

     case 4:if(input2.real==0){
	 if(input2.imaginary==0){
	   printf("Error! Division by zero");
	   break;
	 }
       }

    
       output=divide_complex(input1,input2);
       print_complex(output);
       break;
    
     case 5: 
       distance=distance_complex(input1,input2);
       printf("%.6f",distance);
       break;

     default: printf("exit");
       break;

     }
     printf("\n\n");
  
  }while(choice!=-1);
}
