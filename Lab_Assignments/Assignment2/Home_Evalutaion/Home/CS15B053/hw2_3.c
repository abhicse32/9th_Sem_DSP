#include<stdio.h>
#include<stdlib.h>

int disks[3];

int TOH(int n, char from, char to, char using)
{
	int count=0;
	if(n==1)
	{
		count++;
		disks[from-'A']--; disks[to-'A']++;
		printf("%c -> %c %d %d %d\n", from, to, disks[0], disks[1], disks[2]);
	}
	else
	{
		count = TOH(n-1, from, using, to);
		disks[from-'A']--; disks[to-'A']++;
		printf("%c -> %c %d %d %d\n", from, to, disks[0], disks[1], disks[2]);
		count = count + 1 + TOH(n-1, using, to, from);
	}
	return count;
}
		

void main()
{
	int n;
	scanf("%d", &n);
	
	disks[0]=n; disks[1]=disks[2]=0;
	
	int count = TOH(n, 'A', 'C', 'B');
	printf("%d", count);
}
