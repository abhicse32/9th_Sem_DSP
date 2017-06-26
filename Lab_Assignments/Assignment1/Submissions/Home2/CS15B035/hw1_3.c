#include<stdio.h>
#include<stdlib.h>

int min(int,int);
int pr(int);

int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int pr(int a){
    int p=-1;
    int k;
    for( k=2;k<=a/2;k++){
       p=a%k;
       if(p==0)
        return 1;
       }
       if(p==-1)
       return 0;
    }


int main(){
int a,b,n,i,j,fl;
   scanf("%d %d",&n1,&n2);
   n=min(n1,n2);

    for(i=2;i<=n;i++){
    if((a%i==0)&&(b%i==0)){
       fl=prime(i);
       if(fl==0){
        printf("%d ",i);
       }

            }
        }
return 0;
}



