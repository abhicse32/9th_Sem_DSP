/*CS15B059 KOMMURU ALEKHYA REDDY DATE-8AUG16
PERFORMING ARITHMETIC OPERATIONS ON COMPLEX NUMBERS*/
#include<stdio.h>
#include<math.h>
struct no
{
	float first;
	float second;
};// Declaring a data type number
void add(struct no one,struct no two);
void sub(struct no one,struct no two);
void mult(struct no one,struct no two);
void div(struct no one, struct no two);
void dist(struct no one,struct no two);//prototypes of all the functions
void main()
{      struct no one,two;
	int dec;
	int option;// declaring the option variable
      
	
	do{
	
		scanf("%f %f",&(one.first),&(one.second));//obtaining the first number
		scanf("%f %f",&two.first,&two.second);//obtaining the second number
		scanf("%d",&option);//obtaining their decision
	switch(option){
		case 1: add(one,two);			
			break;

		case 2: sub(one,two);
			break;

		case 3: mult(one,two);
			break;

		case 4: div(one,two);
			break;
		
		case 5:dist(one,two);
			break;
		default:break;
		
	}//switch statement to decide the operation being performed
	}while(option!=-1);//checking the termination condition inputted by the user using a do while loop
	

}

//add function, used to add two complex numbers of the struct no data type, returns nothing
void add(struct no one,struct no two)
{  
	struct no result;
	result.first=one.first+two.first;
	result.second=one.second+two.second;
		if(result.second>=0)
			printf("%f + %fi\n",result.first,result.second);
		else
			{
			float a=result.second*-1;
			printf("%f - %fi\n",result.first,a);			
			}
}

//sub function, used to sub used to subtract the second complex number from the first of the struct no data type, returns nothing
void sub(struct no one,struct no two)
{
	struct no result;
	result.first=one.first-two.first;
	result.second=one.second-two.second;
		if(result.second>=0)
			printf("%f + %fi\n",result.first,result.second);
		else
			{
			float b=result.second*-1;
			printf("%f - %fi\n",result.first,b);			
			}
}
//mult function, used to multiply two complex numbers of the struct no data type, returns nothing
void mult(struct no one,struct no two)
{
	struct no result;
	result.first=one.first*two.first-one.second*two.second;
	result.second=one.second*two.first+one.first*two.second;
		if(result.second>=0)
			printf("%f + %fi\n",result.first,result.second);
		else
			{
			float c=result.second*-1;
			printf("%f - %fi\n",result.first,c);			
			}
}

//div function, used to divide two complex numbers of the struct no data type, returns nothing, checks for division by 0 error
void div(struct no one, struct no two)
{
	struct no result;
	if(two.first!=0 && two.second!=0)
		{
			result.second=(one.second*two.first-two.second*one.first)/(two.first*two.first+two.second*two.second);
			result.first=(one.first*two.first+one.second*two.second)/(two.first*two.first+two.second*two.second);
		if(result.second>=0)
			printf("%f + %fi\n",result.first,result.second);
		else
			{
			float d=result.second*-1;
			printf("%f - %fi\n",result.first,d);			
			}  
		}
	else
		printf("Division by 0 error");
     
}
// calculates the distance between two complex numbers
void dist(struct no one,struct no two)
{
	float result;
	float a,b;
	
	a=(one.first-two.first)*(one.first-two.first);
	b=(one.second-two.second)*(one.second-two.second);
	result=sqrt(a+b);      
	printf("%f\n",result);
	

}
