#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printPermutation(int* arr, char *str, int n){
	if(!n){
		printf("%s ",str);
		free(str);
		return;
	}
	int i,j,k;
	int len= strlen(str);
	for(i=0;i<n;i++){
		int* temp_arr= (int*)malloc(sizeof(int)*(n-1));
		for(j=0;j<n;j++){
			if(j<i)
				temp_arr[j]=arr[j];
			else if(j>i)
				temp_arr[j-1]=arr[j];
		}
		char* buff;
		asprintf(&buff,"%i",arr[i]);
		char* temp_str=(char*)malloc(len+strlen(buff)+1);
		strcpy(temp_str,str);
		strcat(temp_str,buff);
		//printf("%s\n",temp_str);
		printPermutation(temp_arr,temp_str,n-1);
	}
}

int main(){
	int n,i,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int *arr= (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++) scanf("%d",&arr[i]);
		printPermutation(arr,"",n);
		printf("\n");
	}
}