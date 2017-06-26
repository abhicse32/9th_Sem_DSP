#include<stdio.h>
#include<string.h>
int main(){
	char a[100],b[100],c;
	scanf("%s",a);
	scanf("%s",b);
	/*if(a[0]>a[1]){
	printf("1");
	}
	else{
	printf("0");
	}
	printf("%s %d\n",a,strlen(a));
	printf("%s %d\n",b,strlen(b));*/
	for(int i=0;i<strlen(a);i++){
		for(int j=0;j<strlen(a)-1;j++){
			if(a[j]>a[j+1]){
				c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
	}
	for(int i=0;i<strlen(b);i++){
		for(int j=0;j<strlen(b)-1;j++){
			if(b[j]>b[j+1]){
				c=b[j];
				b[j]=b[j+1];
				b[j+1]=c;
			}
		}
	}
	if(strcmp(a,b)==0){
		printf("1");
	}
	else{
		printf("0");
	}
//	printf("%s %s",a,b);
	return 0;
}
