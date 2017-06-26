#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct load_time{
	int start_time;
	int load;
	int end_time;
}load_time;

load_time* arr;

void terminate(){
	printf("ERROR\n");
	exit(1);
}

int comp(const void* num1, const void* num2){
	load_time n1= *((load_time*)num1);
	load_time n2= *((load_time*)num2);
	if(n1.start_time < n2.start_time)
		return -1;
	else if(n1.start_time > n2.start_time)
		return 1;
	return 0;
}

void read(char str[50], int index){
	char* temp= strtok(str," ");
	
	if(temp){
		arr[index].start_time= atoi(temp);
		temp= strtok(NULL," ");
	}else terminate();

	if(temp){
		arr[index].load= atoi(temp);
		temp= strtok(NULL," ");
	}else terminate();

	if(temp)
		arr[index].end_time= atoi(temp);
	else
		terminate();

	if(arr[index].start_time > arr[index].end_time || 
		arr[index].end_time<0 || arr[index].start_time<0 || arr[index].load < 0)
		terminate();
}

int main(){
	int n,i,j,k;
	char str[50];
	scanf("%d\n",&n);
	arr = (load_time*)malloc(sizeof(load_time)*n);
	i=0;
	while(fgets(str,49,stdin)!=NULL && i<n){
		read(str,i++);
	}
	qsort(arr,n,sizeof(load_time),comp);

	int max_time= arr[0].end_time;
	int min_time= arr[0].start_time;

	for(int i=0;i<n;++i)
		if(arr[i].end_time > max_time)
			max_time= arr[i].end_time;

	int interval_length= max_time- min_time+1;
	int temp_arr[interval_length+1];

	memset(temp_arr,0,sizeof temp_arr);

	for(int i=0;i<n;++i){
		int start= arr[i].start_time - min_time;
		int end= arr[i].end_time - min_time;
		int curr_load= arr[i].load;
		for(int j=start; j< end; ++j)
			if(temp_arr[j] < curr_load)
				temp_arr[j]=curr_load;
	}

	for(int i=0;i<interval_length;){
		int curr_load=temp_arr[i];
		printf("%d %d\n",i+min_time,curr_load);
		int j=i+1;
		while(j<interval_length && temp_arr[j]==curr_load)
			++j;
		i=j;
	}
}
