/*
  To find the minimum number of reversals
  required to make a balanced expression
*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    stack *S;
    char opening = '{';
    int t;
    scanf("%d",&t);                              //NO. OF TESTS CASES
    char str[1000];
    for(;t > 0;t--)
    {
        S = stack_new();                         //NEW STACK
        int i = 0;
        scanf("%s",str);                         //TAKING INPUT
        int op = 0;                              //COUNTER FOR NO. OF OPENING BRACES
        int rev = 0;                             //COUNTER FOR NO. OF REVERSALS
        while(str[i] != '\0')
        {
            if(str[i] == opening)                //PUSHING OPENING BRACES AND UPDATE THE COUNTER
            {
                op++;
                stack_push(S,str[i]);
            }
            else if(((S->top)->head) != NULL)    //POPPING IF THERE IS A MATCH
            {
                op--;
                stack_pop(S);
            }
            else                                 //IF FIRST BRACKET IS CLOSING, THEN REVERSE IT AND PUSH 
            {
                rev++;
                op++;                            //UPDATING THE COUNTER
                stack_push(S,opening);
            }
            i++;
        }
        if((op %2) == 0)
        {
            rev += (op/2);
            printf("%d\n",rev);
        }
        else                                     //IF OP IS ODD THEN IT'S IMPOSSIBLE
            printf("%d\n",-1);
    }
    return 0;
}
