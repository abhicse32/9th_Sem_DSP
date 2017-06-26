
/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Sun Aug 21 23:00:24 IST 2016

Description:
This program takes the number of disks in tower 'A' in a typical Toer of Hanoi problem with 3 rods as input and 
outputs a step by step solution along with the total nuber of steps taken to achieve the solution.

*/



#include <stdio.h>

int dist[3] = {0};
char maps[3] = {'A', 'C', 'B'};

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{

    int i;
/*
    prints the solution to a typical 3-rod Tower of Hanoi problem with 'n' disks to begin with
*/

    if (n == 1)
    {
        printf("\n%c -> %c ", from_rod, to_rod);
        for(i=0; i<3; i++)
        {
            if(maps[i]==from_rod)
                dist[i]--;
            if(maps[i]==to_rod)
                dist[i]++;
        }
        printf("%d %d %d", dist[0], dist[1], dist[2]);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n%c -> %c ", from_rod, to_rod);
    for(i=0; i<3; i++)
        {
            if(maps[i]==from_rod)
                dist[i]--;
            if(maps[i]==to_rod)
                dist[i]++;
        }
    printf("%d %d %d", dist[0], dist[1], dist[2]); 
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
 
int main()
{

    int n;
    int x=1;
    scanf("%d", &n);
    
    dist[0] = n;
    
    towerOfHanoi(n, 'A', 'C', 'B');
    
    while(n--)
        x=2*x;

    printf("\n%d \n", x-1);
    return 0;
}