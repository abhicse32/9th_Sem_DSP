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
                if(c == 123){
                    stack_push(st,c);
                }else{
                    int tmp = stack_pop(st);
                    if(tmp == 123){
                        continue;
                    }else{
                        stack_push(st,tmp);
                        stack_push(st,c);
                    }
                }
            }else{
                stack_push(st,c);
            }
        }
        int rev = 0;
        if(stack_is_empty(st)){
                
        }else{
            int tp = stack_pop(st);
            if(tp == 125){
                rev++;
                while(!stack_is_empty(st)){
                    stack_pop(st);
                    rev++;
                }
                if(rev%2 == 1){
                    stack_push(st,125);
                }else{
                    rev = rev/2;
                }
            } else{
                int op = 0, cl = 0;
                op++;
                while(!stack_is_empty(st)){
                    tp = stack_pop(st);
                    if(tp == 123){
                        op++;
                    }else{
                        cl++;
                    }
                }
                if(cl == 0){
                    if(op%2 == 1){
                        stack_push(st,123);
                    }else{
                        rev += op/2;
                    }
                }else{
                    if(op%2 == 0){
                        rev += op/2;
                    }else{
                        rev += op/2;
                        rev = rev + 2;
                        cl--;
                    }
                    if(cl%2 == 0){
                        rev += cl/2;
                    }else{
                        stack_push(st,125);
                    }
                }
            }
        }
        if(stack_is_empty(st)){
            printf("%d\n",rev);
        }else{
            printf("%d\n",-1);
        }
    }
    return 0;
}
