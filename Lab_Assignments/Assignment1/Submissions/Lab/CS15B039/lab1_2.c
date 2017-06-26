/*
Operations on Complex Numbers
__author__= 'Vishal'
__date__= 08/08/16
*/

#include <stdio.h>

void minmax(int *);
int max(int *, int);
int min(int *, int);

int main(){
	
	int n;
	scanf("%d", &n);
	int A[n];
	int i;

	for (i=0;i<n;i++){
		scanf("%d", &A[i]);
	}

	minmax(A);

return 0;	
}

void minmax(int *A){
	int size, max_size, min_size;
	int count=0;
 	int i;
	int vmax, vmin; 

	size = sizeof(A);

	if (size%2==0){
		max_size=(size/2)+1;
		min_size=size/2;
		}

	int Amax[max_size];
	int Amin[min_size];
	for (i=1; i<size; i+=2){
		if (A[i]>=A[i-1]){
			Amax[count]=A[i];
			Amin[count]=A[i-1];
			}
		else{
			Amax[count]=A[i-1];
			Amin[count]=A[i];
			}
	count+=1;
	}
	if (size%2!=0){
		Amax[count]=A[size-1];
		}
	vmax = max(Amax, max_size);
	vmin = min(Amin, min_size);
	printf("%d %d\n", vmin, vmax);
}

int max(int *A, int size){
	int max_value;
	int i;
	max_value = A[0];
	for (i=1; i<size; i++){
		if (A[i]>max_value){
			max_value=A[i];
			}
	}
	return max_value;
}

int min(int *A, int size){
	int min_value;
	int i;
	min_value = A[0];
	for (i=1; i<size; i++){
		if (A[i]<min_value){
			min_value=A[i];
			}
	}
	return min_value;
}
