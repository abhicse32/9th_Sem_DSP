#include <stdio.h>
#include <math.h>

struct complex{
	float real;
	float imaginary;
};

void add(struct complex complex1,struct complex complex2){
	struct complex result;
	result.real = complex1.real +complex2.real;
	result.imaginary = complex1.imaginary + complex2.imaginary;
	if(result.imaginary > 0)	
		printf("%f + %fi\n",result.real,result.imaginary);
	else if(result.imaginary < 0) printf("%f - %fi\n",result.real,-result.imaginary);
	else printf("%f \n",result.real);
	return;
}

void sub(struct complex complex1,struct complex complex2){
	struct complex result;
	result.real = complex1.real - complex2.real;
	result.imaginary = complex1.imaginary - complex2.imaginary;
	if(result.imaginary > 0)	
		printf("%f + %fi\n",result.real,result.imaginary);
	else if(result.imaginary < 0) printf("%f - %fi\n",result.real,-result.imaginary);
	else printf("%f \n",result.real);
	return;
}

void mult(struct complex complex1,struct complex complex2){
	struct complex result;
	result.real = complex1.real* complex2.real - complex1.imaginary *complex2.imaginary;
	result.imaginary = complex1.real*complex2.imaginary + complex2.real*complex1.imaginary;
	if(result.imaginary > 0)	
		printf("%f + %fi\n",result.real,result.imaginary);
	else if(result.imaginary < 0) printf("%f - %fi\n",result.real,-result.imaginary);
	else printf("%f \n",result.real);
	return;
}

void div(struct complex complex1,struct complex complex2){
	struct complex result;
	int modulusofcomp2 = complex2.real*complex2.real + complex2.imaginary*complex2.imaginary;
	result.real = (complex1.real* complex2.real + complex1.imaginary *complex2.imaginary)/modulusofcomp2;
	result.imaginary = (-complex1.real*complex2.imaginary + complex2.real*complex1.imaginary)/modulusofcomp2;
	if(result.imaginary > 0)	
		printf("%f + %fi\n",result.real,result.imaginary);
	else if(result.imaginary < 0) printf("%f - %fi\n",result.real,-result.imaginary);
	else printf("%f \n",result.real);
	return;
}

void distance(struct complex complex1,struct complex complex2){
	float distance;
	distance = sqrt((complex1.real - complex2.real)*(complex1.real - complex2.real) + (complex1.imaginary - complex2.imaginary)*(complex1.imaginary - complex2.imaginary));
	printf("%0.6f \n",distance);	
	return;
}
int main(){
	int operationid;	
	struct complex complex1,complex2;
	scanf("%f%f%f%f",&complex1.real,&complex1.imaginary,&complex2.real,&complex2.imaginary);
	scanf("%d",&operationid);
	while(operationid != 0){			
		switch(operationid){
			case 1:add(complex1,complex2);	break; 
			case 2:sub(complex1,complex2);	break;
			case 3:mult(complex1,complex2);	break;
			case 4:div(complex1,complex2);	break;
			case 5:distance(complex1,complex2);	break;		
		}
		scanf("%f%f%f%f",&complex1.real,&complex1.imaginary,&complex2.real,&complex2.imaginary);
		scanf("%d",&operationid);
	}
	return 0;
}




	

