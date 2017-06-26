/*	Program to check whether the given strings are anagrams or not
		G.Pranav CS15B015 10-8-2016*/
#include<stdio.h>
int main(){
	char a[101],b[101];		//char arrays to store the strings
	scanf("%s%s",a,b);
	int c[26],d[26];	//integer arrays to store the frequency of the characters  
	int i;
        int temp;
	for(i=0;i<26;i++){	//initializing the elements of the array to 0
		c[i]=0;
		d[i]=0;
	}
	for(i=0;a[i]!='\0';i++){	//incrementing the frequency of the correspoding character
		temp=a[i]-'a';
		c[temp]++;
	}
	for(i=0;b[i]!='\0';i++){
                temp=b[i]-'a';
		d[temp]++;
	}
	int dum=0;
	for(i=0;i<26;i++){		//comparing the frequencies of all the characters in both the strings 
		if(c[i]!=d[i]){
			dum++;
			break;
		}
	}
	if(dum==0) printf("1\n");
	else printf("0\n");
	return 0;
}