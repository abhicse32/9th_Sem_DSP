#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void error () {
  printf ("ERROR\n");
  exit (-1);
}

int getInt (char *s, int *index) {
  int len = strlen (s);
  //discard initial spaces
  while ((*index) < len) {
    if (s[(*index)] == ' ')
      (*index) = (*index)+1;
    else
      break;
  }

  if ((*index) >= len)
    error();

  int ret=atoi (&(s[(*index)]));
  
  //move index to correct location
  int i=ret;
  do {
    (*index) = (*index)+1;
    i /= 10;
  } while (i>0);

  return ret;
}

int main () {
  char str[1000];
  //get the number of inputs
  int n;

  scanf ("%[^\n]\n", str);

  //check for error in input
  if (strlen(str) == 0)
    error();
  
  n = atoi (str);
  if (n < 0)
    error();

  int* input[n];

  for (int i=0;i<n;i++){
    int j=0;
    int *arr = (int *) malloc (3 * sizeof(int));

    str[0] = '\0';
    scanf ("%[^\n]\n", str);

    int index=0;
    arr[j++] = getInt (str, &index);
    arr[j++] = getInt (str, &index);
    arr[j++] = getInt (str, &index);

    if (arr[2] < arr[0])
      error();

    input[i]=arr;
  }

  //sort the input
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      if (input[i][0] > input[j][0]) {
      	int *temp;

      	temp     = input[i];
      	input[i] = input[j];
      	input[j] = temp;
      }
    }
  }

  //times at which the load is measured
  int timeMin=input[0][0];
  int timeMax=0;
  for (int i=0; i<n; i++) {
    int t = input[i][2];
    if (timeMax < t)
      timeMax=t;
  }

  int loadSize = timeMax-timeMin+1;

  int load[loadSize];
  
  for (int i=0; i<loadSize; i++)
    load[i]=0;

  //updateing loads
  for (int i=0; i<n; i++) {
    int start = input[i][0];
    int end   = input[i][2];
    int l     = input[i][1];

    for (int j=start-timeMin; j<end-timeMin; j++) {
      if (load[j] < l)
	      load[j] = l;
    }
  }  

  //display the load
  int previousLoad = -1;

  for (int i=0; i<loadSize; i++) {
    if (load[i] != previousLoad) {
      previousLoad = load[i];
      printf ("%d %d\n", i+timeMin, load[i]);
    }
  }
}
