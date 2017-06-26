#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

	int i, j, k;
	char numb[6];
	double x, y, z;
	scanf("%s", numb);

	j = strlen(numb);													// Finding no. of digits in the given number
	k = atoi(numb);														// Converting string into number			
	z = (double)k;														//Type-casting given integer into double		
	
	if( k == 10000){ 													// Checking the exterme case
		printf("100\n");
		return 0;
	}
	
	switch(j){															// Covering cases of 5 Digits, 4 Digits etc, seperately
		case 4 : {														// so as to reduce iterations	
			if(numb[0] >= '4') {										
				for(i = 64; i <= 100; i++){
					if( i*i >= k ) break;								// Here we are finding nearest possible integer 
					}													// square root to the given number.	
				}	
			else if( numb[0] >= 1){										
				for(i = 32; i <= 64; i++){
					if( i*i >= k ) break;
					}
				}
			}
	
		case 3 : {
			for(i = 10; i <= 32; i++){
					if( i*i >= k ) break;
				}
			}
	
		case 2 : {
			for(i = 4; i <= 10; i++){
					if( i*i >= k ) break;
				}
			}
			
		case 1 : {
	
			for(i = 1; i <= 10; i++){
					if( i*i >= k ) break;
				}
			}
		}
		y = (double) i;
	for( i = 1; i <=11 ; i++){
		x = y - ((y*y - z)/2)/y ;									// Finding the square root of the number by newton's method
		y = x;	
	}	

	printf("%.15lf", x);											// Printing it upto 15 decimal accuracy
	return 0;

	}


