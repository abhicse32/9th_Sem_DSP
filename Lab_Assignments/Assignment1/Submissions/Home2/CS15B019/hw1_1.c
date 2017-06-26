//file content - finding maximum and next maximum out of n intergers
//author - Shiva Poojith
//date - 14/08/2016

#include <stdio.h>

int main()
{
	int n,i,temp;
	int max1=-1,max2=-1;
	scanf("%d",&n);

	for(i =0;i<n;i++)
	{
		scanf("%d",&temp);
		if (temp>max1) {
			max2 = max1;
			max1 = temp;
		}
		else if (temp>max2)
			max2 = temp;
	}
	printf("%d %d\n",max1,max2);
}
