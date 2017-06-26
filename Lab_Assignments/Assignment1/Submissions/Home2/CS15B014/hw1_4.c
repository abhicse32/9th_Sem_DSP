/*to determine if the strings are anagrams*/
/*name D Teja Vardhan Reddy cs15b014 date 14/8/16*/
#include<stdio.h>
int main(){						/*main function*/
	char ch;int i,a[28]={0},b[28]={0};
	ch=getchar();
	while(ch!=' '){				/*while statement*/
		a[ch-97]++;
		ch=getchar();			/*using getchar */
	}
	 ch=getchar();
	
	 while(ch!='\n'){
	 	b[ch-97]++;
	 	ch=getchar();
	 }
	 for ( i = 0; i < 28; ++i)
	 {
	 	if(a[i]!=b[i]){
	 		printf("0\n");
	 		return 0;
	 	}
	 }
	 printf("1\n");
	 return 0;
}