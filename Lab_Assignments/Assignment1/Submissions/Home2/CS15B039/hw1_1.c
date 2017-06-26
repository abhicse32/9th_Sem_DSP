/* Max, Next max of a group of integers
__author__='Vishal'
Date=13/08/16*/

#include<stdio.h>

int main(){
	int n, i;
	int max, next_max;
	scanf("%d", &n);
	int A[n];
	scanf("%d", &A[0]);
	max=next_max=A[0];
	for (i=1; i<n; i++){
		scanf("%d", &A[i]);
		if (A[i]>=max){
			next_max=max;
			max=A[i];
			}	
		else if (A[i]>=next_max && A[i]<max)
			next_max=A[i];
	}
	printf("%d %d\n", max, next_max);
	return 0;
}
