#include<stdio.h>
int main(){
	int n, a[100001] = {0};
	scanf("%d", &n);
	int i, max, min, index = 0;
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(i == 0){
			max = a[0];
			min = a[0];
		}
		if(a[i] > max){
			max = a[i];
			index = i;
		}
		if(a[i] < min) min = a[i];
	}
	printf("%d ", max);
	a[index] = min;
	max = a[0];
	for(i = 0; i < n; i++){
		if(a[i] > max) max = a[i];
	}
	printf("%d\n", max);
	return 0;
}
	 
