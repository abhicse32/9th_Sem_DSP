#include<stdio.h>
char Hexadecimal(int n)
{
 	switch(n)
 	{
 		case 0:
 		return '0';
 		case 1:
 		return '1';
 		case 2:
 		return '2';
 		case 3:
 		return '3';
 		case 4:
 		return '4';
 		case 5:
 		return '5';
 		case 6:
 		return '6';
 		case 7:
 		return '7';
 		case 8:
 		return '8';
 		case 9:
 		return '9';
 		case 10:
 		return 'A';
 		case 11:
 		return 'B';
 		case 12:
 		return 'C';
 		case 13:
 		return 'D';
 		case 14:
 		return 'E';
 		case 15:
 		return 'F';
 		
 		default: return '0';
 	}
}
int main()
{
	int n,rem,i;
	scanf("%d",&n);
	char hex[10]="00000000x0";
	for(i=0;i<8;i++)
	{
		rem= n%16;
		n= n/16;
		hex[i]= Hexadecimal(rem);
	}
	for(i=9;i>=0;i--)
	{
		printf("%c",hex[i]);
	}
	printf("\n");
	return 0;
	
}
