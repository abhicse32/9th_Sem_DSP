#include<stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	double start = 0, end = n, mid = n/2, lastmid = 0;
	double diff = n/2;
	int i;
	for(i = 0; i*i <= n; i++){
		if(i*i == n){
			printf("%d\n", i);
			return 0;
		}
	}
	while(diff >= 0.0000000000000001){
		if(mid * mid >= n){
			end = mid;
			lastmid = mid;
			mid = (start + end)/2;
			diff = lastmid - mid;
		}
		else{
			start = mid;
			lastmid = mid;
			mid = (start + end)/2;
			diff = mid - lastmid;
		}
	}
	printf("%.15f\n", mid);
	return 0;
}
