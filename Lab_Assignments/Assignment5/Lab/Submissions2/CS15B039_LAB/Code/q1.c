#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include<string.h>
#include<ctype.h>
#include"List.h"
#define size 1000
int evaluate(char *);
int convert(char);
int main(){
    
    int T;
    scanf("%d", &T);
    
    char *str = (char *)malloc(sizeof(size +1));
    int i;
    char c;
    int flag[T];
    
    for(i=0;i<T;i++){
        scanf("%s", str);
        flag[i] = evaluate(str);
        }

    for(i=0;i<T;i++)
        printf("%d\n", flag[i]);
    return 0;
}

int evaluate(char *str){
    
    char c;
    int i, j, k, flag, len;
    flag = 1;
    len = strlen(str);
   
    stack * st = stack_new();
    for(i=0;i<len;i++){
            c = str[i];
            k = convert(c);

            if(stack_is_empty(st) || k%2==1)
                stack_push(st, k);
                
            else{
                j = stack_pop(st);
                if((k-j)!=1){
 
                    flag = 0;
                    break;
                    }
                }

    }
    
    if(!stack_is_empty(st)){
        flag = 0;
        }
        
    return(flag);
}

int convert(char c){

    switch(c){
        case '(':
            return 1;
            break;
        case ')':
            return 2;
            break;
        case '{':
            return 3;
            break;
        case '}':
            return 4;
            break;
        case '[':
            return 5;
            break;
        case ']':
            return 6;
            break;
        }   
}
