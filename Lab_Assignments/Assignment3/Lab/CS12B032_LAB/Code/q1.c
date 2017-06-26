#include <stdio.h>
#include <stdlib.h>
int comp1,comp2,comp3;
int binarySearch(int* arr, int l, int r, int val){
	if(l>r)
		return -1;
	int mid=l+((r-l)>>1);
	if(arr[mid]==val){
		comp1++;
		return mid;
	}
	else if(arr[mid]>val){
		comp1+=2;
		return binarySearch(arr,l,mid-1,val);
	}
	else{
		comp1+=2;
	 	return binarySearch(arr,mid+1,r,val);
	}
}

int binarySearch2(int*arr, int l, int r, int val){
	if(l>r)
		return -1;
	int _third= l+((r-l)/3);
	if(arr[_third]==val){
		comp2++;
		return _third;
	}
	else if(arr[_third]>val){
		comp2+=2;
		return binarySearch2(arr,l,_third-1,val);
	}
	else{ 
		comp2+=2;
		return binarySearch2(arr,_third+1,r,val);
	}
}

int ternarySearch(int*arr, int l, int r, int val){
	if(l>r)
		return -1;
	int part=(r-l)/3;
	int _1third=l+part;
	int _2third=_1third+part;
	if(arr[_1third]==val){
		comp3++;
		return _1third;
	}
	else if(arr[_1third]>val){
		comp3+=2;
		return ternarySearch(arr,l,_1third-1,val);
	}
	else if(arr[_2third]==val){
		comp3+=3;
		return _2third;
	}
	else if(arr[_2third]>val){
		comp3+=4;
		return ternarySearch(arr,_1third+1,_2third-1,val);
	}
	else{
		comp3+=4;	 
		return ternarySearch(arr,_2third+1,r,val);
	}
}

int main(){
	int n,i,j,k;
	scanf("%d",&n);
	int* arr= (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&k);
	comp1=comp2=comp3=0;
	printf("%d %d %d\n",binarySearch(arr,0,n-1,k),binarySearch2(arr,0,n-1,k),ternarySearch(arr,0,n-1,k));
	printf("%d %d %d\n",comp1,comp2,comp3);
}