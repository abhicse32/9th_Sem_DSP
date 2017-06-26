#include<stdio.h>

void find_2maxes(int* ,int);

void main(){
    int size,i;
    scanf("%d",&size);
    int array[size];
    for(i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    find_2maxes(array,size);
}

void find_2maxes(int *array,int size){
    int max1=0,max2=0,i=0;
    for(;i<size;i++){
        if (max1<array[i]){
            max2=max1;
            max1=array[i];
        }
        else if (max2 < array[i])
            max2=array[i];
    }
    printf("%d %d\n",max1,max2);
    return;
}