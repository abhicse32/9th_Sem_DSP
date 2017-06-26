/*
  To examine whether the pairs and the orders 
  of {,},(,),[,] are correct in expression
*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    stack *S;
    char round_o = '(';
    char round_c = ')';
    char flower_o = '{';
    char flower_c = '}';
    char box_o = '[';
    char box_c = ']';
    int t;
    scanf("%d",&t);                              //NO. OF TESTS CASES
    char str[1000];
    for(;t > 0;t--)
    {
        S = stack_new();                         //NEW STACK
        int i = 0;
        scanf("%s",str);                         //TAKING INPUT
        int ans = 0;
        while(str[i] != '\0')
        {
            if((str[i] == round_o)||(str[i] == flower_o)||(str[i] == box_o))   //PUSHING ALL OPENING BRACES
            {
                ans++;
                stack_push(S,str[i]);
            }
            else if(((S->top)->head) != NULL)
            {
                if((str[i] == round_c) && (((S->top)->head)->data == round_o)) //POPPING THE MATCHING BRACES
                {
                    ans--;
                    stack_pop(S);
                }
                else if((str[i] == box_c) && (((S->top)->head)->data == box_o))
                {
                    ans--;
                    stack_pop(S);
                }
                else if((str[i] == flower_c) && (((S->top)->head)->data == flower_o))
                {
                    ans--;
                    stack_pop(S);
                }
                else                                                           //BREAKING IF THERE IS NO MATCH
                {
                    ans = -1;
                    break;
                }
            }
            else                                 //IF FIRST BRACKET IS CLOSING, BREAK
            {
                ans = -1;
                break;
            }
            i++;
        }
        if(ans == 0)                             //ALL ARE MATCHED
            printf("%d\n",1);
        else                                     //ALL ARE NOT MATCHED
            printf("%d\n",0);
    }
    return 0;
}
