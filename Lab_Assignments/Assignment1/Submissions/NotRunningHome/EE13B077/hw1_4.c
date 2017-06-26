
/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Sun Aug 14 20:48:12 IST 2016

Description:
This program compares to strings and outputs whether they are anagrams or not.

*/



#include <stdio.h>

int if_anagram(char str1[], char str2[])
{

	int chk1[26] = {0}, chk2[26] = {0};
	int i=0;

	while(str1[i]!='\0')
	{
		chk1[str1[i]-'a']++;
		i++;
	}

	i=0;
	while(str2[i]!='\0')
	{
		chk2[str2[i]-'a']++;
		i++;
	}

	for(i=0; i<26; i++)
		if(chk1[i]!=chk2[i])
			return 0;

	return 1;

}



int main()

{
	char str1[100], str2[100];
	
	scanf("%s %s", &str1, &str2);
	printf("%d \n", if_anagram(str1, str2));

	
	return 0;
}

