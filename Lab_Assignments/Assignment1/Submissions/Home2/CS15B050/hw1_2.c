						//COde to represent a number in its hexadecimal form
						//Author:M.Prasanna Kumar
						//Date:10/08/1997
#include<stdio.h>
int main()
{
long int n;                                     
int r;                                          //Remainder
int i=0;
int j;
scanf("%ld",&n);                                //Input number
char arr[10];
arr[9]='0';
arr[8]='x';
while(n!=0)
{
	r=n%16;	
	if(r>9)                                         //
	{                                               //
		switch(r)			        //	
		{					//
			case 10: arr[i]='a';		//
					 break;		//
			case 11: arr[i]='b';		//If remainder is greater than 9 assign the 
					 break;		//corresponding alphabet or else assign the
			case 12: arr[i]='c';		//corresponding number
					 break;		//
			case 13: arr[i]='d';		//
					 break;		//
			case 14: arr[i]='e';		//
					 break;		//
			case 15: arr[i]='f';		//
					 break;		//
		}					//
	}						//
	else arr[i]=r+'0';				//
	n=n/16;                                         //Update the number to n/16
	i++;
}
for(j=i;j<8;j++) arr[j]='0';
for(j=9;j>=0;j--) printf("%c",arr[j]);                  //Printing the hexadecimal form of the number
return 0;
}
