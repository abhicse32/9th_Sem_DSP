#include <stdio.h>
#include "stack.h"

int main(){
    int t,i;
    scanf("%d",&t);
    getchar();
    for(i = 0; i < t; i++){
        stack *st = stack_new();
        int c;
        while( (c=(int)getchar()) != (int)'\n'){
            if(!stack_is_empty(st)){
                if(c == 40 || c == 91 || c == 123){
                    stack_push(st,c);
                }else{
                    int tmp = stack_pop(st);
                    if(tmp == 40){
                        if(c == 41){
                            continue;
                        }else{
                            stack_push(st,tmp);
                            break;
                        }
                    }else if(tmp == 91){
                        if(c == 93){
                            continue;
                        }else{
                            stack_push(st,tmp);
                            break;
                        }
                    }else if(tmp == 123){
                        if(c == 125){
                            continue;
                        }else{
                            stack_push(st,tmp);
                            break;
                        }
                    }
                }
            }else{
                if(c == 40 || c == 91 || c == 123){
                    stack_push(st,c);
                }else{
                    stack_push(st,c);
                    break;
                }
            }
        }
        while(c != (int)'\n'){
            c = (int)getchar();
        }
        if(stack_is_empty(st)){
            printf("%d\n",1);
        }else{
            printf("%d\n",0);
        }
    }
    return 0;
}
