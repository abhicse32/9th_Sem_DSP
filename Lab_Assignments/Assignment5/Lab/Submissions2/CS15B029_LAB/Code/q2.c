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
int p=0;
int c1=0, c2=0;
while( stack_is_empty(st)!=1){
 if(stack_pop( st)=='{')
    c1=c1+1;
else
    c2=c2+1;
}
int s=(c1 + c2);
if(s%2!=0)
 printf("-1\n");
else if(c1==0)
 printf("%d\n",c2/2);
else if(c2==0)
 printf("%d\n",c1/2);
else if(c1%2==0)
 printf("%d\n",s/2);
else if(c1%2!=0)
 printf("%d\n",(c1/2)+((c2-1)/2)+2);
}
return 0;
}
 
int match(char a , char b){
  

 if(a == '{'){
    if(b == '}')
      return 1;
    else
      return 0;
}

}
