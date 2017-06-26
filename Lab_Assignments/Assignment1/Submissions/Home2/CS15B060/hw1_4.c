//in this program i am assuming all alphabets are lower case as it is not logical to have upper cases and check anagrams
//even if inputs have upper case ,strlwr() can be used and same program can work 

#include<stdio.h>
 #include<string.h>
 

 void count(char a[],int ct[26])   //function to count no of reccurances of alphabet in a string
 {  int n=strlen(a);int i;
      for(i=0;i<n;i++)
       ct[a[i]-97]=ct[a[i]-97]+1;    //note: 97=ASCII value of'a'
 }


 void main()
 {  char a[100],b[100];           //input strings a and b
     scanf("%s %s",a,b);
     int on=1;
     int off=0;
     int ct1[26],ct2[26];          //26 refers to the 26 alphabets
     int i;
       for(i=0;i<26;i++)             //initialising each counters ct1,ct2 to 0
  {      ct1[i]=0;
          ct2[i]=0;
   }
   
 
       count(a,ct1);                //calling of count function
       count(b,ct2);

   for(i=0;i<26;i++)
       if(ct1[i]<ct2[i])           //checking condition
          break;
  if(i==26)
    printf("%d",on);
      else
        printf("%d",off);
}

 



  
  
  

