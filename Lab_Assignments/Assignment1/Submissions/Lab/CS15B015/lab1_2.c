/*Program to find minimum and maximum numbers of an array
	G.Pranav CS15B015 	8th august 2016*/
#include<stdio.h>
#include<limits.h>
int main(){
	int n;
	scanf("%d",&n);
    
        if(n>0){	/*validating the size of the array entered*/		
            int a[n];
            int i;
            for(i=0;i<n;i++){		/*scanning the elements of the array*/
                    scanf("%d",&a[i]);
            }
            int max=INT_MIN,min=INT_MAX;	/*creating two variables to store minimum, maximum numbers and intitializing them*/
            for(i=0;i<n-1;i=i+2){	
		if(a[i]<=a[i+1]){
			if(max<a[i+1]){		/*modifying the variables max and min*/
				max=a[i+1];
			}
			if(min>a[i]){
				min=a[i];
			}
			}	
		else{
			if(max<a[i]){
				max=a[i];
			}
			if(min>a[i+1]){
				min=a[i+1];
			}
			}
		}
            if(n%2!=0){		/*verifying the result with the last number of the array when it has odd number of elements*/
		if(a[n-1]>max) max=a[n-1];
		else if(a[n-1]<min) min=a[n-1];
            }
            if(n==1){		/* solving the special case when the array has one element*/
		min=a[0];
		max=a[0];
            }
            printf("%d %d",min,max);
        }
        return 0;
}















