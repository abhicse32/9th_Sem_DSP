//Program to find the hexadecimal equivalent of a number
//Author: B Arjun, CS15B058; Date:10/08/16

#include<stdio.h>
int main(void)
{
	long int n;	// We use long int as 1<n<10^9 is the given range of n.
	char hexout[11];
	scanf("%ld",&n);
/*To set the first two characters to 0x we assign them separately*/
	hexout[0]='0';
	hexout[1]='x';

	int i=9;//The remainers will be assigned from the last character of the string
	while(i>1)
	{
/*n%16 will give the numerical value of remainder, but since we need the character equivalent of that digit we have to add '0'*/
		if(n%16<10)
			hexout[i]=n%16+'0';
		else if(n%16==10)
			hexout[i]='a';
		else if(n%16==11)
			hexout[i]='b';
		else if(n%16==12)
			hexout[i]='c';
		else if(n%16==13)
			hexout[i]='d';
		else if(n%16==14)
			hexout[i]='e';
		else if(n%16==15)
			hexout[i]='f';
		n/=16;
		i--;
	}
	hexout[10]='\0';
	printf("%s",hexout);
}