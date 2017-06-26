/*Program to print the hexadecimal form of a given number in decimal form
		G.Pranav	CS15B015	10-8-2016*/
#include<stdio.h>
void printchar(int x);
int main(){
	int n;
	scanf("%d",&n);
	int i;
	int dividend=n;
	int hex[8];		//array to store the digits after dividing by 16
	for(i=0;i<8;i++){
		hex[i]=dividend%16;
		dividend=dividend/16;
	}
	printf("0x");	//printing 0x before the hexadecimal form of the number
	for(i=7;i>=0;i--){
		printchar(hex[i]);	//calling the function printchar to print the hexadecimal character corresponding to the given digit
	}
	printf("\n");
	return 0;
}
/* Function to print the character corresponding to the digit received as argument in hexadecimal form*/
void printchar(int x){
	if(x<=9) printf("%d",x);
	else{
		if(x==10) printf("a");
		else if(x==11) printf("b");
		else if(x==12) printf("c");
		else if(x==13) printf("d");
		else if(x==14) printf("e");
		else printf("f");
	}
}