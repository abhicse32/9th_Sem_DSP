#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
	printf("enter the value of n: \n");
	int max1 = INT_MIN,max2 = INT_MIN,i,temp,n;
	scanf("%d",&n);
	int* arr = (int*)malloc((n)*sizeof(int));
    
		for(i = 0;i < n;i++){
				scanf("%d",&arr[i]);
			}
		//	max1 = arr[0];
		for(i = 1; i < n;i++){	
			if(arr[i] >= max1){
				temp = max1;
				max1 = arr[i];
				max2 = temp;
			}
			else if(arr[i]> max2 && arr[i] < max1){
				max2 = arr[i];
			
			}
		}
	
		printf("%d\n",max1);
		printf("%d\n",max2);
	}
	
	
