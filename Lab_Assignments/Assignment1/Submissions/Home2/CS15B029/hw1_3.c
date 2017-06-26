#include<stdio.h>
#include<stdlib.h>

int min(int,int);
int prime(int);

int min(int x,int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}

int prime(int x){
    int p=-1;
    int k;
    for( k=2;k<=x/2;k++){
       p=x%k;
       if(p==0)
        return 1;
       }
       if(p==-1)
       return 0;
    }


int main(){
int n1,n2,n,i,j,f;
scanf("%d %d",&n1,&n2);
n=min(n1,n2);

for(i=2;i<=n;i++){
    if((n1%i==0)&&(n2%i==0)){
       f=prime(i);
       if(f==0){
        printf("%d ",i);
       }

            }
        }
return 0;
}



