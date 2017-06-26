/*A program to fcheck if the two strings of lowercase letters are anagrams. 
  Author:CS15B046 Jahnvi Patel
  Date:August 10, 2016 */

#include <stdio.h>
  /* The function has two strings as parameters and compares the occurence of each lower case letter in both the strings
     Returns 1 if they are anagrams otherwise 0.  */
int check(char s1[],char s2[])
{	
	int len1,len2;
	int count[26];
	int i;
	for(i=0;i<26;i++)
		count[i]=0;


	for(len1=0;s1[len1]!='\0';len1++);
	for(len2=0;s2[len2]!='\0';len2++);
	if(len1!=len2)
		return 0;
	else
	{
       for(i=0;i<len1;i++)
       	count[(int)s1[i]-97]++;
       for(i=0;i<len2;i++)
       	count[(int)s2[i]-97]--; 
       /*Checks if overall count now is 0 or not*/
       for(i=0;i<26;i++)
       	if(count[i]!=0)
       	  return 0;
       	return 1;


	}

}

void main()
{   /*two input srings*/
	char s1[100];
	char s2[100];
	scanf("%s",s1);
	scanf("%s",s2);
	printf("%d",check(s1,s2));
}