//Program written by B.Nikhil Baba on Sept 16th,2016-Lab Assgnment5
//Code written to check whether given Tri-bracket series is valid or not.


#include<stdio.h>
#include"List.c"
#include"List.h"
#include<stdlib.h>
#include<string.h>
//Including all the necessary header files.
//Initialising a function to set preferences for characters.
int Pref(char ch)
{
 if(ch == '(')
 return 1;
 else if(ch == ')')
 return 2;
 else if(ch == '{')
 return 3;
 else if(ch =='}')
 return 4;
 else if(ch == '[')
 return 5;
 else
 return 6;
}

//Writing the checker function.
int Checker(char* s)
{
 	int length,j;
        length = strlen(s);
        int Preference[6] = {};
        for(j = 0;j < length;j++)
        {
         Preference[Pref(s[j])-1]++;
        }
        for(j= 0;j < length;j++)
        {
         	if((Pref(s[j]))%2 == 1 && (Pref(s[j+1]))%2 == 0)                 //If anything if closing just after closing..
                 { 
                  	if(((Pref(s[j])) - (Pref(s[j+1]))) != -1)                //If the closing bracket is diferent..return 0
                         	return 0;
                 }
        }
        for(j = 0;j<6;j = j+2)
        {
         if(Preference[j] != Preference[j+1])                                    //Count of aa paired brackets has to be the same.
         {
          return 0;
         }
        }
        
        return 1;                                                                //Return 1 if none of the contradicts.
}

//Main function
int main()
{
 int t,i;
 scanf("%d",&t);
 for(i = 0;i < t;i++)
 {
  	char s[1000];
        scanf("%s",s);
        Checker(s);
        printf("%d\n",Checker(s));
 }
 return 0;
}


 
  
               	
