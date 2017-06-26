#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[100],str2[100];
	int x,y; //x and y lengths of strings
	scanf("%s %s",str1,str2);
	x=strlen(str1);
	y=strlen(str2);
	if(x!=y)
    {
        printf("0");
        return 0;
    }
	int alph1[26]={0},alph2[26]={0}; //each variable stores number of 'a's , 'b's , 'c's ....
	char chr;
	for(chr='a';chr<='z';chr++)
    {
        int p;
	    p = chr - 'a';
	    int i;
	    for(i=0;i<x;i++)
	    {
	        if(str1[i]==chr){alph1[p]++;}
	        if(str2[i]==chr){alph2[p]++;}
	    }
	}
	int t;
	for(t=0 ; t<26 ; t++)
    {
	    if(alph1[t]!=alph2[t])
	    {
	        printf("0");
            return 0;
        }

	}
	printf("1");
	return 1;
}
