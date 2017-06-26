/*PROGRAM TO DISPLAY THE HEXADECIMAL EQUIVALENT OF A DECIMAL NUMBER.
DATE: 14TH AUGUST 2016
AUTHOR: GIRIDHARS, CS15B016*/
#include<stdio.h>


int main(){
	int n;                    //number in decimal form

	int hex=0x00000001;

	scanf("%d",&n);

	hex=n;

	printf("%#010x\n",hex);
}




