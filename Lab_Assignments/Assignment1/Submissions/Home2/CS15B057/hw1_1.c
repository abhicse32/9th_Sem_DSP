/* Author: G.Kavitha
Roll Number: CS15B057
Date: 11-08-16 */
#include <stdio.h>
# define SIZE 100005
int main(){
	int n;//Size of array
	scanf("%d",&n);//Read in size of array
	int i;
	int a[SIZE];//Array holding the n integers
	int maxi=a[0];//maxi is the variable which holds maximum value 
	int next_maxi=a[0];//next_maxi is the variable which holds next maximum value
	for(i=0;i<n;i++){
		scanf("%d",a+i);//Reads in the array elements
	}
	for(i=0;i<n;i++){
		if(a[i]>maxi){//Update both maxi and next_maxi
			next_maxi=maxi;
			maxi=a[i];
		}
		else if(a[i]>next_maxi){//Update only next maxi
			next_maxi=a[i];
		}
	}
	printf("%d %d\n",maxi,next_maxi);//Display the results
	return 0;
}