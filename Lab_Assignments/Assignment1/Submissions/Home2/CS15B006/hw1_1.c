#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i, j;
	int max, max2;
	int n;

	scanf("%d", &n);
	int k = 2*n - 1;
	int* a = malloc( sizeof(int)*(k));												// Allocating space for required array to store data

	for( i = n - 1; i <= k - 1; i++)scanf("%d", &a[i]); 							// Reading the data
	j = n - 2;
	for( i = 2*n-2 ; i > 0; i-= 2 )													// Arranging the data in the convenient data structure according to their respective size and position 
	{
		if(a[i] > a[i-1]) a[j] = a[i];
		else a[j] = a[i-1];
		j--;
	}
	
	int* b = malloc(sizeof(int)*(n-2));												// Allocating space for required array to store data of possible next maximum integers
	
	max = a[0];
	
	j = 0;
		
	for( i = 1 ; i + 1 <= 2*n - 2; j++){											// Checking for possible next maximum numbers
		
		if(a[i] == max) b[j] = a[i+1];
		else { b[j] = a[i] ;
			i = i+1;
			}
		i = 2*i + 1;
		
	} 
	
	max2 = b[0];
	
	for( i = 0; i < j  ; i++){													// Finding the highest next max among possible numbers
		if(b[i] > max2) max2 = b[i];
		}	 
	
	printf("%d %d", max, max2);
	
	return 0;
}
