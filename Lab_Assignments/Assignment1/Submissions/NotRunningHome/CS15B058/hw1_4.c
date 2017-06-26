//Program to check whether two lowercase strings are Anagrams
//Author: B Arjun, CS15B058; Date:10/08/16

#include<stdio.h>
int main(void)
{
	char str1[100],str2[100];
	scanf("%s %s",str1,str2);
	int loopvar_1,length1=0,result; //result contains the final value to be printed
	for(loopvar_1=0;str1[loopvar_1]!='\0';loopvar_1++) //To find the length of the string
	length1++;
/*First we check if both the strings are of the same length, only then theres a possibility of being anagrams. We check this by checking if the character at same position as null character of first string is also a null character*/
	if(str2[length1]!='\0')
	{
		result=0;
	}

	else
	{
		int loopvar_2;
		int count1[26],count2[26];
/*We define two integer arrays each of size 26, to store the count of alphabets in each position. for eg. count of a is stored in position 0, and z in 25*/
		int letterpos; // The variable letterpos is to find numerical position of the particular letter in the list of alphabets
		for(loopvar_1=0;loopvar_1<26;loopvar_1++)
		{
			count1[loopvar_1]=0;
			count2[loopvar_1]=0;
		}

		for(loopvar_2=0;loopvar_2<length1;loopvar_2++)
		{
			letterpos=str1[loopvar_2]-'a';//This gives the numerical position of the letter in the alphabet. For eg. 'b'-'a'=1.
			count1[letterpos]++;
			letterpos=str2[loopvar_2]-'a';
			count2[letterpos]++;
		}

		result=1;
		for(loopvar_1=0;loopvar_1<26;loopvar_1++)
		{
			if(count1[loopvar_1]!=count2[loopvar_1])
			{
				result=0;
				break;
			}
		}
	}	
	/*If result=1, it is an anagram.Else it is not an anagram*/
	printf("%d",result);
	return 0;
}
