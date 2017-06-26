#include<stdio.h>
#include<string.h>

int main (){

	int frq1[128] = {} ;
	int frq2[128] = {};																// Frequency of alphabets in the strings
	char str1[100];
	char str2[100];
	int i, j, k;
	
	scanf("%s%s", str1, str2);
	j = strlen(str1);
	k = strlen(str2);

	if( j != k ){																	// Checking the length of strings
		printf("0") ;
		return 0;
	}
	 
	for( i = 0; i < j; i++){														// Calculating the frequency of each alphabet in the strings
		frq1[str1[i]]++;
		frq2[str2[i]]++;
	}
	j = 0;
	for( i = 0; i < 127; i++)														// Comparing frequencies of alphabets of both strings
		if( frq1[i] != frq2[i]) j = 2;
	
	if(j == 0) printf("1");
	else printf("0");
	
	return 0;	
}
