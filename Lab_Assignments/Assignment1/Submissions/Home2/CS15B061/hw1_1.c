/*
 * =====================================================================================
 *
 *
 *    Description:  To find max and next max of array/
 *
 *       
 *
 *         Author: Harshavardhan.P.K. 
 *
 * 	  Roll No: CS15B061
 *		Date: 12/8/16
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
 typedef long long int lli;

 
/* 
 * ========================================================================================
 *
 *	Function: main
 *	Input: len - the input number in decimal form.
 *			arr[] - array of len integers
 *	len1 : lenth of heap array = 2*len - 1
 *	arr[]: stores the hexadecimal form of num in form of string.
 *
 *	Output: max: maximum element
 			nman: next maximum element
 *
 *
 * ========================================================================================
 * */
 int main (void){
 	int len,len1,i;
	lli *arr;
	scanf ("%d",&len);
	len1 = 2*len -1;
	
	arr = (lli *)malloc (len1 * sizeof(lli));
	
	// Input of elements in array
	for (i=len1-1; i>len1-1-len; i--){
		scanf("%lld",&arr[i]);		
	}

//Find max by heap generation from successive comparisons
	int index = i;
	for (i=len1-1; i>0; i-=2){
		if(arr[i]>arr[i-1]) arr[index] = arr[i];
		else arr[index] = arr[i-1];
		index--;
	
	}
	printf ("%lld",arr[0]);

	lli nmax, max = arr[0];
	index=0;



	if (arr[(1+index)*2]!= max){
		nmax = arr[(1+index)*2];
		index = (1+index)*2-1;
	}

	else{
		nmax = arr[(1+index)*2-1];
		index = (1+index)*2;
	}

//Tracing back branch of max to compare its opponents to see next max element
	while ((1+index)*2<len1){
	if (arr[(1+index)*2]!= max){
		if (nmax < arr[(1+index)*2])
		nmax = arr[(1+index)*2];
		index = (1+index)*2-1;
	}

	else{
		if (nmax < arr[(1+index)*2-1])
		nmax = arr[(1+index)*2-1];
		index = (1+index)*2;
	}
	
	}

	printf (" %lld\n",nmax);

	return 0;

 }
