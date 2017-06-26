/* a function to find the Maximum and the Minimum of an array of integers
using minimum number of comparisons.*/
/*name D Teja Vardhan Reddy cs15b014 date 8/8/16*/
#include<stdio.h>
int main(){     					/*main function*/
	int n,i,min,max,a[101];
	scanf("%d",&n);
	for(i=0;i<n;i++){				/*for loop*/
		scanf("%d",&a[i]);
	 }
	 if(n==1)
	 {
	 	printf("%d  %d",a[0],a[0]);
 		return 0;
 	}
	if(a[0]<a[1]){
		max=a[1];
		min=a[0];
	 }
	else{
		max=a[0];
		min=a[1];
	 }
	 i=2;
	while(i<n){				/*while loop*/
		if(i+1==n){
			if(a[i]<min)
				min=a[i];
			else if(a[i]>max)
				max=a[i];
	}
	else{
		if(a[i]<a[i+1]){
			if(min>a[i])
				min=a[i];
			if(max<a[i+1])
				max=a[i+1];
		}
		else
		{
			if(min>a[i+1])
				min=a[i+1];
			if(max<a[i])
				max=a[i];
			}
		}
		i+=2;
	 }
	printf("%d  %d",min,max);			/*printf statement*/
	 return 0;
}
