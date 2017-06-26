#include<stdio.h>
#include<stdlib.h>

int minimum(int,int);
int isprime(int);

int main(void){
int n1,n2,n,i,j,flag;
scanf("%d %d",&n1,&n2);
n=minimum(n1,n2);

for(i=2;i<=n;i++){
    if((n1%i==0)&&(n2%i==0)){
       flag=isprime(i);
       if(flag==0){
        printf("%d ",i);
       }

            }
        }
return 0;
}
int minimum(int x,int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}

int isprime(int x){
    int p=-1;
    int k;
    for( k=2;k<=x/2;k++){
       p=x%k;
       if(p==0)
        return 1;
       }
       return 0;
    }

