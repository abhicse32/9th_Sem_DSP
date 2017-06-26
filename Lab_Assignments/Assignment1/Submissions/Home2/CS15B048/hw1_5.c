/* 
 * Program to find the square root of an integer upto 15 decimal places 
 * Author : G.Kavya CS15B048
 * Date : 10.08.2016
*/

#include<stdio.h>

int findApprox(int number){
  int i = 2;
  while(number > i*i){
	i++;
	//printf("i is %d\n",i);
  }
  //printf("returns %d\n", i);
  return i;
}

void findSquareRoot(int num){
  long double root;
  int i = 0;
  int approx = findApprox(num);
  //printf("approx is now %d\n", approx);

  root = (approx + num/(float)approx)/2.0;
  //printf("root is now %Lf\n", root);

  while(i++ < 7){
	root = (root + (float)num/root)/2.0;
  }
  printf("Root is %.15Lf\n", root);
}

int main(){
  int num;
  scanf("%d", &num);

  findSquareRoot(num);

  return 0;
}
