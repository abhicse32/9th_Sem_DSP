/* Program to perform addition, subtraction, multiplication, division and finding the modulo of complex numbers
	G.Pranav CS15B015 	8th august 2016*/
#include<stdio.h>
#include<math.h>
struct complexno{     /*structure defined to create and manipulate complex numbers*/
	float rpart;
	float ipart;
};
void addition(struct complexno a,struct complexno b);
void subtraction(struct complexno a,struct complexno b);
void multiplication(struct complexno a,struct complexno b);
void division(struct complexno a,struct complexno b);
void distance(struct complexno a,struct complexno b);
int main(){
	struct complexno no1,no2;
	int choice;
	do{
    scanf("%f%f%f%f",&no1.rpart,&no1.ipart,&no2.rpart,&no2.ipart);
	scanf("%d",&choice);
	if(choice==1) addition(no1,no2);	
	else if(choice==2) subtraction(no1,no2);
	else if(choice==3) multiplication(no1,no2);
	else if(choice==4) division(no1,no2);
	else if(choice==5) distance(no1,no2);
	}while((choice!=-1)&&(choice!=0));	/*setting -1 and 0 as the sentinal values*/
return 0;
}
void print(struct complexno a){	/*function to print complex numbers in the required format*/
	printf("%f%+fi",a.rpart,a.ipart);
}
void addition(struct complexno a,struct complexno b){  /*function that receives two complex numbers as arguments and calls the print function to print 																	their sum*/ 
	struct complexno sum;
	sum.rpart=a.rpart+b.rpart;
	sum.ipart=a.ipart+b.ipart;
	print(sum);
}
void subtraction(struct complexno a,struct complexno b){	 /*function that receives two complex numbers as arguments and calls print function 															to print their difference*/ 
	struct complexno dif;
	dif.rpart=a.rpart-b.rpart;
	dif.ipart=a.ipart-b.ipart;
	print(dif);
}
void multiplication(struct complexno a,struct complexno b){	 /*function that receives two complex numbers as arguments and calls print function 																to print their product*/ 
	struct complexno pdt;
	pdt.rpart=(a.rpart*b.rpart)-(a.ipart*b.ipart);
	pdt.ipart=(a.ipart*b.rpart)+(a.rpart*b.ipart);
	print(pdt);
}
void division(struct complexno a,struct complexno b){	 /*function that receives two complex numbers as arguments, divides them and calls the 														print function to print the result*/ 
	struct complexno div;
	div.rpart=((a.rpart*b.rpart)+(a.ipart*b.ipart))/((b.rpart*b.rpart)+(b.ipart*b.ipart));
	div.ipart=((a.ipart*b.rpart)-(a.rpart*b.ipart))/((b.rpart*b.rpart)+(b.ipart*b.ipart));
	print(div);
}
void distance(struct complexno a,struct complexno b){	/*function that receives two complex numbers as arguments and calls print function 													to print the distance between them*/
	float dis;
	dis=sqrt(((a.rpart-b.rpart)*(a.rpart-b.rpart))+((a.ipart-b.ipart)*(a.ipart-b.ipart)));
	printf("%f\n",dis);
}

	












