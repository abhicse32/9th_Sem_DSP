#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main(void) {
    int a1[256];
    int a2[256];
    
    char s1[101];
    char s2[101];
    scanf("%s %s",s1,s2);
	if(strlen(s1)!=strlen(s2)){
	   printf("0");
	   return ;}
	int i,j;
	
	
	for(i=0;i<256;i++){
	    a2[i]=0;
	    a1[i]=0;
	}
	for(i=0;i<=strlen(s2);i++){
	   
	    a1[s1[i]]++;
	    a2[s2[i]]++;
	}
	 j=1;
	for(i=0;i<256;i++){
	    if(a1[i]!=a2[i]) j=0;
	}
	if(j==1)printf("1");
	if(j==0)printf("0");
	return 0;
}

