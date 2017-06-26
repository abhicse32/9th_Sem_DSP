#include<stdio.h>
#include<stdlib.h>

int NewPos(int position, char move)
{
	if(move == 'L')
		return position*2;
	if(move == 'R')
		return position*2 + 1;
	if(move == 'U')
		return position/2;
	//else move == 'S'
	return position;
}

void OneOutArray(int array[], int length)
{
	int i;
	for(i = 0; i < length; i++)
	{
		array[i] = 1;
	}
}

//returns the index at which the Thief was caught or 0 if not caught
int ThiefCaught(int polices[], int numPolices, int thiefIndex)
{
	int i;
	for(i = 0; i < numPolices; i++)
	{
		if(polices[i] == thiefIndex)
			return i+1;
	}
	return 0;
}

int main() {
	int moveNum = 0;
	int thiefIndex = 0;
	int numProbs = 0;
	int numPolices = 0;
	int numMoves = 0;
	char turn[1002]; // assuming max 1000 Polices and 1 Thief
	int tempPos = 0;
	int catchCheck = 0;
	int thiefCaught = 0;
	int *polices;
	int i, j, k;
	
	//scanf("%d",&numProbs);
	
	//for(i=1; i < numProbs+1; i++)
	//{
		//thiefCaught = 0;
		
		//if(i > 1)
		//	printf("\n");
		
		//initialize tree positions
		scanf("%d %d %d",&numPolices, &numMoves, &thiefIndex);
		polices = (int *)malloc(numPolices*sizeof(int));
		OneOutArray(polices, numPolices);

		if(thiefIndex == 1)
		{
			printf("1 1");
			thiefCaught = 1;
		}
		else{
			for(j=0; j< numMoves; j++)
			{
				scanf("%s", turn);

				tempPos = NewPos(thiefIndex, turn[0]);
				thiefIndex = tempPos;

				catchCheck = ThiefCaught(polices, numPolices, thiefIndex);
				if(catchCheck > 0)
				{
					printf("%d %d", numMoves, catchCheck);
					thiefCaught = 1;
					break;
				}
				
				for(k=0; k < numPolices; k++)
				{
					tempPos = NewPos(polices[k], turn[k+1]);
					polices[k] = tempPos;
				}

				catchCheck = ThiefCaught(polices, numPolices, thiefIndex);
				if(catchCheck > 0)
				{
					printf("%d %d", numMoves, catchCheck);
					thiefCaught = 1;
					break;
				}
			}
		}
		if(!thiefCaught)
			printf("0 0");
		printf("\n");
	//}//for each problem
	return 0;
}
