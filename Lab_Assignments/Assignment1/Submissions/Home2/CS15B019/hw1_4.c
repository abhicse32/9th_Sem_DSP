//file content - Checking whether two given strings are anagrams or not
//author - Shiva Poojith
//date - 14/08/2016

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[102],s2[102];
	scanf("%s%s",s1,s2);

	int n1 = strlen(s1),n2 = strlen(s2);
	int H1[26] = {0},H2[26] = {0};          // hash-tables for both strings 
	int i ;
	int ok = true;  			            //  C99 standard has inbuilt bool feature 

	if(n1!=n2) 
		printf("0\n");
	else {
		for ( i =0;i<n1;i++) {
			H1[s1[i]-'a']++;
			H2[s2[i]-'a']++;
		}

		for(i = 0;i<26;i++)
			if (H1[i]!=H2[i])
				ok = false;

		if (ok)
			printf("1\n");
		else 
			printf("0\n");
	}
}
