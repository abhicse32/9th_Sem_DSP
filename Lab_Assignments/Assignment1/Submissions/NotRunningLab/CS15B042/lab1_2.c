#include <stdio.h>

int main(){
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i = 0;i < n;i++){
		scanf("%d",&arr[i]);
	}
	int max,min;
	if(n == 1){
		max = arr[0];
		min = arr[0];
		printf("%d  %d\n",min,max);
		return 0;
	}
	if(arr[0] > arr[1]){
		max = arr[0];
		min = arr[1];
	}
	else{
		max = arr[1];
		min = arr[0];
	}
	i = 2;
	while(i < n - 1){
		if(arr[i] > arr[i + 1]){
			if(arr[i] > max) max = arr[i];
			if(arr[i +1] < min) min = arr[i + 1];
		}
		else{
			if(arr[i] < min) min = arr[i];
			if(arr[i + 1] > max) max = arr[i + 1];
		}
		i += 2;
	}

	if(i != n){
		if(arr[i] < min) min = arr[i];
		if(arr[i] > max) max = arr[i];
	}
	printf("%d  %d\n",min,max);
	return 0;
}	
