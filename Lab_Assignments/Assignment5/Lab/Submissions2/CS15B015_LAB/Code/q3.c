/*      Program to find the next greatest element for all the elements of the array
            G.Pranav    CS15B015    16-9-2016   */

#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"
int main(){
    int t;
    int x=1;
    scanf("%d",&t);     //inputting the number of test cases
    while(t--){
        int n;
        scanf("%d",&n);
        int *arr=malloc(n*sizeof(int));
        int i;
        for(i=0;i<n;i++){           //inputting the numbers of the array
            scanf("%d",&arr[i]);
        }    
        int *ans=malloc(n*sizeof(int));
        for(i=0;i<n;i++){           //this array stores the next greatest element of the given element
            ans[i]=-1;                  //initializing the array to -1
        }
        stack *stackptr1=stack_new();   //stack to store the elements of the array
        stack *stackptr2=stack_new();   //stack to store the indices of corresponding elements of the other stack
        stack_push(stackptr1,arr[0]);
        stack_push(stackptr2,0);        //sending the first element of the array into the stack
        for(i=1;i<n;i++){
            x=1;
            if(stack_is_empty(stackptr1)){
                stack_push(stackptr1,arr[i]);
                stack_push(stackptr2,i);
            }
            else{
                int temp=stack_pop(stackptr1);
                if(temp<arr[i]){            //checking whether the first element of the stack is lesser than the array element or not
                    int temp3;
                    do{
                        int temp2=stack_pop(stackptr2);
                        ans[temp2]=arr[i];
                        if(stack_is_empty(stackptr1)){
                            x=0;
                            break;
                         }
                        else temp3=stack_pop(stackptr1);
                    }while(temp3<arr[i]);
                    if(x!=0) stack_push(stackptr1,temp3);
                    stack_push(stackptr1,arr[i]);
                    stack_push(stackptr2,i);
                }
                else{
                    stack_push(stackptr1,temp);
                    stack_push(stackptr1,arr[i]);
                    stack_push(stackptr2,i);
                }
            }
        }
        for(i=0;i<n;i++){           //outputting the ans array
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
