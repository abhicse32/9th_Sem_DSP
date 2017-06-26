#include<stdio.h>               /* Program for arithmetic operations on Complex numbers  */
#include<math.h>

struct cmplx {
        float real;
        float imgn;
    };
    
void ADD ( struct cmplx x, struct cmplx y );        // Addition function of complex numbers
void SUBSTRACT ( struct cmplx x, struct cmplx y );  // Substraction function of complex numbers
void MULTIPLY ( struct cmplx x, struct cmplx y );   // Multiplication function of complex numbers
void DIVISION ( struct cmplx x, struct cmplx y );   // Division function of complex numbers
void MODULUS ( struct cmplx x, struct cmplx y );    // Modulus function of complex numbers


int main () {

    struct cmplx numb1, numb2; 
    int operation;
   // printf("Addition : 1\nSubstraction : 2\nMultiplication : 3\nDivision : 4\nModulus : 5\n To end the program: -1\n");
   // printf(" Enter two complex numbers : ");     
   operation = 0;
   while(operation != -1){
    scanf("%f%f%f%f%d", &numb1.real, &numb1.imgn, &numb2.real, &numb2.imgn, &operation); //input
    
    switch(operation){
        case -1 : return 0;     // Assigning sentinel value -1
        case 1 : ADD(numb1, numb2); break;
        case 2 : SUBSTRACT(numb1, numb2); break;
        case 3 : MULTIPLY(numb1, numb2); break;
        case 4 : DIVISION(numb1, numb2); break;
        case 5 : MODULUS(numb1, numb2); break;
    }
    }
 
    }

void ADD (struct cmplx x, struct cmplx y ) {
    
    x.real = x.real + y.real;
    x.imgn = x.imgn + y.imgn;
    
    if(x.imgn >= 0) printf("%.6f + %.6fi\n", x.real, x.imgn);
    else printf("%.6f - %.6fi\n", x.real, -1*x.imgn);
    return;   
}

void SUBSTRACT ( struct cmplx x, struct cmplx y ){
    
    x.real = x.real - y.real;
    x.imgn = x.imgn - y.imgn;

    if(x.imgn >= 0) printf("%.6f + %.6fi\n", x.real, x.imgn);
    else printf("%.6f - %.6fi\n", x.real, -1*x.imgn);
    return;
}

void MULTIPLY ( struct cmplx x, struct cmplx y ){

    x.real = x.real*y.real - x.imgn*y.imgn;
    x.imgn = x.real*y.imgn + x.imgn*y.real;
    
    if(x.imgn >= 0) printf("%.6f + %.6fi\n", x.real, x.imgn);
    else printf("%.6f - %.6fi\n", x.real, -1*x.imgn);
    return;
}

void DIVISION ( struct cmplx x, struct cmplx y ){
    int k;
    k = y.real*y.real + y.imgn*y.imgn;              // Dividing two numbers by multiplying conjugate in numerator and denominator
    
    x.real = (x.real*y.real + x.imgn*y.imgn)/k ;
    x.imgn = (-1*x.real*y.imgn + x.imgn*y.real)/k;
    
    if(x.imgn >= 0) printf("%.6f + %.6fi\n", x.real, x.imgn);
    else printf("%.6f - %.6fi\n", x.real, -1*x.imgn);
    return;
}

void MODULUS ( struct cmplx x, struct cmplx y){
    
    float diff1, diff2;
    float distance;
    diff1 = x.real - y.real;                
    diff2 = x.imgn - y.imgn;
    
    diff1 = diff1*diff1;                    // Difference in real co-ordinates 
    diff2 = diff2*diff2;                    // Difference in imgn co-ordinates    
    distance = sqrt(diff1 + diff2);         // Distance between two complex numbers    
    printf("%.6f\n", distance);
    return; 
}

