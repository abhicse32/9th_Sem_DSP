#include<stdio.h>
#include<math.h>

struct num add(struct num ,struct num);	//to add the complex numbers
struct num sub(struct num ,struct num);	//to subract the complex numbers
struct num mult(struct num ,struct num);	//to multiply the complex numbers
struct num div(struct num ,struct num);	//to divide the complex numbers
float dist(struct num ,struct num); 	//to find the distance between the complex numbers
struct num{
	float real;
	float image;
}first,second,result;

int main(){
	
	int op;
	float distance;

	printf("1.Addition\n2.Subraction\n3.Multiplication\n4.Division\n5.Modulus\nSentinel-Value is -1\n");
	printf("Enter real and imaginary part of two complex numbers:\n");
	scanf("%f%f",&first.real,&first.image);
	scanf("%f%f",&second.real,&second.image);
	printf("enter choice\n");
	scanf("%d",&op);
	switch(op){
		case 1:
			{result=add(first,second);
			break;}
		case 2:
			{result=sub(first,second);
			break;}
		case 3:
			{result=mult(first,second);
			break;}
		case 4:
			{result=div(first,second);
			break;}
		case 5:
			{distance=dist(first,second);
				printf("%.6f\n",distance);
			break;}
	}
	
	return 0;
}

struct num add(struct num first ,struct num second){
	result.real=first.real+second.real;
	result.image=first.image+second.image;
	printf("%f+%fi\n",result.real,result.image);
	return result;
}

struct num sub(struct num first ,struct num second){
	result.real=first.real-second.real;
	result.image=first.image-second.image;
	if(first.image>=second.image){
			printf("%f+%fi\n",result.real,result.image);
	}
	else{printf("%f-%fi\n",result.real,(-1*result.image));
	}
	return result;
}

struct num mult(struct num first ,struct num second){
	result.real=(first.real*second.real)-(first.image*second.image);
	result.image=(first.real*second.image)+(first.image*second.real);
	printf("%f+%fi\n",result.real,result.image);
	return result;
}

struct num div(struct num first ,struct num second){
	float add;
	add=((second.real*second.real)+((second.image)*(second.image)));	
	result.real=(first.real*second.real)+(first.image*second.image);
	result.image=(first.image*second.real)-(first.real*second.image);
	result.real=result.real/add;
	result.image=result.image/add;
	if(result.image>=0){
		printf("%f+%fi\n",result.real,result.image);
	}
	else{printf("%f-%fi\n",result.real,(-1*result.image));
}
	return result;
}

float dist(struct num first ,struct num second){
	float length,add;
	add=(((first.real-second.real)*(first.real-second.real))+((first.image-second.image)*(first.image-second.image)));
	length=sqrt(add);
	return length;
}
