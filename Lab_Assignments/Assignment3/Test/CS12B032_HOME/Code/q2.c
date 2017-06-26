#include <stdio.h>
#include <stdlib.h>
#include "q2_sort.h"
#define size 1000005
int main(){
	int t,i,n;
	int arr[size];
	FILE* fp= fopen("CS12B032_HOME/out2.txt","w");
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&arr[i]);
		double bubble_t, select_t, insert_t, quick_t, merge_t;
		bubble_t= useSort(bubble_sort, arr, n);
		select_t= useSort(selection_sort, arr, n); 
		insert_t= useSort(insertion_sort, arr, n);
		quick_t= useSort(quick_sort, arr, n);
		merge_t= useSort(merge_sort, arr, n);
		fprintf(fp, "%d %lf %lf %lf %lf %lf\n",n,select_t,bubble_t,insert_t,quick_t,merge_t);
	}
	fclose(fp);
}