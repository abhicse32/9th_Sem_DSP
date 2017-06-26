#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *Alphabetsorting(char *string);

int main(void){

int n1,n2;

char string1[100];
char string2[100];

scanf("%s %s",string1,string2);

char*sortedstring1;
char*sortedstring2;

n1=strlen(string1);
n2=strlen(string2);

sortedstring1=Alphabetsorting(string1);
sortedstring2=Alphabetsorting(string2);

if(strcmp(sortedstring1,sortedstring2)==0) {
        printf("1");
}

else{
        printf("0");
}
return 0;
}

char*Alphabetsorting(char*string){
       char ch;
       int no[26]={0},n,c,t,x;

       n=strlen(string);

       for (c=0;c<n;c++){
       ch=string[c]-'a';
       no[ch]++;
       }
       t=0;
       for(ch='a';ch<='z';ch++){

            x=ch-'a';

            for(c=0;c<no[x];c++){
              string[t]=ch;
              t++;
       }
       }
   string[t]='\0';

   return string;

}
