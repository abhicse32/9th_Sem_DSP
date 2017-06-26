#include<stdio.h>
#include<string.h>/*using string header file*/
int main()
{
 char s1[101],s2[101];/*two strings for anagram comparison */
 scanf("%s %s",s1,s2);
 int l1,l2;
 l1=strlen(s1);/*finding string lengths*/
 l2=strlen(s2);
	int a[26]={0},b[26]={0},i,j;/*initialising arrays to null */
	for(i=0;i<l1;i++)
	{
	if(s1[i]-'a'==i)/*finding how many times each alphabet is present in string1*/
	a[i]++;
	}
	  for(i=0;i<l2;i++)
	  {
	  if(s2[i]-'a'==i)
	  b[i]++;
	  }
	    if(l1==l2)/*comparing string lengths*/
	    {
	    for(j=0;j<26;j++)
		{
	        if(a[j]!=b[j])/*if equal checking for anagrams */
		  {
	          printf("o\n");
	          break;
		  }
	          else
		  {
	          printf("1\n");/*printing 1 if they are unequal */
	          break;
		  }
	        }
	   }
	   else printf("0\n");/*printing 0 if they are not anagrams */
}
