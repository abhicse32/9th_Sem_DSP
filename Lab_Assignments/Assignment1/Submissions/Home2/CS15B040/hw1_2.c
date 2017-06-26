#include<stdio.h>
#include<stdlib.h>

int main(void){

long int n,quotient;
int i,j,remainder;
char hexa[11];

scanf("%d",&n);
quotient=n;

for(i=9;i>1;i--){
    remainder=quotient%16;
    if(remainder<10){
        remainder=remainder+48;
    }
    else{
        remainder=remainder+55;
    }
    hexa[i]=remainder;
    quotient=quotient/16;
}
hexa[0]='0';
hexa[1]='x';
for(j=0;j<=9;j++){
    printf("%c",hexa[j]);
}
return 0;
}
