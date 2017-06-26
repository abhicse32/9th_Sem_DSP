#include <stdio.h>
#include "stack.h"

int main(){
    int t,i;
    scanf("%d",&t);
    for(i = 0; i < t; i++){
        int n,j;
        scanf("%d",&n);
        int arr[n];
        int iarr[n];
        stack *st = stack_new();
        for(j = 0; j < n; j++){
            scanf("%d",&arr[j]);
        }
        j= 0;
        int ii = -1, tmp;
        while(j < n-1){
            if(arr[j] < arr[j+1]){
                arr[j] = arr[j+1];
                while(!stack_is_empty(st)){
                    tmp = stack_pop(st);
                    if(arr[j+1] <= tmp){
                        stack_push(st,tmp);
                        break;
                    }else{
                        arr[iarr[ii]] = arr[j+1];
                        ii--;
                    }
                }
            }else{
                stack_push(st,arr[j]);
                ii++;
                iarr[ii] = j;
            }
            j++;
        }
        while(!stack_is_empty(st)){
            stack_pop(st);
            arr[iarr[ii]] = -1;
            ii--;
        }
        arr[n-1] = -1;
        for(j = 0; j < n; j++){
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
    return 0;
}
