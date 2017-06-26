#include<stdio.h>
#include<math.h>
int prime ( int m );

int main() {
	int i, j, k;
	int a, b;
		
	scanf("%d%d", &a, &b);
	
	if( a < b) {
	k = a;
	a = b;															// Making sure that a is larger than b
	b = k;
	}
	j = b/2;
	
	if( a%2 == 0 && b%2 == 0) printf("2 "); 						// Checking the even-prime(special) case
	for( i = 3; i <= j; i+=2){
		if( a%i == 0 && b%i == 0 && prime(i) == 1){					// Chencking if various numbers are factors of both and prime at the same time
			printf("%d ", i);
		}
	}
	if(a%b == 0 && prime(b) == 1) printf("%d ", b); 
	
	return 0;
}

int prime( int m ){													// Function to find if a given number is prime	
	int i, j;
	
	j = sqrt(m);
	if( m%2 == 0) return 0;
	for( i = 3; i <= j; i += 2 ){									// Checking if any number divides it until its square root			
		if( m%i == 0 ) return 0;
	}
	return 1;
}
