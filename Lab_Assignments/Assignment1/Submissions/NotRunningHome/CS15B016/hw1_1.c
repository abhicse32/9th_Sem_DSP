/* PROGRAM TO FIND THE MAXIMUM AND SECOND MAXIMUM OF AN ARRAY OF INTEGER ELEMENTS.
DATE: 14TH AUGUST 2016
AUTHOR: GIRIDHAR S, CS15B016 */
#include<stdio.h>

//FUNCTION TO FIND LARGER OF TWO NUMBERS
//INPUT: Two integers
//OUTPUT: Larger of the two
int compare(int x, int y){
	if (x>y) 
		return x;
	else 
		return y;
}


//FUNCTION FINDS THE SECOND MAXIMUM INTEGER ELEMENT OF AN ARRAY GIVEN THE TOURNAMENT DATA STRUCTURE IMPLEMENTATION IN ARRAY FORM
//INPUT: tournament[]-DS for tournament like comparison, size-size of tournament array=no. of matches played
//OUTPUT: Prints the max and second max as per question demand
//WORKING: the tournament DS stores the tournament info in such a manner that the winner of match played between 2i and (2i+1) element in an array numbered 1->N is 
//stored in position i. The second max could have been knocked out only by the first max. So we see all the opponents of max, and find the max amongst them. 
void find_secondmax(int tournament[], int size){
	int max=tournament[0];
	int second_max=max>tournament[1]? tournament[1] : tournament[2];
	int pos=1;
	while (pos<size){
		if(tournament[pos]==max){
			if(second_max<tournament[pos+1])
				second_max=tournament[pos+1];
			
		}
		else{
			if(second_max<tournament[pos])
				second_max=tournament[pos];
			pos++;
		}
		pos=2*pos+1;
	}
	printf("\n%d %d\n",max, second_max);
}



//FUNCTION BUILDS THE ARRAY IMPLEMENTATION OF TOURNAMENT DATA STRUCTURE AND THEN PASSES CONTROL TO find_secondmax
//INPUT: array[]-input array, size-no. of elements in array 
void play_tournament(int array[], int size){
	int SizeTournamentArray=2*size-1;
	int TournamentArray[SizeTournamentArray];
	int i;
	int j=size-1;
	for(i=SizeTournamentArray-1;i>=0;i--){
		if(j>=0){
			TournamentArray[i]=array[j];
			j--;
		}
		else{
			TournamentArray[i]=compare(TournamentArray[2*i+1], TournamentArray[2*(i+1)]);
		}
    }
    find_secondmax(TournamentArray,SizeTournamentArray);
   
}





int main(int argc, char const *argv[])
{
	
	int n;   //size of array
	int i;
	scanf("%d",&n);
	int array[n];
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);

	}
	play_tournament(array,n);
	return 0;
}