#include<stdio.h>
#include<limits.h>

  int main(){

         int n,j;
             int max=INT_MIN,min=INT_MAX;

             scanf("%d",&n);
                int p[n];

                 for(j=0;j<n;j++)
                 scanf("%d",&p[j]);
       
                     for(j=0;j<n-1;j+=2){
      
                     if(p[j]<p[j+1]){
                             if(max<p[j+1]){
                                 max=p[j+1];
                            }
                             if(min>p[j]){
                                 min=p[j];
                            }
}
                     else if(p[j]>p[j+1]){
                               if(max<p[j]){
                                   max=p[j];
                                  }
                                 
                               if(min>p[j+1]){
                                   min=p[j+1];
                   }
                  }
             }
         printf("%d %d\n",min,max);
   return 0;
}
 

