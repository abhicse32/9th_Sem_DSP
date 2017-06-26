#include <stdio.h>
#include <string.h>
int Anagram(char *firststring,char *secondstring);
int main()
{
	char first[100],second[100];
	printf("enter first string and second string\n");
	scanf("%s",first);
	scanf("%s",second);
	if(Anagram(first,second)==1)
	{
		printf("1");
	}
	else printf("0");	
	
}
//function to check whether passed strings are anagrams or not
//function returns 1 if strings are anagrams otherwise returns 0
int Anagram(char *first,char *second)
{
	int firstcharcount[256]={0},secondcharcount[256]={0};
	int counter;
	if(strlen(first)!=strlen(second))	//two strings of different length cannot be anagrams
	{
		return 0;
	}
	for(counter=0;first[counter]!='\0';counter++)	//counts frequency of characters of first string
	{
		firstcharcount[first[counter]]++;
	}
	for(counter=0;second[counter]!='\0';counter++)	//counts frequency of characters of second string
	{
		secondcharcount[second[counter]]++;
	}
	for(counter=0;counter<256;counter++)
	{
		if(firstcharcount[counter]!=secondcharcount[counter])
		return 0;
	}
	return 1;	
}
	

	
	
