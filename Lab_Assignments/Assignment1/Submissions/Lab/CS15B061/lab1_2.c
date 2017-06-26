/* Program to find the min and max of an array

Author : Harshavardhan.P.K. (CS15B061)
Date: Aug 8,2016

*/



#include <stdio.h>
#include <stdlib.h>
int max(int *,int len);
int min(int *,int len);





/*
Main function first inputs the array and then divides the array to two arrays (one for finding max and other for min)

*/
int main(void){
	int len_orig,max_elem,min_elem;

/*
arr contains original array
arr_max contains elements which win round1
arr_min contains elements which lose round1
max_elem stores max element and min_elem for min element
len_orig stores length of input array

*/


	int *arr,*arr_max,*arr_min;
	scanf("%d",&len_orig);

	//Allocate memory for input array
	arr=(int *)malloc(len_orig*sizeof(int));
	

	//Allocate memory for min and max array
	if(len_orig%2==0){
		arr_max=(int *)malloc((len_orig/2)*sizeof(int));
		arr_min=(int *)malloc((len_orig/2)*sizeof(int));	
	}
	if(len_orig%2==1){
		arr_max=(int *)malloc((len_orig/2+1)*sizeof(int));
		arr_min=(int *)malloc((len_orig/2+1)*sizeof(int));	
	}

	if(arr==NULL || arr_max==NULL || arr_min==NULL){
		printf ("Problem with Memory allocation \n");        //If allocation doesnt succeed
		exit (1);	
	}


	int i,max_index=0,min_index=0;
	
	for (i=0;i<len_orig; i++)
		scanf("%d",&arr[i]);

	for (i=0; i<len_orig-1; i+=2){
		if(arr[i]>arr[i+1]){
			arr_max[max_index]=arr[i];
			arr_min[min_index]=arr[i+1];
		}
		else{
			arr_max[max_index]=arr[i+1];
			arr_min[min_index]=arr[i];
		}
		max_index++; min_index++;	
	}

	//The last element in odd lenght array has not played in round 1 so it goes to both arrays
	if(len_orig%2==1){
		arr_max[max_index]=arr[len_orig-1];
		arr_min[min_index]=arr[len_orig-1];
		max_elem=max(arr_max,len_orig/2+1);
		min_elem=min(arr_min,len_orig/2+1);
	}

	else{
		
		max_elem=max(arr_max,len_orig/2);
		min_elem=min(arr_min,len_orig/2);
	}

	printf("%d %d\n",min_elem,max_elem);
	
	free(arr);
	free(arr_max);
	free(arr_min);
	return 0;
	
	
	
}


int max(int *ar,int l){
	int i,ans=ar[0];
	for (i=1; i<l; i++)
		if (ans < ar[i])
			ans = ar[i];
	return ans;

}


int min(int *ar,int l){
	int i,ans=ar[0];
	for (i=1; i<l; i++)
		if (ans > ar[i])
			ans = ar[i];
	return ans;

}


