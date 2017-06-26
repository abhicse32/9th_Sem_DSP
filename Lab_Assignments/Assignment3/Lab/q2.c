#include <stdio.h>
#include <stdlib.h>
void swap(int*a, int *b){
	int temp=*a;
	*a=*b; *b=temp;
}

void arrayShift(int*arr, int start, int end){
	while(start<=end){
		if(arr[start]<arr[start-1])
			swap(&arr[start],&arr[start-1]);
		else break;
		start++;
	}
}

void rearrange(int*arr1, int m, int *arr2, int n){
	int i;
	for(i=0;i<m;i++){
		if(arr1[i]>arr2[0]){
			swap(&arr1[i],&arr2[0]);
			arrayShift(arr2,1,n-1);
		}
	}
}

void printArr(int*arr, int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main(){
	int m,n,i;
	scanf("%d",&m);
	int*arr1=(int*)malloc(sizeof(int)*m);
	for(i=0;i<m;i++) scanf("%d",&arr1[i]);
	scanf("%d",&n);
	int*arr2=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++) scanf("%d",&arr2[i]);
	rearrange(arr1,m,arr2,n);
	printArr(arr1,m);
	printArr(arr2,n);	
}