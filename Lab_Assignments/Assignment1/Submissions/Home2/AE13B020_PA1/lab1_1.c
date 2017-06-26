#include <stdio.h>
#include <math.h>

struct Complex {
    float real;
    float imag;
};

float modulus(struct Complex number1, struct Complex number2) {
    float dist, a = number1.real, b = number1.imag, c = number2.real, d = number2.imag;
    dist = (float) sqrt(pow((a - c), 2) + pow((b - d), 2));
    return dist;
}

void add(struct Complex number1, struct Complex number2) {
	float a,b;
	a=number1.real + number2.real;
	b=number1.imag + number2.imag;
	if (b>=0)
    	printf("%.6f+%.6fi\n", a, b);
    else
    	printf("%.6f%.6fi\n", a, b);
    return;
}

void substract(struct Complex number1, struct Complex number2) {
	number2.real=-number2.real;
	number2.imag=-number2.imag;
	add(number1,number2);
    return;
}

void multiply(struct Complex number1, struct Complex number2) {
    struct Complex number3;
    float a = number1.real, b = number1.imag, c = number2.real, d = number2.imag;
    number3.real = (a * c - b * d);
    number3.imag = (a * d + b * c);
	if (b>=0)
    	printf("%.6f+%.6fi\n", a, b);
    else
    	printf("%.6f%.6fi\n", a, b);
    return;
}

void divide(struct Complex number1, struct Complex number2) {
    float dist = (float) (pow((number2.real), 2) + pow((number2.imag), 2));
    if (number1.real == number2.real && number2.imag == number2.imag) {
        return;
    }
    number2.real = number2.real / dist;
    number2.imag = -number2.imag / dist;
    multiply(number1, number2);
    return;
}


void main() {
    struct Complex number1, number2;
    int func;
    float a, b,dist;
    scanf("%f %f", &a, &b);
    number1.real = a;
    number1.imag = b;
    scanf("%f %f", &a, &b);
    number2.real = a;
    number2.imag = b;
    scanf("%d", &func);
    while(func>=1 && func<=5){
        switch (func) {
            case 1:
                add(number1, number2);
                break;
            case 2:
                substract(number1, number2);
                break;
            case 3:
                multiply(number1, number2);
                break;
            case 4:
                divide(number1, number2);
                break;
            case 5:
                dist=modulus(number1, number2);
                printf("%f\n",dist);
                break;
            default:
                break;
        }
        scanf("%d", &func);
    }
}
