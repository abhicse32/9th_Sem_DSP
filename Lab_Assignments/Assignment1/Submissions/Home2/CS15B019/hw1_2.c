//file content - Converting a decimal number into Hexadecimal System
//author - Shiva Poojith
//date - 14/08/2016

#include <stdio.h>

int main()
{
	int n,i,j;
	int temp,rem;
	char hexdec[100];

	scanf("%d",&n);

	temp = n;
	while(temp) {
		rem = temp%16;

		if(rem < 10) 
			hexdec[j++] = rem+'0';
		else 
			hexdec[j++] = rem+'a'-10;    

		temp/=16;
	}

	// as 16^8 > 10^9 every n <10^9 can be represented within 8-bits in hexadecimal system
	for (i = 8-j;i--;)
		hexdec[j++] = '0';  // leading zeroes 

	printf("0x");           // "0x" - standard notion to start any hexadecimal number
	for (i = j-1;i>=0;i--)
		printf("%c",hexdec[i]);
	printf("\n");
}
