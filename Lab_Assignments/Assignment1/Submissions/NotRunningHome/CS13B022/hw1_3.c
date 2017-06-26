#include<stdio.h>
#include<stdlib.h>

int main(){
	int n1,n2,count = 0,count2 =0;
	//printf("enter the first number");
	scanf("%d",&n1);
	//printf("enter the second number");
	scanf("%d",&n2);
	int i,j;
	int min = n1<n2?n1:n2;
	
	for(i =2;i <= min;i++){
	
		for( j = 2;j < i;j++){
			if(i % j == 0){
				count++;
			}	
	}
	if(count == 0 && n1%i == 0 && n2 % i == 0 ){
		printf("%d ", i);
		
	}
}
	

}
		

	

