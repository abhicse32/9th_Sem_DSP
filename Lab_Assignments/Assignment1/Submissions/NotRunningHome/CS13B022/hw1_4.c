#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char str1[100],str2[100];
printf("enter the first string");
gets(str1);
printf("enter the second string");
gets(str2);
int n1[26],n2[26],i;
for(i = 0;i<26;i++){
	n1[i] = 0;
	n2[i] = 0;
}
for(i = 0;str1[i]!='\0';i++ ){
	n1[str1[i] - 'a']++;
}
for(i = 0;str2[i]!='\0';i++ ){
	n2[str2[i] - 'a']++;
}
int flag = 0;
for(i = 0; i < 26;i++){
	if(n1[i]!= n2[i]){
		flag = 1;
		break;
	}
}

if(flag == 0){
	printf("1");
}else 
printf("0");
}
