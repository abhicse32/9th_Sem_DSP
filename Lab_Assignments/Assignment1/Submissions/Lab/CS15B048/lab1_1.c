// Program to implement abstract data type : Complex numbers and associated operations
// Author : G.Kavya CS15B048
// Date : 08.08.2016

#include<stdio.h>
#include<math.h>

//Declaration of structure
struct complexnumber {
  float real;
  float imag;
};

// here num1 is the first number and num2 is the second for order of subtraction and division

void add(struct complexnumber num1, struct complexnumber num2){
  float real_result;
  float imag_result;
  real_result = num1.real + num2.real;
  imag_result = num1.imag + num2.imag;
  printf("%.6f + %.6fi\n", real_result, imag_result);
}

void subtract(struct complexnumber num1, struct complexnumber num2){
  float real_result;
  float imag_result;
  real_result = num1.real - num2.real;
  imag_result = num1.imag - num2.imag;
  printf("%.6f + %.6fi\n", real_result, imag_result);
}

void multiply(struct complexnumber num1, struct complexnumber num2){
  float real_result;
  float imag_result;
  real_result = num1.real * num2.real - num1.imag * num2.imag;
  imag_result = num1.real * num2.imag + num1.imag * num2.real;
  printf("%.6f + %.6fi\n", real_result, imag_result);
}

void divide(struct complexnumber num1, struct complexnumber num2){
  float real_result;
  float imag_result;
  //Check for divide by zero error
  if(num2.real == 0 && num2.imag == 0){
	printf("Oops! You have tried to divide a number by zero. Sending you back to menu now\n");
	return;
  }
  float denom = pow(num2.real, 2) + pow(num2.imag, 2);
  real_result = num1.real * num2.real + num1.imag * num2.imag;
  imag_result = num1.imag * num2.real - num1.real * num2.imag;
  real_result /= denom;
  imag_result /= denom;
  printf("%.6f + %.6fi\n", real_result, imag_result);
}

// Takes 2 complex number and calculates distance using coordinate analogy

void modulus(struct complexnumber num1, struct complexnumber num2){
  float result;
  result = sqrt(pow(num1.real - num2.real, 2) +  pow(num1.imag - num2.imag, 2));
  printf("%.6f\n", result);
}

int main(){
  struct complexnumber numb1;
  struct complexnumber numb2;
  int userchoice;
  /*Program menu
   * Addition : 1
   * Subtraction : 2
   * Multiplication : 3
   * Division : 4
   * Modulus : 5
   */

  while(1){
	scanf("%f %f", &numb1.real, &numb1.imag);
	scanf("%f %f", &numb2.real, &numb2.imag);
	scanf("%d", &userchoice);
	switch(userchoice){
	  case 1: add(numb1, numb2);
			  break;
	  case 2: subtract(numb1, numb2);
			  break;
	  case 3: multiply(numb1, numb2);
			  break;
	  case 4: divide(numb1, numb2);
			  break;
	  case 5: modulus(numb1, numb2);
			  break;
	  case 0: 
	  case -1: return 0; // to exit program
	  default : printf("Invalid choice\n"); 
	}
  }
}

