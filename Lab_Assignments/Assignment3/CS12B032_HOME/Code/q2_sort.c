#include "q2_sort.h"
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
void swap(int* a , int* b){
	int temp=*a;
	*a=*b; 
	*b=temp;
}

void printArr(int* arr, int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}


double useSort(void (*fun_ptr)(int*, int), int* arr, int n){
	int* newArr= (int*)memcpy((int*)malloc(sizeof(int)*n),arr,sizeof(int)*n);
	struct timeval t1, t2;
	gettimeofday(&t1,NULL);
	fun_ptr(newArr,n);
	gettimeofday(&t2,NULL);
	printArr(newArr,n);
	return ((double)(t2.tv_sec- t1.tv_sec))*1e6+(double)(t2.tv_usec - t1.tv_usec);
}

void bubble_sort(int* arr, int n){
	int i,j,flag,m;
	for(i=0,m=n;i<n;i++,--m){
		flag=0;
		for(j=1;j<m;j++){
			if(arr[j]<arr[j-1]){
				swap(&arr[j],&arr[j-1]);
				flag=1;
			}
		}
		if(!flag)
			break;
	}
}

void insertion_sort(int* arr, int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		for(j=i-1;j>=0 && arr[j]>temp;j--)
			arr[j+1]=arr[j];
		arr[j+1]=temp;
	}
} 

void selection_sort(int* arr, int n){
	int i,j,k;
	for(i=0;i<n;i++){
		int min=i;
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[min])
				min=j;
		swap(&arr[i],&arr[min]);
	}
}

int partition(int* arr, int l, int r){
	int i,j;
	int temp=arr[l];
	for(i=l+1,j=l+1;i<=r;i++)
		if(arr[i]<temp)
			swap(&arr[i],&arr[j++]);
	swap(&arr[j-1],&arr[l]);
	return (j-1);
}

void quick2(int*arr, int l, int r){
	if(l<r){
		int q= partition(arr,l,r);
		quick2(arr,l,q-1); 
		quick2(arr,q+1,r);
	}
}

void quick_sort(int* arr, int n){
	quick2(arr,0,n-1);
}

void merge(int* arr, int l, int m,int r){
	int lsize= m-l+1;
	int rsize= r-m;
	int* l_arr= (int*)malloc(sizeof(int)*lsize);
	int* r_arr= (int*)malloc(sizeof(int)*rsize);
	int i,j,k;
	for(i=l,j=0;i<=m;i++,j++) l_arr[j]=arr[i];
	for(i=m+1,j=0;i<=r;i++,j++) r_arr[j]=arr[i];
	for(i=0,j=0,k=l;i<lsize && j<rsize;k++)
		if(l_arr[i]<r_arr[j])
			arr[k]=l_arr[i++];
		else arr[k]=r_arr[j++];
	while(i<lsize) arr[k++]=l_arr[i++];
	while(j<rsize) arr[k++]=r_arr[j++];
	free(l_arr);
	free(r_arr);
}

void split(int* arr, int l, int r){
	if(l<r){
		int mid=l+((r-l)>>1);
		split(arr,l,mid);
		split(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void merge_sort(int* arr, int n){
	split(arr,0,n-1);
}
