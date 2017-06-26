#include<stdio.h>
#include<math.h>

int min(int a, int b){
  if(a < b)
	return a;
  else return b;
}

int prime(int number){
  // If number is even and not 2, automatically return not prime
  if((number > 2) && (number % 2 == 0))
	return 0;

  int flag = 1;
  int i = 3;

  for(; i <= sqrt(number); i+=2){
	if(number % i == 0){
	  flag = 0;
	  break;
	}
  }
  return flag;
}

int main(){
  int num1, num2;
  int i = 2;
  scanf("%d %d", &num1, &num2);

  for(; i <= min(num1, num2); i++){
	if((num1 % i == 0) && (num2 % i == 0) && (prime(i))){
	  printf("%d ", i);
	}
  }
  printf("\n");
  return 0;
}
