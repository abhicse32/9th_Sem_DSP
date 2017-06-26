#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.c"
#include "List.c"
int match(char a, char b)
{
   if(a=='{')
   {
      if(b=='}') return 1;
      else return 0;
   }
}
int main()
{
   int t,i;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
      int c=0;
      char str[1000];
      scanf("%s",str);
      stack*ps=stack_new();
      int n,i=0;
      n=strlen(str);
      if(n%2!=0)
      {
         printf("-1\n");
         continue;
      }
      stack_push(ps,str[0]);
      for(i=1;i<n;i++)
      {
         if(str[i]=='{')
         stack_push(ps,str[i]); 
         else if(stack_is_empty(ps)!=1&&match(stack_top(ps),str[i])==1)
         {
            stack_pop(ps);
         }
         else stack_push(ps,str[i]);
      }
      //stack_print(ps);
      int c1=0,m=stack_size(ps);
      for(i=0;i<m;i++)
      {
         char x=stack_pop(ps);
         if(x=='{')
         c1++;
      }
      if(c1==0||c1==m)
      printf("%d\n",m/2);
      else if( c1%2==0)
      printf("%d\n",m/2);
      else if(c1%2!=0)
      printf("%d\n",(c1/2)+2+((m-c1-1)/2));
   }
 }

