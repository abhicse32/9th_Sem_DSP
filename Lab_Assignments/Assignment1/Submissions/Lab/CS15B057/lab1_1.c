/* Program to implement ADT Complex Number and associated operations on them
Author: G.Kavitha
Roll No. CS15B057
Date: 8 August 2016 */

#include<stdio.h>
#include<math.h>
# define Sentinel -1

/* Structure holding the real and imaginary parts of a complex number*/
struct Complex{
	float real;
	float img;
};

/*Function to add 2 complex numbers A and B and store it in C
C=A+B 
C is passed by reference here*/
void add(struct Complex A, struct Complex B,struct Complex* C){
	(*C).real=A.real+B.real;
	(*C).img=A.img+B.img;
}

/*Function to subtract 2 complex numbers and store it in C
C=A-B 
C is passed by reference here*/
void sub(struct Complex A, struct Complex B,struct Complex* C){
	(*C).real=A.real-B.real;
	(*C).img=A.img-B.img;
}

/*Function to multiply 2 complex numbers A and B and store it in C
C=A.B 
C is passed by reference here*/
void mult(struct Complex A, struct Complex B,struct Complex* C){
	(*C).real=(A.real)*(B.real)-(A.img)*(B.img);
	(*C).img=(A.real)*(B.img)+(A.img)*(B.real);
}

/*Function to divide 2 complex numbers A and B and store it in C
C=A/B 
C is passed by reference here*/
int div(struct Complex A, struct Complex B,struct Complex* C){
	if(B.real==0&&B.img==0) {printf("Invalid input - Divide by Zero Error\n"); return -1;}
	(*C).real=((A.real)*(B.real)+(A.img)*(B.img))/((B.real)*(B.real)+(B.img)*(B.img));
	(*C).img=(-1*(A.real)*(B.img)+(A.img)*(B.real))/((B.real)*(B.real)+(B.img)*(B.img));
	return 0;
}

/*Function to find the distance between 2 complex numbers A and B and store it in ans 
ans is passed by reference here*/
void dist(struct Complex A, struct Complex B,float* ans){
	struct Complex C;
	sub(A,B,&C);
	(*ans)=sqrt((C.real)*(C.real)+(C.img)*(C.img));
}

//Main function
int main(){
	struct Complex A,B;
	scanf("%f %f",&(A.real),&(A.img));//Read in first Complex No. 
	scanf("%f %f",&(B.real),&(B.img));//Read in second Complex No.
	int a;
	scanf("%d",&a);//Read in option
	while(a!=Sentinel){
		struct Complex C;
		float ans;
		int flag;//to check for divide by zero error in case of division			
		switch(a){
			case 1: add(A,B,&C); break;
			case 2: sub(A,B,&C); break;
			case 3: mult(A,B,&C); break;
			case 4: flag=div(A,B,&C); break;
			case 5: dist(A,B,&ans); break;
			default: return 0;
		}
		if(a<=3||(a==4&&flag!=-1)) {//Display answer
			if(C.img>=0) printf("%.6f + %.6fi\n",C.real,C.img);
			else printf("%.6f - %.6fi\n",C.real,-1*C.img);
		}
		else if(a==5) {
			printf("%.6f\n",ans);
		}		
		scanf("%f %f",&(A.real),&(A.img));
		scanf("%f %f",&(B.real),&(B.img));
		scanf("%d",&a);
	}
	return 0;
}
