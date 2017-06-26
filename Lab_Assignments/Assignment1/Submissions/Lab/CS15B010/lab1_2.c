/*a program to find the minimum and maximum of a list of n integers using winners and loosers sets to decrease number of comparisions*/

/* author: vinay chilaka cs15b010
   date:8/8/16 for lab assignment 1 question 2 */ 

#include<stdio.h>
int main(){
	int n;
	int i;
	scanf("%d",&n);
	if(n==0){ return 0;}
	int test[n];			//declaring total set
	int half=n/2;
	int win[half+1];		//declaring winners and loosers set
	int loose[half+1];		
	for(i=0;i<n;i++){
		scanf("%d",&test[i]);		//scanning the given set
	}
	for(i=0;i<half;i++){			//comparisions between sets of two and copying them into respective arrays 
		if(test[2*i]>test[2*i+1]){ 
			win[i]=test[2*i];
			loose[i]=test[2*i+1];}
		else{
			loose[i]=test[2*i];
			win[i]=test[2*i+1];}
	}
	loose[half]=test[n-1];		//pushing the last element into both arrays
	win[half]=test[n-1];
	int max=win[0];
	int min=loose[0];
	for(i=0;i<=half;i++){
		if(win[i]>max) max=win[i];		//finding min from winners set
		if(loose[i]<min) min=loose[i];		//finding max from loosers set
	}
	printf("%d %d",min,max);		//printing the maximum and minimum
	return 0;
}
