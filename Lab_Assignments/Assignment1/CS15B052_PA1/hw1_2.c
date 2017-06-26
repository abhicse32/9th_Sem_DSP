// Home Assignement 1 Question 2
// Finding hex equivalent of a given integer n
// Author : Milind Srivastava
// Date : 9 Aug 2016

#include <stdio.h>

int main()
{
	long int input;

	scanf("%ld",&input);

	char hex[8]; // array to store hex equivalent

	int i=0;

	for(i=0;i<8;i++)
	{
		hex[i] = '0';
	} 

	i=0;

	while(input > 0)
	{
		switch(input%16) // assigning values to hex array based on modulus of number mod 16
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:hex[i] = (char)(input%16 + 48);break;
			case 10:hex[i] = 'a';break;
			case 11:hex[i] = 'b';break;
			case 12:hex[i] = 'c';break;
			case 13:hex[i] = 'd';break;
			case 14:hex[i] = 'e';break;
			case 15:hex[i] = 'f';break;
		}
		i++;
		input/=16;
	}

	printf("%s","0x");

	for(i=7;i>=0;i--)
	{
		printf("%c",hex[i]); // printing array in reverse
	}
	printf("\n");

	return 0;
}
