//HEXADECIMAL converter (integer to hexadecimal)

#include <stdio.h>

int main ()
{
	int n,i;
	scanf("%d",&n);
	char a[8];                    //for storing the hexadecimal output
	for(i=0;i<8;i++,n=n/16)
	{
		switch (n%16)         // to store values in the hexadecimal array   
		{
			case 0:
			a[7-i]='0';
			break;
			
			case 1:
			a[7-i]='1';
			break;
			
			case 2:
			a[7-i]='2';
			break;
			
			case 3:
			a[7-i]='3';
			break;
			
			case 4:
			a[7-i]='4';
			break;
			
			case 5:
			a[7-i]='5';
			break;
			
			case 6:
			a[7-i]='6';
			break;
			
			case 7:
			a[7-i]='7';
			break;
			
			case 8:
			a[7-i]='8';
			break;
			
			case 9:
			a[7-i]='9';
			break;
			
			case 10:
			a[7-i]='a';
			break;
			
			case 11:
			a[7-i]='b';
			break;
			
			case 12:
			a[7-i]='c';
			break;
			
			case 13:
			a[7-i]='d';
			break;
			
			case 14:
			a[7-i]='e';
			break;
			
			case 15:
			a[7-i]='f';
			break;
			
		}
	}
    printf ("0x%s",a);              // to print the hexadecimal array
	return 0;
}
		
