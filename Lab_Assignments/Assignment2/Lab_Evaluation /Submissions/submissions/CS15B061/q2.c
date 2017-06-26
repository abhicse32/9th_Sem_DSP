#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* permutenext (int * ,int);
void printperm (int *,int);
void reverse (int*,int,int);

/*-----------------------------------------------------------------------------
 *  Function - permutenext
 *  Use : For given ar array containing permutaion on (0...n-1), it return the next permutation if exists.
 *  Input: ar - array containing previous permutation of (0...n-1)
 *  	   n - number elements in ar.
 *-----------------------------------------------------------------------------*/
int * permutenext (int* ar, int n){
	int i=n-2;
	// Selects first i so ar[i]>ar[i+1]
	while (i>=0 && ar[i]>ar[i+1])
		i--;
	// If it is last Permutation all elements in ar are in descending order. Hence, i = -1
	if (i<0)
		return NULL;
	// Insert previous a[i] so that ar[(i+1)...(n-1)] are in descending order.
	int j=i+1;
	while (j<n && ar[i]< ar[j])
		j++;
	int temp;
	temp=ar[i];
	ar[i]=ar[j-1];
	ar[j-1]=temp;

	//Reverse the subarray[i+1 ... n-1] to yeild the next permutation.
	reverse (ar,i+1,n-1);
	return ar;

}


/*-----------------------------------------------------------------------------
 *  Function - printperm.
 *  Usage : prints all the permutations of arr.
 *  Inputs: arr - the array to be permuted.
 *  	    len - length of arr
 *  ar - stores a array containing elements (0 ... len -1) for permuting its elements  so corresponding
 *  permutation is printed from arr.
 *  Outputs : All permutations of arr.	    
 *-----------------------------------------------------------------------------*/
void printperm (int *arr, int len){
	// Creation of ar.
	int *ar=(int *)malloc(len*sizeof(int));
	int i;
	// For first permutation put all numbers in the right order i.e., ascending order of input in arr.
	for (i=0;i<len;i++)
		ar[i] = i;
	// t is a temporary pointer that copies the result of permutenext and checks if it get NULL
	// if t = NULL the last permutation is printed where all elements are in descending order.
	int *t;
	do{
		// PRint a permutation of array according to arrangement of numbers in ar.
		i=0;
	while(i<len){
		printf("%d",arr[ar[i]]);
		i++;
	}
	printf(" ");
	// Get next permutation in ar.
	t=permutenext(ar,len);
	
	
	}while(t!=NULL);
}


/*-----------------------------------------------------------------------------
 *  Function - reverse - to reverse an array in given range.
 *  Inputs: a - the array to be manipulated
 *  	    start - the start position for reversing
 *  	    end - the last position for reversing
 *  Outputs - It returns nothing. ar is reversed in given range	    
 *-----------------------------------------------------------------------------*/
void reverse(int *a,int start, int end){
	while(start<end){
		int temp = a[start];
		a[start]=a[end];
		a[end]=temp;
		start++; end--;
	}
}


int main(void){
	int len;
	scanf("%d",&len);
	int* arr =(int *) malloc(len*sizeof(int));
	int i;
	for(i=0;i<len;i++)
		scanf("%d",&arr[i]);
	printperm(arr,len);
	printf("\n");
	return 0;

}
