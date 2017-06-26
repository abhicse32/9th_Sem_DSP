/*
	Author: G.Kavitha
	Roll No. CS15B057
	Date: 16-09-16
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
const int SIZE=10005;
int top=-1;
int stack_size(int arr[SIZE]){//To get the size of the stack arr
	return (top+1);
}
int stack_top(int arr[SIZE]){//To get the top element in the stack
	if(top==-1) return INT_MIN;
	return arr[top];
}	
void stack_push(int arr[SIZE], int ch){//To push an element in stack arr
	if(top==SIZE-1) return;
	top++;
	arr[top]=ch;
}
void stack_pop(int arr[SIZE]){//To pop the top most element in stack arr
	if(top==-1) return;
	top--;
}

//Function to solve for the ans
//arr is the stack which holds the elements of A[p+1: n-1]
//ans holds the final answer for the next larger number of A[p]
//p is the index (0 based indexing)
//n is the value A[p]
void solve(int arr[SIZE],int ans[SIZE],int p, int n){
	if(stack_size(arr)==0) {//no number after it was larger than it
		ans[p]=-1;//set to -1
		return;
	}
	if(n<stack_top(arr)) {//the number in the top of the stack is greater than n
		ans[p]=stack_top(arr);//set answer to the top number in stack arr
	}
	else{
		while(stack_size(arr)>0&&stack_top(arr)<=n)
			stack_pop(arr);//pop all element less than equal to n
		if(stack_size(arr)==0) ans[p]=-1;
		else ans[p]=stack_top(arr);
	}
}
int main(){
	int arr[SIZE];//stack implemented as an array
	int t;//Number of test cases
	scanf("%d",&t);//read in t

	int A[SIZE];//Holds the input array A
	
	while(t--){
		top=-1;
		int n;//number of elements in A
		scanf("%d",&n);//Read in n
		int i;

		for(i=0;i<n;i++) scanf("%d",&A[i]);//Read in elements of array
		
		int ans[SIZE];//Holds the final answer

		for(i=n-1;i>=0;i--){
			solve(arr,ans,i,A[i]);//Solving for the ith index
			stack_push(arr,A[i]);//Pushing A[i] into the stack arr
		}

		for(i=0;i<n;i++) printf("%d ",ans[i]);//Printing the answers
		printf("\n");
	}
	return 0;
}
