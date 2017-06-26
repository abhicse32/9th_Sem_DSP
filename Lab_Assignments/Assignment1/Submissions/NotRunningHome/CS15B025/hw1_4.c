#include<stdio.h>
#include<string.h>
/*
  To check if two strings are anagrams or not
*/
int main()
{
  char string1[100];
  char string2[100];
  scanf("%s",string1);                 //Taking two strings as input
  scanf("%s",string2);
  int l1 = strlen(string1);
  int l2 = strlen(string2);
  if(l1!=l2)                           //Comparing lengths of the strings
    printf("%d",0);
  else
  {
    int i;
    int j;
    char c;
    for(i=0;i<l1;i++)                  //Sorting string1
    {
      for(j=0;j<l1;j++)
      {
        if(string1[j]>string1[j+1])
        {
          c = string1[j];
          string1[j] = string1[j+1];
          string1[j+1] = c;
        }
      }
    }
    for(i=0;i<l2;i++)                  //Sorting string2
    {
      for(j=0;j<l2;j++)
      {
        if(string2[j]>string2[j+1])
        {
          c = string2[j];
          string2[j] = string2[j+1];
          string2[j+1] = c;
        }
      }
    }
    j = 0;
    for(i=0;i<l1;i++)
    {
      if(string1[i]==string2[i])       //Comparing the two strings
        j++;
    }
    if(l1==j)
      printf("%d",1);
    else
      printf("%d",0);
  }    
}
