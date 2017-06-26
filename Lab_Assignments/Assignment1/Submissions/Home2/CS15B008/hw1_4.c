//A program to verify if two strings are anagrams or not.
//Program is written by Nikhil Baba.B CS15B008 on 9th August,2016


#include<stdio.h>
#include<string.h>                                 //Calling the necessary libraries
int main()                                         //Defining the main function
{
 char s1[100],s2[100];                             //Declaring the character arrays of inputs
 int alpha1[26]={0};                               //Declaring arrays for alphabet counters
 int alpha2[26]={0};
 int i=0;                                  
 scanf("%s",s1);                                   //Reading the strings
 scanf("%s",s2);
  
 
 while(s1[i]!='\0')                                //Running the loop till escape character occurs
 {
  alpha1[s1[i]-'a']++;                             //Counting occurences of each alphabet
  i++;
 }
 int j=0;
 while(s2[j]!='\0')                                //Running the loop till escape character occurs
 {  
  alpha2[s2[j]-'a']++;                             //Counting occurences of each alphabet
  j++;
 }
 for(i=0;i<26;i++)                                 //Running loop to verify no. of occurences of each alphabet
 {
  if(alpha1[i]!=alpha2[i])
  {
   printf("0");
   return 0;                                       //Print 0 if not an anagram
  }
 }
 printf("1");                                      //Print 1 if an anagram
 return 0;                                         //Return 0 at the end of the function
} 
