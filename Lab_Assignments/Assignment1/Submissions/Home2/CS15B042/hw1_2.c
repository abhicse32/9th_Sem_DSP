#include <stdio.h>

int main(){
	int n;
	fscanf(stdin,"%d",&n);
	fprintf(stdout,"0x%08x\n",n);
	return 0;
}
