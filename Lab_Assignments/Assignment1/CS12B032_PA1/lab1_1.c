#include <stdio.h>
#include <math.h>
typedef struct Complex Complex;

struct  Complex{
	float p;
	float q;	
};

Complex addition(Complex num1, Complex num2){
	Complex sum;
	sum.p= num1.p+num2.p;
	sum.q= num1.q+num2.q;
	return sum;
}

Complex subtraction(Complex num1, Complex num2){
	Complex diff;
	diff.p= num1.p-num2.p;
	diff.q= num1.q-num2.q;
	return diff;
}

Complex multiplication(Complex num1, Complex num2){
	Complex product;
	product.p=(num1.p*num2.p - num1.q*num2.q);
	product.q=(num1.p*num2.q + num1.q*num2.p);
	return product;
}

Complex division(Complex num1, Complex num2){     // assuming that real and imaginary parts of num2 are not 0 simultaneously
	Complex multiplicand;
	multiplicand.p= num2.p;
	multiplicand.q= -num2.q;
	Complex numerator=multiplication(num1,multiplicand);
	float denom= (num2.p*num2.p)+(num2.q*num2.q);
	numerator.p/=denom;
	numerator.q/=denom;
	return numerator;
}

float distance(Complex num1,Complex num2){
	return sqrt(pow(num1.p-num2.p,2)+pow(num1.q-num2.q,2));
}

int main(){
	int operation;
	Complex num1, num2;
	while(1){
		scanf("%f%f",&num1.p,&num1.q);
		scanf("%f%f",&num2.p,&num2.q);
		scanf("%d",&operation);
		if(operation<1 || operation > 5)
			break;
		if(operation==5)
			printf("%f\n",distance(num1,num2));
		else{
			switch(operation){
				case 1: 
					num1 = addition(num1,num2);
					break;
				case 2:
					num1 = subtraction(num1,num2);
					break;
				case 3:
					num1 = multiplication(num1,num2);
					break;
				case 4:
					num1 = division(num1, num2);
					break;
				default: break;
			}
			char sign='+';
			if(num1.q < 0){
				num1.q= -num1.q;
				sign='-';
			}
			printf("%.6f %c %.6fi\n",num1.p,sign,num1.q);
		}
	}
	return 0;
}