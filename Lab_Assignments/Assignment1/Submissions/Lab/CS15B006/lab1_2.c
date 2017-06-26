#include<stdio.h>

int main() {

    int n;
    int arr[100], arr2[51];
    int i , j, k;
    int Max, Min;    
    j = 0; k = 0;
    scanf("%d", &n);
    
    for(i = 0 ; i < n; i++)scanf("%d", &arr[i]);
    
    if(n == 1) {printf("%d %d\n", arr[0], arr[0]); return 0;}
    
    for( i = 0; i < n; i+=2){
        if(i < n-1 ){
        
            if( arr[i] > arr[i+1] ) {
                arr[j] = arr[i]; j++;
                arr2[k] = arr[i+1]; k++;
                }
            else{
                arr[j] = arr[i+1]; j++;
                arr2[k] = arr[i]; k++;
                }
        }
        else {
            if  ( arr[i] > arr[i-1]) {arr[j] = arr[i]; j++;}
            else { arr2[k] = arr[i]; k++;}
        }
    }
    
    Max = arr[0] ; 
    Min = arr2[0] ;
    
    for( i = 0; i < j; i++){
        if(arr[i] > Max) Max = arr[i];
    }
    
    for( i = 0; i < k; i++){
        if(arr2[i] < Min) Min = arr2[i];
    }
    printf("%d %d\n", Min, Max);

    return 0;
}

