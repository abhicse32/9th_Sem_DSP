  

#include <stdio.h>
int anagram(char a[],char b[]);
void main()
{char a[100];char b[100];
int ch;
printf("enter the string");
scanf("%s",a);
printf("enter the string");
scanf("%s",b);
ch=anagram(a,b);

printf("%d",ch);

}

int anagram(char a[],char b[])
{
int p[26],q[26];int f,g;
for(f=0;a[f]!='\0';f++)
{
 p[a[f]-'a']++;
 
}
for(f=0;b[f]!='\0';f++)

 {q[b[f]-'a']++;
 }

for(g=0;g<26;g++)
{if(p[g] != q[g])
return 0;
}
return 1;
}



