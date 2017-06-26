#include<stdio.h>
int main() {
    int b;
    scanf("%d",&b);
    int i;
    int temp=0;
    char a[8]={0,0,0,0,0,0,0,0};
    for(i=0;i<8;i++){
        temp=b%16;
        switch(temp){
            case 0: a[i]='0';break;
            case 1: a[i]='1';break;
            case 2: a[i]='2';break;
            case 3: a[i]='3';break;
            case 4: a[i]='4';break;
            case 5: a[i]='5';break;
            case 6: a[i]='6';break;
            case 7: a[i]='7';break;
            case 8: a[i]='8';break;
            case 9: a[i]='9';break;
            case 10: a[i]='a';break;
            case 11: a[i]='b';break;
            case 12: a[i]='c';break;
            case 13: a[i]='d';break;
            case 14: a[i]='e';break;
            case 15: a[i]='f';break;
        } 
        b=b/16;
    }
    printf("0x");
    for(i=0;i<8;i++){
        printf("%c",a[7-i]);
    }
    return 0;
}
