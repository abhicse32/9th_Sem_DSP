/*
PROGRAM: Takes as input two strings of characters, and returns 1 if the two are anagrams, and 0 if they are not.
DATE: 14th August 2016
AUTHOR: Giridhar S, CS15B016 */




#include<stdio.h>

//FUNCTION TO FIND THE LENGTH OF A STRING
//INPUT: String, whose length is to be found
//OUTPUT: length of String

int slen(char s[]){
	int count=0;
	while(s[count]!='\0'){
		count++;
	}
	return(count);
}



//MAIN FUNCTION

int main(){

	char string1[100]; char string2[100];  //Variables to hold Input Strings.
	int alphabets[26];                     //Array that will store the number of occurences of each alphabet in string1 and string2.
	int i;
	for(i=0;i<26;i++){
		alphabets[i]=0;
	}

	void readInput(char s1[], char s2[]);	//Function to take user input
	void readAlphabets(char s[], int a[], int choice);	//function to update alphabets array

	readInput(string1,string2);

	if(slen(string1)!=slen(string2)){
		printf("%d",0);
		return 1;
	}                                     //If length is not same, the two strings cannot be anagrams

	else{
		readAlphabets(string1, alphabets, 0);
		readAlphabets(string2, alphabets, 1);
		for(i=0;i<26;i++){
			if(alphabets[i]!=0){
				printf("\n%d",0);
				return 1;
			}
		}
		printf("\n1");
	}

}


//FUNCTION TAKES USER INPUT
//ARGUMENTS: THE TWO STRINGS IN WHICH DATA IS STORED

void readInput(char s1[], char s2[]){
	scanf("%s",s1);
	scanf("%s",s2);
}


//FUNCTION TO UPDATE THE VALUE OF ALPHABETS ARRAY
//WORKING: In string1, for every occurence of an alphabet in string1, the corresponding variable in alphabets array is increased by one. in String2, it is decreased by one.
//So for anagrams, at the end of program, alphabets array should have only zeros.
//ARGUMENT: i) s[]-string to be counted, ii) a[]-alphabets array, iii) choice-0 for string 1, else 1.

void readAlphabets(char s[], int a[], int choice){
	int addend,size;
	if(choice)
		addend=-1;
	else
		addend=1;

	int i,ascii;
	int ascii0='a';
	size=slen(s);
	for(i=0;i<size;i++){
		ascii=s[i];
		a[ascii-ascii0]+=addend;
	}
}

