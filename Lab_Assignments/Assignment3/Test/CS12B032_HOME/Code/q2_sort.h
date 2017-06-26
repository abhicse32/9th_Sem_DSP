#ifndef SORTING_H
#define SORTING_H

double useSort(void(*fp)(int*,int),int*, int);
void printArr(int*, int);
int partition(int*, int, int);
void quick2(int*, int, int);
void split(int*, int , int);
void merge(int*, int, int, int);
void bubble_sort(int*, int);
void selection_sort(int*, int);
void insertion_sort(int*,int);
void quick_sort(int*,int);
void merge_sort(int*,int);

#endif 