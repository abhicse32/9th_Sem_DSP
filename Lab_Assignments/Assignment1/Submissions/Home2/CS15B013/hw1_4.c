//CS15B013 ANAGRAM

#include <stdio.h>
#include <string.h>

int main()
{
 char str1[100];
 char str2[100];

 int array1[26],array2[26],i,i1,ref,stop,out;

 scanf("%s",str1);
 scanf("%s",str2);


 int b=strlen(str1);
 int a=strlen(str2);

  out=1;

   if(a==b)
     {
      for(i=0,ref=0;i<a;i++)
         {
           for(i1=0,stop=0;i1<a && stop==0;i1++)
              {
               if(str1[i]==str2[i1])
                  {str2[i1]='1';stop=1;}
              }
           if(stop==0)
              {ref==1;out=0;}
         }

     } 
   else
     out=0;

printf("%d\n",out);

return 0;
}
