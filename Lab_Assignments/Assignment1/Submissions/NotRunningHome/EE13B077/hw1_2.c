
/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Sun Aug 14 20:25:54 IST 2016

Description:
This program takes a decimal integer as an input and outputs the its hexadecimal value.

*/



#include <stdio.h>


int main()

{

	int n; 

	printf("Number? \n");
	scanf("%d", &n);
	printf("0x%08x\n", n);

	return 0;
}

