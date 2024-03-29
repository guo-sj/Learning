#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quickSortCall();
void displayArray(int a[], int n);
void printLine(int len);
void swap(int a[], int s1, int s2);
int increasePartition(int a[], int len, int left, int right, int povit);
int decreasePartition(int a[], int len, int left, int right, int povit);
void quickSort(int a[], int len, int left, int right, bool increasing);
void getArray(int **p, int len);
void freeArray(int *p);

