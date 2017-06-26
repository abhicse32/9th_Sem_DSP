#include<stdio.h>
#include"stack.h"
int main(){
        int t;
        scanf("%d",&t);
        while(t--){
                int i;
                int n;
                scanf("%d",&n);
                int a[n];
                for(i=0;i<n;i++) scanf("%d",&a[i]);
                stack* S=stack_new();
                stack* I=stack_new();
                stack_push(S,a[0]);
                stack_push(I,0);
                int j;
                int k;
                int res[n];
                for(i=1;i<n;){
                        if(stack_is_empty(I)&&i<n){
                                stack_push(S,a[i]);
                                stack_push(I,i);
                                //stack_print(S);
                                i++;
                                
                        }                        
                        while(!stack_is_empty(S)&&!stack_is_empty(I)){
                                j=stack_pop(S);
                                k=stack_pop(I);
                                if(a[i]>j){ 
                                        res[k]=a[i];
                                        //printf("%d\n",res[k]);
                                        continue;        
                                }
                                
                                else{   
                                        stack_push(S,j);
                                        stack_push(I,k);
                                        stack_push(S,a[i]);
                                        stack_push(I,i);
                                        i++;
                                        break;        
                        }
                        
                
                
                }
  
                }
                if(i==n&&!stack_is_empty(I)){
                        while(!stack_is_empty(I))
                        res[stack_pop(I)]=-1;
                }
                res[n-1]=-1;
                for(i=0;i<n;i++) printf("%d ",res[i]);
                
                printf("\n");
        }
                       
        return 0;
               
}
