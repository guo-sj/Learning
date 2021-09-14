#include <stdio.h>

enum array {
    TRAVERSE_ARRAY = 1,
    INSERT_ARRAY,
    DELETE_ARRAY,
    SEARCH_ARRAY,
    UPDATE_ARRAY,
};

void traverse_array(int a[], int length);
void insert_array(int a[], int *length, int elem, int index);
void delete_array(int a[], int *length, int index);
int search_array(int a[], int length, int value);
void update_array(int a[], int index, int value);

void call_update_array(int a[], int length);
void call_search_array(int a[], int length);
void call_delete_array(int a[], int *length);
void call_insert_array(int a[], int *length);
void call_traverse_array(int a[], int length);

void call_array_operation();
void print_array_menu();
