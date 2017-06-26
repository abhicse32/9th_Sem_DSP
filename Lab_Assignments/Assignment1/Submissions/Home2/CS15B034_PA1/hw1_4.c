//Homework Assignment 1.4 by Raghavan S CS15B034: finding if two user input strings are anagrams of each other or not
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
   char p[101],q[101];                    //input strings
   int flag=1;                            //flag variable to check if anaram or not
   scanf("%s",p);
   scanf("%s",q);                         //scanning the inputs
   int c1[26] = {0};
   int c2[26] = {0};                      //counts of frequency of characters in the 2 strings
   int i=0;                               //counter
   int n;                                 //character index
   while (p[i]!='\0')                     //to go throughout the strings to calculate frequencies
   {
      n=p[i]-'a';
      c1[n]++;
      i++;
   }
   i=0;
   while (q[i]!='\0')
   {
      n=q[i]-'a';
      c2[n]++;
      i++;
   }
   for (i=0; i<26; i++)                   //checking if frequency of each character is same
   {
      if (c1[i]!=c2[i])
          {
            flag=0;
            break;
          }
   }
   if (flag == 1)                         //printing the result
      printf("%d",1);
   else
      printf("%d",0);
   return 0;
}
