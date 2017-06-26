//Homework Assignment 1.1 by Raghavan S CS15B034: finding maximum and next maximum given array size and a series of inputs
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define intmin -2147483648
int main()
{
int *ar;                                      //array of inputs
int *kn;                                      //knockout tourney ds as an array
int l[20];                                    //boolean string to check odd no of elements in each knockout round
int max,nmax;                                 //maximum and nextmaximum
max=nmax=intmin;                              //initialization to min possible int
int n;                                        //size of input array
int nnew;                                     //size of the knockout round
int i,j;                                      //counters
int begin,end;                                //counters that denote beginning and end element of the knockout round
int pos,pos2,posm;
/*pos is the occurence of position of the max element in a round, pos2 is the position of the loser to max element
  in the previous round and posm is the position of max element in the previous round in the kn array */
scanf("%d",&n);
float c=log(n-1)/log(2);                      //number of knockout rounds in float
int count = c;                                //number of knockout rounds - 1 this keeps the track of which round is being processed
int cc=c;                                     //number of knockout rounds - 1
if(n<=0)
  exit(0);                                    //wrong input
ar=(int *) malloc(100000*sizeof(int));
kn=(int *) malloc(200040*sizeof(int));        //allocation of memory
for(i=0;i<n;i++)
  scanf("%d",&ar[i]);                         //scanning the array elements
for(i=0;i<20;i++)
  l[i]=0;                                     //l[i]=0 implies even players and 1 implies odd players in a particular round
nnew=n;                                       //initial value of nnew is n
  for(j=0;j<n;j++)
  {
    kn[n+count+j]=ar[j];                      //assigning knockout tourney initial players
  }
begin=n+count;
end=begin+n-1;                                //assigning start and end element indices
/*the following loop assigns the winners in each round of the tourney in subsequent places in the array*/
do
{
  if(nnew%2!=0)                               //in case of odd players
  {
    begin--;
    kn[begin]=intmin;                         //adding extra player with min value
    nnew++;
    l[count]=1;
  }
  count--;
  for(j=0;j<nnew/2;j++)                       //assigns winners of each comparison to a place in the array
  {
    if(kn[end-2*j]>kn[end-2*j-1])
      kn[begin-j-1]=kn[end-2*j];
    else
      kn[begin-j-1]=kn[end-2*j-1];
  }
  end=begin-1;
  begin=begin-j;                              //updating parameters
  nnew=nnew/2;
} while(begin!=end);                          //the loop ends if begin and end are same i.e. only one player in a round
pos=begin;
max=kn[begin];                                //assigning max to the tourney winner
/*the following loop runs through the tourney rounds to find the competitors to the winner to find the nextmax*/
do
{
  count++;
  if(max==kn[end+2*(pos-begin)+1])            //checking position of the winner in the knockout round and using competitors to update nmax
  {
    posm=end+2*(pos-begin)+1;
    pos2=end+2*(pos-begin)+2;
  }
  else
  {
    pos2=end+2*(pos-begin)+1;
    posm=end+2*(pos-begin)+2;
  }
  if(nmax<kn[pos2])
    nmax=kn[pos2];
  pos=posm;                                   //updation of parameters
  nnew=nnew*2;
  begin=end+1;
  end=end+nnew;
  if(l[count]==1)                             //in case of odd competitorsin the next round
  {
    nnew--;
    begin++;
  }
} while(count<cc);                            //the first knockout round occurs at count=cc and hence will be the last to be accessed
printf("%d %d",max,nmax);                     //printing max and next maximum
free(ar);
free(kn);
return 0;
}
