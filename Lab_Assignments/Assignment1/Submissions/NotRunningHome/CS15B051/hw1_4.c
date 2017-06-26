

#include <stdio.h>


int anagram(char a[], char b[])
{
   int p[26] = {0}, q[26] = {0}, c = 0;
 
   while (a[c] != '\0')
   {
      p[a[c]-'a']++;
      
 
   c = 0;
 
   while (b[c] != '\0')
   {
      q[b[c]-'a']++;
      c++;
   }
 
   for (c = 0; c < 26; c++)
   {
      if (p[c] != q[c]){
         return 0;
	break;
	}
	return 1;	
	      
   } 
 
}
 
int main()
{
   char a[100], b[100];
   int n;
   scanf("%s",a); //Reads a string
      scanf("%s",a); //Reads b string
   n=anagram(a, b);
 
   if (n == 1)
      printf("1");
   else
      printf("0");
   return 0;
}
 
