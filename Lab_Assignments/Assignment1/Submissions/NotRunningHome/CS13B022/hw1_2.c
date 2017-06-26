#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n,i,rem;
	printf("enter the number");
	scanf("%d",&n);
	int n2 = n;
	int count = 0;
	while(n2> 0){
		count++;
		n2 = n2/16;
	}
	int k = 0;
	char* arr = (char*)malloc((count)*sizeof(char));
	while(n > 0){
	
		rem = n % 16;
		n = n/16;
		if(rem <= 9){
			arr[k] = rem+48;
			k++;
		}
		else{
			if(rem == 10){
				arr[k]= 'a' ;
			}
			if(rem == 11){
				arr[k] = 'b';
			}
			if(rem == 12){
				arr[k] = 'c';
			}
			if(rem == 13){
				arr[k] = 'd';
			}
			if(rem == 14){
				arr[k] = 'e';
			}
			if(rem == 15){
				arr[k] = 'f';
			}
			k++;
		}
	}
	
	for(i = count - 1;i >= 0;i--){
		if(arr[i] == 'a' || arr[i] == 'b' || arr[i] == 'c'|| arr[i] == 'd'|| arr[i] == 'e'|| arr[i] == 'f' ){
		printf("%c",arr[i]);}
		else
			printf("%c",arr[i]);
	}
		
	
}
