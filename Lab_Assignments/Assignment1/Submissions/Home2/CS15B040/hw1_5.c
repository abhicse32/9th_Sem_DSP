#include<stdio.h>
#include<stdlib.h>
#include<float.h>

double squareroot(int);

int main(void){

int n;
scanf("%d",&n);
printf("%.15lf",squareroot(n));
return 0;
}

double squareroot(int a){
    int hold;
    int i=0;
    double guess=1;
    int max=1000;

    for(i=0;i<max;i++){
        hold=guess;
        guess=(guess+a/guess)/2;
        if(hold==guess){
            break;
        }
    }
    return guess;
    }
