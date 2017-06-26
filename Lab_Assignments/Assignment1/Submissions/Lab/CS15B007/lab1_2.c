#include<stdio.h>

int main(){
	
	int i,n;
	int a[100];
	int min,max;
	scanf("%d",&n);
	for(i=0 ; i<n ; i++){
		scanf("%d",&a[i]);	
	}
	if(n%2==0){
		if(a[0]<a[1]){
			min=a[0];
			max=a[1];		
		}
		else{
			min=a[1];
			max=a[0];
		}
		for(i=2 ;i<n ;i=i+2){
			if(a[i]<a[i+1]){
				if(a[i]<min){min=a[i];}		
				if(a[i+1]>max){max=a[i+1];}
			}
			else{
				if(a[i+1]<min){min=a[i+1];}		
				if(a[i]>max){max=a[i];}			
			}
		}	
	}
	else{
		if(a[0]<a[1]){
			min=a[0];
			max=a[1];		
		}
		else{
			min=a[1];
			max=a[0];
		}
		for(i=2 ;i<n-1 ;i=i+2){
			if(a[i]<a[i+1]){
				if(a[i]<min){min=a[i];}		
				if(a[i+1]>max){max=a[i+1];}
			}
			else{
				if(a[i+1]<min){min=a[i+1];}		
				if(a[i]>max){max=a[i];}			
			}
		}
		if(a[n-1]<min){min=a[n-1];}	
		if(a[n-1]>max){max=a[n-1];}			
	}
	printf("%d %d\n",min,max);
	return 0;
}
