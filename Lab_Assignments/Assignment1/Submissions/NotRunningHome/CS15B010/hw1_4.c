#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    char o[100];
    scanf("%s",s);
    scanf("%s",o);
    int i;
    int j;
    int counter=0;
    int a=strlen(s);
    int b=strlen(o);
    if(a!=b){
        printf("0");
        return 0;
    }
    for(i=0;i<a;i++){
        for(j=0;j<a;j++){
            if(s[i]==o[j]){
                counter++;
                o[j]='1';
            }
        }
    }
    if(counter==a){
        printf("1");
    }else{
        printf("0");
    }
    return 0;
}

