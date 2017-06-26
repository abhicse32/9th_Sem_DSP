/* 
 * Program to convert a maximum of 9 digit integer to its hexadecimal equivalent
 * Author : G.Kavya CS15B048
 * Date : 09.08.2016
*/

#include<stdio.h>
#include<string.h>

// Converts numbers between 10 and 15 to their letter equivalent and other numbers to their number equivalent
char hexaequivalent(int num){
  if(num < 10)
	return (char)(num + '0');
  else
	switch(num){
	  case 10: return 'a';
	  case 11: return 'b';
	  case 12: return 'c';
	  case 13: return 'd';
	  case 14: return 'e';
	  case 15: return 'f';
	}
}

// Since strrev is not present in glibc's string.h 
void reverse(char str[]){
  char temp;
  int i;
  int len = strlen(str);
  for(i = 0; i < len/2; i++){
	temp = str[i];
	str[i] = str[len - i - 1];
	str[len - i - 1] = temp;
  }
}
void intToHexa(long number){
  char hexa[11];
  // From man page : memset - fill memory with a constant byte
  memset(hexa, '0', sizeof(hexa));
  hexa[10] = '\0';
  int hexaindex = 0;

  while(number > 0){
	int remainder = number % 16;
	number /= 16;
	hexa[hexaindex++] = hexaequivalent(remainder); 
  }

  hexa[8] = 'x';
  hexa[9] = '0';
  reverse(hexa);
  printf("%s\n", hexa);
}

int main(){
  long input;

  scanf("%ld", &input);

  intToHexa(input);

  return 0;
}
