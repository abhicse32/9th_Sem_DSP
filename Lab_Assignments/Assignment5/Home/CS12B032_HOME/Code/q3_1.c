#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack_3.h"
#define size 1024

typedef struct precedence{
  char* op;
  int preced;
}precedence;
precedence operators[]={
  {"(",0},{")",0},{"*",1},{"/",1},{"%",1},
  {"+",2},{"-",2},{"&",3},{"^",4},{"|",5}
};

int get_precedence(char* op){
  int i=0, preced=-1,num_ops= sizeof(operators)/sizeof(precedence);
  for(i=0;i<num_ops;i++){
    if(!strcmp(op,operators[i].op)){
      preced= operators[i].preced;
      break;
    }
  }
  return preced;
}

void infix_to_postfix(char* buff){
    char* delimiter=" ";
    char* temp= strtok(buff,delimiter);
    stack * st= stack_new();
    while(temp){
      int preced= get_precedence(temp),comp;
      if(preced==-1)
        printf("%s ",temp);

      else if(preced>0){
        while(!stack_is_empty(st) && strcmp(stack_top(st),"(") &&
              preced >= get_precedence(stack_top(st))){
          printf("%s ",stack_pop(st));
        }
        stack_push(st,strdup(temp));

      }else if(!strcmp(temp,")")){
        while(!stack_is_empty(st) && strcmp(stack_top(st),"("))
          printf("%s ",stack_pop(st));
        stack_pop(st);
        
      }else stack_push(st,strdup(temp));
      temp= strtok(NULL, delimiter);
    }
    while(!stack_is_empty(st))
      printf("%s ",stack_pop(st));
    printf("\n");
}

int main(int argc, char* argv[]){
  char buff[size];
  while(fgets(buff,size-1,stdin)!=NULL){
    buff[strlen(buff)-1]='\0';
    infix_to_postfix(buff);
  }
}
