//Program to find ANAGRAMS


#include <stdio.h>
#include <string.h>

int main ()
{
	int na,nb,out=0,i,j;
	char a[100];
	char b[100];
	scanf ("%s%s",a,b);                      //scans the input strings
	na=strlen(a);
	nb=strlen(b);
	if (na!=nb)                              //if number of elements different,yhen strings cannot be 
		out=0;
	else
		for(i=0;i<na;i++)                //for moving through string a
	{
		for(j=0;j<na;j++)                //for moving through string b
		{
			if(a[i]==b[j])
			{
				out=1;           //changes the out to 1
				b[j]='0';        //if a character of a matches b,it sets that char of b='0' so that it is not detected again
                break;
			}
			
		}
		if(out==0)
			break;
	}
	printf("%d",out);
	return 0;
}
	
			
			
		
	
