#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
int main()
 {
  char s1[100],s2[100];// temperorary allotion of an arry
  int i,j,x;
  x=1;
  scanf("%s %s",s1,s2);
  int len1,len2;
  len1=strlen(s1);// caluclating string length
  len2=strlen(s2);
  assert(((len1)>=1)&&(((len1))<=100));// checking the condition on lengh of the string
  assert(((len2)>=1)&&(((len2))<=100));
 if((len1)!=(len2))
  	{ printf("0\n");
          exit(1);   }
 else
    {
      for(i=0;(i<len1)&&(x==1);i++)// checking each term wether it is there in the other array or not
	{x=0;
	  for(j=0;j<len1;j++)
	   {
	     if(s1[i]==s2[j])
             {
            x=1;
	     }   
	   } 
	}
      
if(x==1)
printf("1\n");// outputing in required format
else
printf("0\n");
																				
    }

return 0;

 }
