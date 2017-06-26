#include<stdio.h>
#include<stdlib.h>

int main(){

 int n,q;
int i,j,r;
char hexadec[11];

scanf("%d",&n);
q=n;

for(i=9;i>=2;i--){
    r=q%16;
    if(r<10){
        r=r+48;
    }
    else{
        r=r+87;
    }
    hexadec[i]=r;
    q=q/16;
}
hexadec[0]='0';
hexadec[1]='x';
for(j=0;j<=9;j++){
    printf("%c",hexadec[j]);
}
return 0;
}
