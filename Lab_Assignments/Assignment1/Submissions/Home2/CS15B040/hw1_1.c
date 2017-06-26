#include<stdio.h>
#include<stdlib.h>

int main(void){

int n,i,j;
int MAX,NEXTMAX;

scanf("%d",&n);

int array[n];

for(i=0;i<n;i++){
        scanf("%d",&array[i]);
}
if(array[0]>array[1]){
        MAX=array[0];
        NEXTMAX=array[1];
}
else{
        MAX=array[1];
        NEXTMAX=array[0];
}
for(j=2;j<n;j++){
    if(MAX<array[j]){
        NEXTMAX=MAX;
        MAX=array[j];
        }
    else if(NEXTMAX<array[j]){
        NEXTMAX=array[j];
    }
}
printf("%d %d",MAX,NEXTMAX);
return 0;
}
