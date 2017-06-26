#include<stdio.h>
#include<stdlib.h>

int main(void){

int n;
scanf("%d",&n);
int i,j,m1,m2;

int num[n];

for(i=0;i<n;i++){
        scanf("%d",&num[i]);
}
if(num[1]<num[0]){
        m1=num[0];
        m2=num[1];
}
else{
        m1=num[1];
        m2=num[0];
}
for(j=2;j<n;j++){
    if(m1<num[j]){
        m2=m1;
        m1=num[j];
        }
    else if(m2<num[j]){
        m2=num[j];
    }
}
 printf("%d %d\n",m1,m2);
return 0;
}
