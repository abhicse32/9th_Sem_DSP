/*to find the Maximum and the Next-Maximum of an array of integers.*/
/*name D Teja Vardhan Reddy cs15b014 date 14/8/16*/
#include <stdio.h>
#include <limits.h>
#include <math.h>
void fill_arr(int*,int, int);
void update(int,int*);

int pos(int*b,int p,int h);
int max(int a,int b){		/*reutrns maximum of two numbers*/
	if(a<b)
		return b;				/*return statement*/
	else
		return a;
}
int main(){						/*main function*/
	int n,a[100000],b[400000],i,h;int s=0;
	scanf("%d",&n);
	
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
		
	}
 	int k=n-1;
 	while(k/2!=0){					/*while loop*/
		k=k/2;
 		s++;
 	}
 	
	h=pow(2,s+1);					/*power function from math library*/
	for (int i = n; i < h; ++i)
	{
		a[i]=INT_MIN;					/*use of macro*/
	}
	
	for (int i = h; i < 2*h; ++i)
	{
		b[i]=a[i-h];
	}
	
	fill_arr(b,h,2*h);
	
	int posi = pos(b,1,h);
	int max_element = b[1];
	update(posi,b);
	int next_max=b[1];
	printf("%d  %d",max_element,next_max);

 }
void fill_arr(int*b,int x,int y){   			/*to construct the tree*/
	if(x!=1){
		int i;
		for ( i = x; i < y; i+=2)
		{
			b[i/2]=max(b[i],b[i+1]);
		}
		fill_arr(b,x/2,y/2);
	}
}
int pos(int*b,int p,int h){						/*to find position of maximum*/
	if(p<h){
		int i;
		if(b[2*p]<b[2*p+1])
			i=2*p+1;
		else
			i=2*p;

		return pos(b,i,h);
	}
	else
		return p;


}
void update(int p,int*b){							/*to update  max element to least element*/
	b[p]=INT_MIN;
	while(p!=1){
		if(p%2==0){
			b[p/2]=max(b[p],b[p+1]);
			p=p/2;
		}
		else
		{
			b[p/2]=max(b[p-1],b[p]);
			p=p/2;
		}
	}

}
	