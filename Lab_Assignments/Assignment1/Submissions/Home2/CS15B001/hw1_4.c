/*
This program takes as input two string and tells if the
two string are anagrams are not

Ameet S Deshpande
CS15B001
*/



#include<stdio.h>

int main()
{
	int count[26];	//Keeps track of the number of letters and their occurences in each string
	char a[100],b[100];	//Stores the two string
	int i,temp,flag=1;	//Flag contains the answer to the problem
	scanf("%s%s",a,b);	//Prompting user for input
	
	for(i=0;i<26;++i)	//Initialising the array before usage
	{
		count[i]=0;
	}
	
	for(i=0;a[i]!='\0';++i)
	{
		temp=(int)(a[i]);
		temp=temp-97;
		count[temp]++;	//Counting the number od letters in each string
	}
	
	
	for(i=0;b[i]!='\0';++i)
	{
		temp=(int)(b[i]);
		temp=temp-97;
		count[temp]--;	//Counting the number of letters in each string
	}
	
	
	for(i=0;i<26;++i)
	{
		if(count[i]!=0)
		{
			flag=0;
			break;
		}
	}
	
	printf("%d",flag);
	
}