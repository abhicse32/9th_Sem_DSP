#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printArr(int* arr, int n){
	int i;
	for(i=0;i<n;i++) printf("%d ",arr[i]);
	printf("\n");
}

int* counting_sort(int *arr, int n, int range){
	int count[range+1],i,j;
	int* output=(int*)malloc(sizeof(int)*n); 
	memset(count,0,sizeof count);
	for(i=0;i<n;i++) count[arr[i]]++;
	for(i=1;i<=range;i++) count[i]+=count[i-1];
	for(i=0;i<n;i++){
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}
	return output;
}

int main(){
	int n,i,k;
	scanf("%d%d",&n,&k);
	int* arr= (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	arr=counting_sort(arr,n,k);
	printArr(arr,n);
}