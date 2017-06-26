#include <stdio.h>

int main()
{
    int n,i;
	char hex[10];
	scanf("%d",&n);
	for( i=9 ; i>1 ; i = i-1)   //as the result is to be printed in reverse of remainders list
	{
        switch(n%16)    //remainder
        {
            case 0 : hex[i]='0'; break;
            case 1 : hex[i]='1'; break;
            case 2 : hex[i]='2'; break;
            case 3 : hex[i]='3'; break;
            case 4 : hex[i]='4'; break;
            case 5 : hex[i]='5'; break;
            case 6 : hex[i]='6'; break;
            case 7 : hex[i]='7'; break;
            case 8 : hex[i]='8'; break;
            case 9 : hex[i]='9'; break;
            case 10 : hex[i]='a'; break;
            case 11 : hex[i]='b'; break;
            case 12 : hex[i]='c'; break;
            case 13 : hex[i]='d'; break;
            case 14 : hex[i]='e'; break;
            case 15 : hex[i]='f'; break;
        }
        n=n/16;   //getting the quotient
	}
	hex[0]='0';           //assigning first two elements of a string
	hex[1]='x';
	printf("%s",hex);
	return 0;
}
