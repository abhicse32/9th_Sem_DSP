#include <stdio.h>
int main(int argc, char const *argv[])
{
	char p1[101],p2[101];
	int arr1[26]={0},arr2[26]={0},i,j,l,n=1;
	scanf("%s %s",p1,p2);

	 for(i=0;p1[i]!='\0';i++)
    {
        arr1[p1[i]-'a']++;
    }
    for(j=0;p2[j]!='\0';j++)
    {
        arr2[p2[j]-'a']++;
    }
    
   for(l=0;l<26;l++)
   {
   	if(arr1[l]!=arr2[l]) 
   		n=0;
   }
   printf("%d\n",n);
   return 0;
}


	