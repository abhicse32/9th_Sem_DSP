/* Author: G.Kavitha
Roll Number: CS15B057
Date: 11-08-16 */
#include <stdio.h>
int main(){
	char s1[102],s2[102];
	scanf("%s",s1);//Read in string 1
	scanf("%s",s2);//Read in string 2
	int n1,n2;//Holds length of strings
	for(n1=0;s1[n1]!='\0';n1++);//Computes n1
	for(n2=0;s2[n2]!='\0';n2++);//Computes n2
	
	//If lengths are not equal then they are not anagrams
	if(n1!=n2){
		printf("0\n");
		return 0;
	}

	int i;
	
	//a[i] holds the count of the number of times the alphabet appears in string1
	//b[i] holds the count of the number of times the alphabet appears in string2
	int a[27],b[27];

	//Setting all to 0 initially
	for(i=0;i<26;i++){
		a[i]=0;
		b[i]=0;
	}

	//Updating a[i]
	for(i=0;i<n1;i++){
		a[s1[i]-'a']++;
	}

	//Updating b[i]
	for(i=0;i<n2;i++){
		b[s2[i]-'a']++;
	}

	int flag=1;
	for(i=0;i<26;i++){
		if(a[i]!=b[i]) {
			flag=0; //Not anagrams
			break;
		}
	}

	//Displays answer
	if(flag==0) printf("0\n");
	else printf("1\n");
	return 0;
}
