#include<stdio.h>
#include<limits.h>

int max(int arr[], int);

int main(){
	
	int arr[100000],n;
	int i;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	
	int a = max(arr,n);
	printf("%d ",arr[a]);
	
	arr[a] = INT_MIN;
	
	int b = max(arr,n);
	
	printf("%d",arr[b]);
	return 0;
}

int max(int arr[], int n){
	
	int k=0,p;
	
	for(p = 0; p < n-1; p++){
		if(arr[k] < arr[p+1]) k = p + 1;
	}
	
	return k;
}


