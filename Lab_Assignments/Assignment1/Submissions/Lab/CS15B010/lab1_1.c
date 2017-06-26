/* a program to add / subtract / multiply / divide / find distance between two complex numbers this repeats until program is terminated using a sentital value 0 or -1*/

/* author: vinay chilaka cs15b010
   date:8/8/16 for lab assignment 1 question 1*/ 


#include<stdio.h>
#include<math.h>

//declaring a global structure variable
struct complex{
	float r;
	float i;
	};


//declarations of functions used
int add(struct complex x, struct complex y);
int subtract(struct complex x, struct complex y);
int multiply(struct complex x, struct complex y);
int div(struct complex x, struct complex y);
int modulus(struct complex x, struct complex y);


//main function
int main(){
	int next;
	struct complex a;
	struct complex b;
	//do while is used to ensure atleast one iteration
	do{
		scanf("%f %f %f %f",&a.r,&a.i,&b.r,&b.i);
		scanf("%d",&next);
		switch(next){
			//to call respective functions
			case 1: add(a,b); break;
			case 2: subtract(a,b); break;
			case 3: multiply(a,b); break;
			case 4: div(a,b); break;
			case 5: modulus(a,b); break;
		}
	}while(next!=-1&&next!=0);
	return 0;
}

int add(struct complex x, struct complex y){		//function to add
	struct complex z;
	z.i=x.i+y.i;
	z.r=x.r+y.r;
	if(z.i>=0) { printf("%f + %fi",z.r,z.i); }
		else {	printf("%f - %fi",z.r,z.i); }
	return 1;
}

int subtract(struct complex x, struct complex y){	//function to subtract
	struct complex z;
	z.i=x.i-y.i;
	z.r=x.r-y.r;
	if(z.i>=0) { printf("%f + %fi",z.r,z.i); }
		else {	printf("%f - %fi",z.r,z.i); }
	return 1;
}

int multiply(struct complex x, struct complex y){	//function to multiply
	struct complex z;
	z.i=x.i*y.r + x.r*y.i;
	z.r=x.r*y.r - x.i*y.i;
	if(z.i>=0) { printf("%f + %fi",z.r,z.i); }
		else {	printf("%f - %fi",z.r,z.i); }
	return 0;
}

int div(struct complex x, struct complex y){	//function to divide
	struct complex z;
	float mody;
	mody = (y.r*y.r + y.i*y.i);				//the denominator term
	if(mody==0){return -1;}
	z.r = (x.r+y.r + x.i*y.i)/mody;
	z.i = (y.r*x.i - x.r*y.i)/mody;
	if(z.i>=0){ printf("%f + %fi",z.r,z.i); }
		else{	printf("%f - %fi",z.r,z.i); }
	return 0;
}

int modulus(struct complex x, struct complex y){		//to find distance between to comp numbers
	float dist;
	dist=(x.i-y.i)*(x.i-y.i)+(x.r-y.r)*(x.r-y.r);
	float dist1 = sqrt(dist);
	printf("%f",dist1);
	return 0;
}
