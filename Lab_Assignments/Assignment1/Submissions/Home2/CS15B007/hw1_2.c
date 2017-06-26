#include<stdio.h>

int main(){
	
	long int n;
	int rem,i;
	scanf("%ld",&n);
	char ch[10]={'0','x','0','0','0','0','0','0','0','0'};
	for(i=9 ; n>15 ; i--){											//factorising with 16 and setting remainder in character array from the back
		rem=n%16;
		n=n/16;
		if(rem>9){ch[i]=('a'+(rem-10));}					//using ASCII values to set the remainder to hexadecimal
		else ch[i]=('0'+rem);
	}
	if(n>9){ch[i]=('a'+(n-10));}								
	else ch[i]=('0'+n);
	for(i=0 ; i<10 ; i++){
		printf("%c",ch[i]);
	}
	printf("\n");
	return 0;
}
