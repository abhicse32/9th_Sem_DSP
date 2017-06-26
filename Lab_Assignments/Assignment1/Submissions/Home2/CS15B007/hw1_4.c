#include<stdio.h>
#include<string.h>

int main(){
	
	int count=0;
	int i,n;
	int check1[26]={0},check2[26]={0};
	char str1[100],str2[100];
	scanf("%s%s",str1,str2);
	n=strlen(str1);
	if(n==strlen(str2)){
		for(i=0 ; i<n ; i++){
			check1[str1[i]-'a']++;				//creating individual arrays of both strings with count of each letter
			check2[str2[i]-'a']++;
		}
		for(i=0 ; i<26 ;i++){								//comparing the arrays to check for anagrams
			if(check1[i]==check2[i]){count++;}
			else break;
		}
		if(count==26){printf("1\n");}
		else {printf("0\n");}
	}
	else {printf("0\n");}
	return 0;
}
