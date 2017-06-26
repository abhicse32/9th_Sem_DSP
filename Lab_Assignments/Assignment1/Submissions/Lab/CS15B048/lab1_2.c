// Program to find the maximum and minimum of an array of integers using minimum comparisons
// Author : G.Kavya CS15B048
// Date : 08.08.2016

#include<stdio.h>
const int N = 100;

void FindMinAndMax(int array[], int size){

  int winners[50]; // Stores max of all n/2 comparisons here
  int losers[50]; // Stores min of all n/2 comparisons here
  int i, k = 0;

  // For odd numbered elements in array, loop accesses an element outside array limits
  // So storing it as its own pair in the next element
  if(size % 2 != 0){
	array[size] = array[size - 1];
  }

  // Code to fill the winner and loser elements from round 1 of tournament analogy into respective arrays
  for(i = 0; i < size; i += 2){
	if(array[i] > array[i + 1]){
	  winners[k] = array[i];
	  losers[k++] = array[i + 1];
	}
	else {
	  winners[k] = array[i + 1];
	  losers[k++] = array[i];
	}
  }
  /* testing
  for(i = 0; i < k; i++){
	printf("%d  ", winners[i]);
  }
  */
  int max = winners[0];
  for(i = 1; i < (size+1)/2; i++){
	if(max < winners[i])
	  max = winners[i];
  }
  printf("Max : %d\n", max);

  int min = losers[0];
  for(i = 1; i < (size+1)/2; i++){
	if(min > losers[i])
	  min = losers[i];
  }
  printf("Min : %d\n", min);
}

int main(){
  int n;
  int i = 0;
  int array[N];
  // Getting input 
  scanf("%d", &n);
  for(; i < n; i++){
	scanf("%d", &array[i]);
  }

  FindMinAndMax(array, n);

  return 0;
}

