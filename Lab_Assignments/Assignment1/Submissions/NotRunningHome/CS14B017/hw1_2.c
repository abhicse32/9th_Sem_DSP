#include<stdio.h>
#include<math.h>
char hexD(long long int m){
//printf("enter");
if(m<9){
;
return m+48;
}
else{
return m+87;
}
}
int main(){
long long int n;
char c[10];
//printf("1");
scanf("%lld",&n);
//printf("2");
c[0]='0';
printf("0");
c[1]='x';
printf("x");
for(int i=2;i<10;i++){
//printf("%d",i);
c[i]=hexD(n/(long long int)pow(16,9-i));
n=n%(long long int)pow(16,9-i);
printf("%c",c[i]);
}
//printf("%c",c[0]);
//printf("%c",c[2]);
//printf("%c",c[1]);
}
