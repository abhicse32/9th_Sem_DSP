#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int a[8] = {0}, i;
	for(i =  0; i < 8; i++){
		a[i] = n % 16;
		n = n / 16;
	}
	printf("0x");
	for(i = 7; i >= 0; i--){
		if(a[i] < 10) printf("%d", a[i]);
		if(a[i] == 10) printf("a");
		if(a[i] == 11) printf("b");
		if(a[i] == 12) printf("c");
		if(a[i] == 13) printf("d");
		if(a[i] == 14) printf("e");
		if(a[i] == 15) printf("f");
	}
	printf("\n");
	return 0;
}

