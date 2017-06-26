#include <stdio.h>
int main()
{
	int num,quo,rem;	//dividind the decimal number by 16 continuosly and taking the remainders gives hexadecimal no
	int i=9,j,temp;r
	printf("enter any decimal number");
	scanf("%d",&num);
	quo=num;		//initiate the quotient as the number and dividing quo by 16 till quotient not equal to 0
	while(quo!=0){
	temp=quo%16;
	if(temp<10)
	temp=temp+48;else	//ASCII value of 0is 48 and of a is 97(86+11)
	temp=temp+86;
	hexadecimal[i--]=temp;
	quo=quo/16;
	}
	for(j=0;j<10;j++){
	printf("%c",hexadecimal[j]);	//printing the array elements which are the bits of hexadecimal notation
	}
}
	
	
	
	
