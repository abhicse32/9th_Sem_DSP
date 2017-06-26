#include<stdio.h>

int main() {

	int N;
	int i;
	int numb[8];

	scanf("%d", &N);

	for( i = 0; i < 8; i++){								// Finding each digit of hexa decimals by finding remainders of the
		if(N == 0) numb[i] = 0;								// number when divided by 16.
		else {
		numb[i] = N%16;
		N = ( N - numb[i] )/16;
		}
	}
	printf("0x");
	for( i = 7; i >= 0; i--){
		if(numb[i] > 9) printf("%c", 'a'+numb[i]-10);		// Printing the obtained digits from above
		else  printf("%d", numb[i]);
	}
	
	return 0;
}
