#include <stdio.h>
#include <string.h>

int main(void) 
{
	char str1[101],str2[101];
	scanf("%s%s",str1,str2); // Scan both strings
	
	int i;
	int l1=strlen(str1),l2=strlen(str2); // l1-->length of str1 l2-->length of str2  
        
        // Initialize every ele of count1 , count2 to 0
	int count1[27]={},count2[27]={};  
	
	//count1[i] --> no. of times ith alphabet (a->1 z->26) occurs in str1 and similar for count2 
	for(i=0;i<l1;i++)
	{
		count1[str1[i]-'a'+1]++; //Manipulate index and increment appropriate alphabet counter
	}
	for(i=0;i<l2;i++)
	{
		count2[str2[i]-'a'+1]++;
	}
	int anagram=1; // anagram=1 --> both anagrams anagram = 0 --> not anagrams
	
	// If all count of all alphabets is same in both strings then anagram else not
	for(i=1;i<=26;i++)
	{
		if(count1[i]!=count2[i])
		{
			anagram=0;
			break;
		}
	}
	
	printf("%d\n",anagram);
	
	return 0;
}

