/*CS15B059 KOMMURU ALEKHYA REDDY 12AUG2016
TO PRINT THE HEXADECIMAL EQUIVALENT OF A DECIMAL NUMBER*/
#include<stdio.h>
void hex(int rem);//defining the function
void main()
{

	int n;
	printf("Enter the decimal number");
	scanf("%d",&n);//input the decimal number to be converted

	int rem=0;
	hex(n);//defining a recursive function to print 
}

void hex(int n)
{
	if(n==0){
		printf("0");
				
		}

	else if(n==1){
		printf("1");
			
		}

	else if(n==2){
		printf("2");
				
		}

	else if(n==3){
		printf("3");
				
		}

	else if(n==4){
		printf("4");
				
		}

	else if(n==5){
		printf("5");
			
		}

	else if(n==6){
		printf("6");
			
		}

	else if(n==7){
		printf("7");
			
		}
	else if(n==8){
		printf("8");
			
		}

	else if(n==9){
		printf("9");
		
		}

	else if(n==10){
		printf("A");
		
		}

	else if(n==11){
		printf("B");
				
		}

	else if(n==12){
		printf("C");
			
		}

	else if(n==13){
		printf("D");
			
		}

	else if(n==14){
		printf("E");
			
		}

	else if(n==15){
		printf("F");//16 base conditions which print the last remainder, then the next and so on
			
		}

	else 
		{ hex(n/16);//if n is greater than 16 then continue to divide it and then print its remainders recursively
		hex(n%16);}

	
}
