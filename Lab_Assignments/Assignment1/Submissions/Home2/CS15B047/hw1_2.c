#include <stdio.h>

int main(void) 
{
	long int n;
	long int num;
	int i;
	scanf("%ld",&n); // Take number to be converted
	num=n; //create a copy of input
	int digit[8]={}; // Make array which will contain digit/ ASCII value of character
	int num_digits=0; // Will contain number of digits in input number 

        // Converting num to hex 
	while(num!=0)
	{
	        //num_digits used as counter which will finally contain number of digits in i/p no.
		// digit[num_digits] will contain decimal value of digit in hex representation
                
                // Extracting digits
		digit[num_digits] = num % 16 ; 
		num=num/16;
		num_digits++;
	}
	printf("0x");// output format needs 0x which cant be generated  so simply print 
	for(i=7;i>=0;i--)
	{
	        //case 1 : digit[i]<10 print as is
                //case 2 : digit >= 10 manipulate value to ascii value of character
		if(digit[i]>=10)
			printf("%c",'A'+digit[i]-10+32); 
		else
			printf("%d",digit[i]);
	}
	
	return 0;
}

