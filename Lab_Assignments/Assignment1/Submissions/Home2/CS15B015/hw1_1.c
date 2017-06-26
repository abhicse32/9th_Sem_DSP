/*	Program to find the first two largest integers of an array
		G.Pranav	CS15B015	10-8-2016*/
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	int max,nextmax;
	for(i=0;i<n;i++){		//inputting the elements of the array
		scanf("%d",&a[i]);
	}
	if(a[0]<a[1]){		//Initializing max and nextmax
		max=a[1];
		nextmax=a[0];
	}
	else{
		max=a[0];
		nextmax=a[1];
	}
	for(i=2;i<n;i++){
		if(a[i]>=nextmax){
			if(a[i]>=max){
				nextmax=max;
				max=a[i];
			}
			else{
				nextmax=a[i];
			}
		}
	}
	printf("%d %d\n",max,nextmax);	//printing the maximum and the next maximum elements of the array
	return 0;
}
