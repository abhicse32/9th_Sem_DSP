										/*program to check anagrams by Akshay Kumar*/

#include<stdio.h>

void main()
{
	char n1[100],n2[100];										/*declaration of variables*/
	scanf("%s %s",n1,n2);
	int m1[26] = {0}, m2[26] = {0}, i = 0,k=0;				    	/*initialization*/
    while(n1[i] != '\0')
    {
       m1[n1[i] - 'a']++;
       i++;
    }
    i = 0;
    while(n2[i] != '\0')
	{
        m2[n2[i] -'a']++;
        i++;
    }
	for(i = 0; i < 26; i++)
    {
       if(m1[i] == m2[i])
           k++ ;
    }
    if(k == 26) printf("1\n");
    else printf("0\n");
  
}



