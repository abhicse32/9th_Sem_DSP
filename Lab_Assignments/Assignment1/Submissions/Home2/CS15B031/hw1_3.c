#include<stdio.h>
int prime(int a){
	int i, test = 1;
	for(i = 2; i < a; i++){
		if(a % i == 0) test = 0;
	}
	return test;
}	
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int i;
	for(i = 2; i <= a; i++){
		if(a % i == 0 && b % i == 0){
			if(prime(i) == 1) printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
