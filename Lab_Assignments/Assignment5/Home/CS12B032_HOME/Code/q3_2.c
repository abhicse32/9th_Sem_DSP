#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_3.h"
#define size 1024
char *ops[]={"+","-","*","/","%","&","^","|"};

bool check_if_op(char* op){
  int i;
  for(i=0;i<sizeof(ops)/sizeof(char*);i++)
    if(!strcmp(ops[i],op))
      return true;
  return false;
}

char* perform_operation(int operand1, int operand2, char* op){
  int res=0;
  switch (op[0]) {
    case '+': res= operand1 + operand2; break;
    case '-': res= operand1 - operand2; break;
    case '*': res= operand1 * operand2; break;
    case '/': res= operand1 / operand2; break;
    case '%': res= operand1 % operand2; break;
    case '&': res= operand1 & operand2; break;
    case '|': res= operand1 | operand2; break;
    case '^': res= operand1 ^ operand2; break;
    default: break;
  }
  char* res_str;
  asprintf(&res_str,"%i",res);
  return res_str;
}

int evaluate_postfix(char* buff){
  stack* st= stack_new();
  char* temp= strtok(buff," ");
  int operand1, operand2;
  while(temp!=NULL){
    operand1=operand2=0;
    if(check_if_op(temp)){
      if(!stack_is_empty(st))
        operand1= atoi(stack_pop(st));
      if(!stack_is_empty(st))
        operand2= atoi(stack_pop(st));
      stack_push(st,perform_operation(operand2,operand1,temp));
    }else{
      stack_push(st,strdup(temp));
    }
    temp=strtok(NULL," ");
  }
  return atoi(stack_pop(st));
}

int main(){
  char buff[size];
  while(fgets(buff,size-1,stdin)!=NULL){
    buff[strlen(buff)-1]='\0';
    printf("%d\n",evaluate_postfix(buff));
  }
}
