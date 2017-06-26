/*
 * =====================================================================================
 *
 *
 *    Description:  To Check convert a decimal positive integer to hexadecimal
 *
 *       
 *
 *         Author: Harshavardhan.P.K. 
 *
 * 	  Roll No: CS15B061
 *		Date: 12/8/16
 * =====================================================================================
 */
#include <stdio.h>
#define LEN 8

char * tohex(char *, int);

/* 
 * ========================================================================================
 *
 *	Function: main
 *	Input: num - the input number in decimal form.
 *	
 *	arr[]: stores the hexadecimal form of num in form of string.
 *
 *	Output: prints the hexadecimal form of string
 *
 *
 * ========================================================================================
 * */
int main (void){
	int num;
	scanf ("%d",&num);
	char arr[LEN+1];
	tohex(arr, num);
	if (num>=0)
	printf("0x%s\n",arr);
else
	printf("-0x%s\n",arr);
	return 0;
}


/* 
 * ========================================================================================
 *
 *	Function: tohex - to convert n to hexadecimal form
 *	Input: n - the input number in decimal form.
 *	digit: store individual digits of remainder on successive division by 16.
 *	index: conter to keep track of position to input next character on a[]
 *	a[]: stores the hexadecimal form of num in form of string.
 *
 *	Output: the hexadecimal form of string in array a[].
 *
 *
 * ======================================================================================== 
 */
char * tohex(char *a, int nu){
	unsigned int digit;
	long index=LEN-1;
	unsigned int n = (unsigned int)((nu>=0) ? nu : -nu);
	while(n!=0){
		digit=n%16;

/* 
 *	If digit is nine print as it is but for digit remainder > 9 print appropriate alphabet.
 */		
		if(digit>9)
			a[index] = 'a' + digit - 10;
		else
			a[index] = '0' + digit;
		index--;
/* 
 *	fill rest of the string with '0's 
 * */		n=n/16;

	}
	while (index>=0){
		a[index] = '0';
		index --;
	}
	return a;
}
