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
   if(a=='(')
   {
      if(b==')') return 1;
      else return 0;
   }
   if(a=='[')
   {
      if(b==']') return 1;
      else return 0;
   }
}
int main()
{
   int t,i;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
      char str[1000];
      scanf("%s",str);

      stack*ps=stack_new();
      int n,i=0;
      n=strlen(str);
      stack_push(ps,str[0]);
      if(str[0]=='}'||str[0]==']'||str[0]==')')
      {
          printf("0\n");
          return 0;
      }
      for(i=1;i<n;i++)
      {
         if(str[i]=='{'||str[i]=='['||str[i]=='(')
         stack_push(ps,str[i]); 
         else if(match(stack_top(ps),str[i])==1)
         {
            stack_pop(ps);
         }
         else stack_push(ps,str[i]);
      }
      printf("%d\n",stack_is_empty(ps)); 
   }
 }

