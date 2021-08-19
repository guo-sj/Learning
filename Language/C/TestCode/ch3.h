#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum ch3 {COUNTDWO = 1, MYATOI, SHELLSORT, REVERSE, QUIT = 0};
void ch3Call();
void ch3PrintMenu();
void countdwo();
int myatoi(char *s);
void myatoiCall();

void shellsortCall();
void shellsort(int v[], int n);
void print_array(int a[], int n);

void reverseCall();
void reverse(char s[]);

