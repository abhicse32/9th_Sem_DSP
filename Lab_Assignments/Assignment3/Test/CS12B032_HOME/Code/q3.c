#include <stdio.h>
#include <stdlib.h>
#include "q2_sort.h"
#define size 100005

typedef struct func_struct{
	void (*func_ptr)(int*,int);
	FILE* fp;
} func_struct;

void take_input(int* arr, int n){
	int i;
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
}

int main(){
	int i,n,j,t;
	int arr1[size],arr2[size],arr3[size];
	func_struct func_arr[5]={
					(func_struct){bubble_sort, fopen("CS12B032_HOME/out3_bubble.txt","w")},
					(func_struct){selection_sort,fopen("CS12B032_HOME/out3_selection.txt","w")},
					(func_struct){insertion_sort, fopen("CS12B032_HOME/out3_insertion.txt","w")},
					(func_struct){quick_sort, fopen("CS12B032_HOME/out3_quick.txt","w")},
					(func_struct){merge_sort, fopen("CS12B032_HOME/out3_merge.txt","w")}};


	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		take_input(arr1,n);
		take_input(arr2,n);
		take_input(arr3,n);
		for(i=0;i<5;i++)
			fprintf(func_arr[i].fp, "%d %lf %lf %lf\n",n,useSort(func_arr[i].func_ptr,arr1,n),
							useSort(func_arr[i].func_ptr,arr2,n),useSort(func_arr[i].func_ptr,arr3,n));
		printf("\n");
	}
	for(i=0;i<5;i++)
		fclose(func_arr[i].fp);
}