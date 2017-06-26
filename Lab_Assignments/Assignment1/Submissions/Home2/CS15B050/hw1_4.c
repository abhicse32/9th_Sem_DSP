						//COde to find whether two strings are anagrams 
						//Author:M.Prasanna Kumar
						//Date:10/08/1997
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
	return (*(int*)a-*(int*)b);
}
int main()
{
char str1[100];
char str2[100];
int ch1,ch2;
int no[26]={0},c,x;
int n1,n2;
int i;
int t=1;                                         //Flag variable
scanf("%s %s",str1,str2);                        //Input the two strings
n1=strlen(str1);                                 //String length of string 1
n2=strlen(str2);                                 //String length of string 2
int output1[n1];
int output2[n2];
if(n1!=n2) printf("%d\n",0);
else
{
	for(i=0;i<n1;i++)
	{
		ch1=str1[i]-'a';                 
		output1[i]=ch1;                  //Representing each alphabet with its corresponding number
		ch2=str2[i]-'a';
		output2[i]=ch2;			 //Representing each alphabet with its corresponding number
	}
	qsort(output1,n1,sizeof(int),cmpfunc);   //Sorting the array
	qsort(output2,n2,sizeof(int),cmpfunc);   //Sorting the array
	for(i=0;i<n1;i++)
	{
		if(output1[i]!=output2[i]) 
		{
			t=0;                     //If corresponding elements of each array don't match assign t=0
			break;
		}
	}
	if(t==1) printf("%d\n",1);
	if(t==0) printf("%d\n",0);
}
return 0;
}
