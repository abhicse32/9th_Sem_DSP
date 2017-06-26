/* Program to find if two given strings are anagrams of each other
 * Note : Program assumes strings given do not contains numbers, spaces or any special characters
 * Author : G.Kavya CS15B048
 * Date : 09.08.2016
*/
#include<stdio.h>
#include<string.h>

const int N = 100;

int main(){
  char s1[N];
  char s2[N];
  int count1[26] = {0};
  int count2[26] = {0};
  int i;
  int ch;

  scanf("%s", s1);
  scanf("%s", s2);

  // 1. Checking if lengths are same, most basic level of checking
  if(strlen(s1) != strlen(s2)){
	printf("0\n");
	return 0;
  }

  // Note : Checking if each character in s1 occurs in s2 is not complete since it does not check number of such occurences and is satisfied at the first occurence
  
  // 2. Counting number of each alphabet in each string and comparing those 2 arrays
  for(i = 0; i < strlen(s1); i++){
	// Can store using index = char - 'a'
	ch = s1[i] - 'a';
	count1[ch]++;
	ch = s2[i] - 'a';
	count2[ch]++;
  }
  // Checking if number of each alphabet is the same in both the strings
  for(i = 0; i < 26; i++){
	if(count1[i] != count2[i]){
	  printf("0\n");
	  return 0;
	}
  }	
  printf("1\n");
  return 0;
}
