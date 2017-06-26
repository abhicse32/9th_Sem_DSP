#include<stdio.h>
#include<string.h>

int main()
{
 char a[100], b[100];
 scanf("%s",a);
 scanf("%s",b);
 int i, j, x, y;
 x=strlen(a);
 y=strlen(b); 

 for(i=x;i<100;i++)
  a[i]=0;
 for(j=y;j<100;j++)
  b[j]=0;

 if(x!=y) printf("0");
 
 else
 {
  for(i=0;i<x;i++)
  {
   for(j=0;j<y;j++)
    {
     if(a[i]==b[j]) b[j]=0; break;
    }
  }
   for(i=0;i<y;i++)
   {if(b[i]!=0) {printf("0"); break;}
    else {printf("1"); break;}}
 }
}
