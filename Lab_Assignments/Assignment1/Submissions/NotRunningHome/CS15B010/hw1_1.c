#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max=a[0];
    int nextmax=a[0];
    for(i=0;i<n;i++){
        if(max<a[i]){
            nextmax=max;
            max=a[i];
        }
        else{
            if(nextmax<a[i]){
                nextmax=a[i];
            }
        }
    }
    printf("%d %d",max,nextmax);
    return 0;
}
