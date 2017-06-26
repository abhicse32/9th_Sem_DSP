#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

int match(char  , char );
int main(){

int t;
scanf("%d",&t);
int i=1;
while(i<=t)
{
  char str[1000];
  scanf("%s",str);
  int n = strlen(str);
  stack* st = stack_new(); 
  stack_push(st , str[0]);
int j=1;
 for(j=1 ; j<n ; j++){
   if(match(stack_top(st) , str[j]) == 1){
    stack_removetop(st);
    }
   else{
     stack_push( st, str[j]);
       }
}
i++;
printf("%d\n", stack_is_empty(st));
}
    
   return 0;
}

int match(char a , char b){
  if(a == '('){
    if(b == ')')
      return 1;
    else
      return 0;
}

else if(a == '{'){
    if(b == '}')
      return 1;
    else
      return 0;
}

else if(a == '['){
    if(b == ']')
      return 1;
    else
      return 0;
}

}

  
