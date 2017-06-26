#include <stdio.h>
void print_hexadecimal(int a[]){
	printf("0x");
	int j;
	for(j=0;j<8;j++){
		switch(a[j]){
			case 0: printf("0"); break;
			case 1: printf("1"); break;
			case 2: printf("2"); break;
			case 3: printf("3"); break;
			case 4: printf("4"); break;
			case 5: printf("5"); break;
			case 6: printf("6"); break;
			case 7: printf("7"); break;
			case 8: printf("8"); break;
			case 9: printf("9"); break;
			case 10: printf("a"); break;
			case 11: printf("b"); break;
			case 12: printf("c"); break;
			case 13: printf("d"); break;
			case 14: printf("e"); break;
			case 15: printf("f"); break;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int a[8];
	int i;
	for(i=0;i<8;i++){
		a[i]=0;	
	}
	int q,r;
	q=n;
	i=7;
	while(q!=0){
		r=q%16;
		q=q/16;
		a[i]=r;
		i--;
	}
      print_hexadecimal(a);
    return 0;

}
