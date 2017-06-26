#include<stdio.h>

int main(){
	
	int	flag = 1;
	int i,j,k,l,p,strlen1,strlen2;
	char str1[100]={0},str2[100]={0};
	
	scanf("%s %s",str1,str2);
		
	for(k = 0; k<100; k++){
		if(str1[k] == '\0') {
			strlen1 = k;
			break;
		}
	}
	
	for(l = 0; l<100; l++){
		if(str2[l] == '\0') {
			strlen2 = l;
			break;
		}
	}
		
	if(strlen1 != strlen2) flag = 0;
	else{
			for(i = 0; i < strlen1; i++){
			for(j = 0; j < strlen2; j++){
				if(str1[i] == str2[j]){
					str1[i] = '\0';
					str2[j] = '\0';
					break;
				}
			}
		}
		
		for(p = 0; p < strlen1; p++) if(str1[p] != '\0') flag = 0; 
	}
			
	printf("%d",flag);
	
}


