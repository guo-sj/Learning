#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int key;
    struct node *next;
} *head;

void display_linklist(struct node *head);
void insert_linklist_first(struct node **head, int key, int data);
void delete_linklist_first(struct node **head);
struct node *search_linklist(struct node *head, int key);
int delete_linklist_key(struct node *head, int key);
void reverse_linklist(struct node **head);
int isempty_linklist(struct node *head);
int getlength_linklist(struct node *head);
