/*
Program to print next larger number in sequence for each element in array
Name: Harshavardhan.P.K.
Roll No.: CS15B061
Date: 16 Sept, 2016
*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
void nlarger(int*,int);

/*
Function nlarger: to print next larger number in sequence for each element in array
Input: ar-> input array
	len -> length of string 
Output: prints the solution
ar: stores soln array later
Idea: transverse array reverse and for each element ar[i] pop all elements in stack <= ar[i], if it reaches end of stack put -1 else put the larger element
*/
void nlarger(int* ar, int len){
	stack* s = stack_new(); //create stack s
	
	int i;
	for(i=len-1; i>=0;i--){
		if(stack_is_empty(s)){
			
			stack_push(s,ar[i]);ar[i]=-1; //if stack is empty it is the larget element so far so store -1
			continue;
		}
		int num = stack_pop(s);
		while(!stack_is_empty(s) && num<=ar[i]) 		//pop each element in s and check if it is greater than ar[i] if not for all n<i also these elements are not next larger as we have ar[i]
			num = stack_pop(s);
		if(num<=ar[i]) {stack_push(s,ar[i]);ar[i]=-1;} 		//in this case ar[i] in largest till end of array
		else { stack_push(s,num);stack_push(s,ar[i]);ar[i]=num;}// if we find a larger element store it and push present element
		
	}
	for(i=0;i<len;i++) 						//Now print soln array
		printf("%d ",ar[i]);
	putchar('\n');
	
}


int main(void){
	int t;
	scanf("%d",&t);
	int i;
	for(i=0;i<t;i++){
	int len,*arr;
	scanf("%d",&len);
	int j;
	arr = (int*)malloc(sizeof(int)*len);
	for(j=0;j<len;j++)
		scanf("%d",&arr[j]);
	nlarger(arr,len);
	
	}
}
