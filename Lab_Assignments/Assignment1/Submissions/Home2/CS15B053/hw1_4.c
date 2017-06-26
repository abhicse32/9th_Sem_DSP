#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checkifanagrams(char *s1, char *s2)
{
	int s1count[26]={0};
	int s2count[26]={0};
	
	int i;
	
	int s1length = strlen(s1);
	int s2length = strlen(s2);
	
	if(s1length != s2length)
	{
		return 0;
	}
	else
	{
		for(i=0; i<s1length; i++)
		{
			s1count[s1[i]-97]++;
		}
		
		for(i=0; i<s2length; i++)
		{
			s2count[s1[i]-97]++;
		}
		
		for(i=0; i<26; i++)
		{
			if(s1count[i]!=s2count[i])
				return 0;
		}
	}
	return 1;			
}


void main()
{
	char s1[100], s2[100];
	int anagram;
		
	scanf("%s %s", s1, s2);
	
	anagram = checkifanagrams(s1, s2);
	printf("%d", anagram);
}
	
