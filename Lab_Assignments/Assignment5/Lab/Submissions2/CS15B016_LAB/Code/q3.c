/*PROGRAM TO FID NEXT MAX OF EACH NUMBER IN THE ARRAY
AUTHOR: GIRIDHAR S 
ROLL NUMBER: CS15B016
DATE 16 SEPT*/

#include<stdio.h>
#include<malloc.h>
#include "stack.h"
#include "stack.c"
#include "List.h"
#include "List.c"
/*
void analyse(int a[], int size){
	stack *s=stack_new();
	int i=0;
	int y,q;
	while(i<size){
		if(stack_is_empty(s))
			stack_push(s,i);
		else{
			int count=1;
			q=i-1;
			while(1){
				
				y=stack_pop(s);
				if(y>(q--)) {stack_push(s,y); break;}
				if(a[i]>a[y]) 
					{
					count++;
					if(stack_is_empty(s)) break;
					continue;
					}
				
				else {stack_push(s,y); break;}
			}
			stack_print(s);
			printf("\n");

			while(count--){stack_push(s,i);}
		}
	i++;
	}
stack_print(s);
printf("\n");
	int size2=size;
	int *b=(int*)malloc(sizeof(int)*size);
	size--;
	while(!stack_is_empty(s)){
		int ind=stack_pop(s);
//		printf("\n...%d;;%d",ind,size);
		if(size==ind)
			b[size]=-1;
		else
			b[size]=a[ind];
		size--;
	}				
    int j;
    for(j=0;j<size2;j++) printf("%d ",b[j]);
    printf("\n");	
}
*/

//function uses three stacks to analyse the given array and update it

void analyse2(int a[], int size){

stack *s; //preliminary stack, indices from the array are pushed into this in such a manner that from head to tail the array values for that index is increasing
stack *index; //stores the index from the array
stack *nextg; //stores the nextgreater value for each index

s=stack_new();
index=stack_new();
nextg=stack_new();

int flag;
int i=0;
int tmp;
int val;
//loop runs through the array once and sets up the three stacks
for(i=0;i<size;i++){
	if(stack_is_empty(s)) stack_push(s,i);
	else{
		tmp=stack_pop(s);
		if(a[tmp]>=a[i]) 
			{ stack_push(s, tmp); stack_push(s,i); }
		else if(a[tmp]<a[i]){
			flag=1;
			do{
			stack_push(index,tmp);
			stack_push(nextg,a[i]);
			if(stack_is_empty(s)) {flag=0;break;}
			tmp=stack_pop(s);
			}while(a[tmp]<a[i]);
			if(flag){
				stack_push(s,tmp);
			}
			stack_push(s,i);
		}
	}
}

//finally, all the elements remaining in s must be put into index, such that their nextg values are -1
while(!stack_is_empty(s)){
	tmp=stack_pop(s);
	stack_push(index, tmp);
	stack_push(nextg, -1);
}

//to update values in the array
while(!stack_is_empty(index)){
	tmp=stack_pop(index);
	val=stack_pop(nextg);
	a[tmp]=val;
}

}
						
			

int main(){
  int test,size,*array;
  scanf("%d",&test);
  while(test--){
    scanf("%d",&size);
    array=(int*)malloc(sizeof(int)*(size));
    int i=0;
    for(i=0;i<size;i++){
      scanf("%d",&array[i]);
    }
    

    analyse2(array,size);

    for(i=0;i<size;i++){ printf("%d ",array[i]); }
    printf("\n");	

  }
}
      
  
