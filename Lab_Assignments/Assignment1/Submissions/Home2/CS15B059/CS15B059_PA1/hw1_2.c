/*CS15B059 KOMMURU ALEKHYA REDDY 12AUG2016
TO PRINT THE HEXADECIMAL EQUIVALENT OF A DECIMAL NUMBER*/
#include<stdio.h>
void hex(int n,char *a);//defining the function
void main()
{

	int n;
	scanf("%d",&n);//input the decimal number to be converted
	char a[7];
	int rem=0;
	printf("0x0");
	hex(n,a);//defining a recursive function to print 
	int i;	
	for(i=0;i<7;i++)
		printf("%c",a[i]);
}

void hex(int n,char* a)
{
	int j;
	for(j=6;j>=0;j--)
	{
	int i=n%16;
	n=n/16;
	switch(i)
		{
		case 0:*(a+j)='0';break;
		case 1:*(a+j)='1';break;
		case 2:*(a+j)='2';break;
		case 3:*(a+j)='3';break;
		case 4:*(a+j)='4';break;
		case 5:*(a+j)='5';break;
		case 6:*(a+j)='6';break;
		case 7:*(a+j)='7';break;
		case 8:*(a+j)='8';break;
		case 9:*(a+j)='9';break;
		case 10:*(a+j)='a';break;
		case 11:*(a+j)='b';break;
		case 12:*(a+j)='c';break;
		case 13:*(a+j)='d';break;
		case 14:*(a+j)='e';break;
		case 15:*(a+j)='f';break;
		
	
		}	
	}
	
}
