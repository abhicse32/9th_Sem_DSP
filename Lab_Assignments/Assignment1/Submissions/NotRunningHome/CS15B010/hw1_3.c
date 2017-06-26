#include<stdio.h>

int isPrime(int x){
    int i;
    if(x==2){return 1;}
    if(x%2==0){  return 0; }
    else{
        for(i=3;i<x;i=i+2){
            if(x%i==0){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int a;
    int b;
    scanf("%d %d",&a,&b);
    if(a<b){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    int i;
    for(i=2;i<=a;i++){
        if(isPrime(i)){
            if((a%i==0)&&(b%i==0)){
                printf("%d ",i);
            }
        }
    }
    return 0;
}


