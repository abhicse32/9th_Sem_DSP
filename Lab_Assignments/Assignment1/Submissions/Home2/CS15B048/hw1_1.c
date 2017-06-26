#include<stdio.h>

/*
int maxumum(int num1, int num2){
  if(num1 > num2)
	return num1;
  else return num2;
}
*/

const int N = 10000;

int main(){
  int n; // Number of elements 
  int i, j; // Loop indices
  int array[N];
  int max, nextmax;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++){
	scanf("%d", &array[i]);
  }
  max = array[0];
  nextmax = array[1];

  // In case nextmax stores value of max, loop index i = 1 takes care of that
  // Otherwise we need to store max as maximum(array[0],array[1])
  for(i = 1; i < n; i++){
	if(array[i] > max){
	  nextmax = max;
	  max= array[i];
	}
	else if(array[i] > nextmax)
	  nextmax = array[i];
  }

  printf("%d %d\n", max, nextmax);
}
