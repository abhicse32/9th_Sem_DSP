#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int main(void){
	int n;
	int min,max;

	scanf("%d",&n);

	int array[n];
	max=INT_MIN;
	min=INT_MAX;

	for(int i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	for(int k=0;k<n-1;k+=2){
		if(array[k]>array[k+1]){
			
			if(max<array[k]){
			   max=array[k];
			}
			if(min>array[k+1]){
			   min=array[k+1];
			}
		}
		else if(array[k+1]>array[k]){
			
			if(max<array[k+1]){
			   max=array[k+1];
			}
			if(min>array[k]){
			   min=array[k];
			}
		}
	}
	printf("%d %d\n",min,max);
return 0;
} 

