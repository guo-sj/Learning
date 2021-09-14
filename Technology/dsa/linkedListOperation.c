#include "linkedListOperation.h"

/* display_linklist:  display the complete list */
void display_linklist(struct node *head)
{
    struct node *pn;
    printf("\n[");

    for (pn = head; pn != NULL; pn = pn->next)
        printf("(%d, %d) ", pn->key, pn->data);
    printf("]\n");
}

/* insert_linklist_first:  adds an element at the beginning of the list */
void insert_linklist_first(struct node **head, int key, int data)
{
    struct node *link = (struct node *) malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    link->next = *head;
    *head = link;
}

/* delete_linklist_first:  delete an element at the beginning of the list */
void delete_linklist_first(struct node **head)
{
    struct node *pn = *head;
    *head = (*head)->next;
    pn->next = NULL;
    free(pn);
}

/* search_linklist:  search an element using the given key */
struct node *search_linklist(struct node *head, int key)
{
    struct node *pn;

    for (pn = head; pn != NULL; pn = pn->next)
        if (pn->key == key)
            return pn;
    return NULL;
}

/* delete_linklist_key:  delete an element using the given key */
int delete_linklist_key(struct node *head, int key)
{
    struct node *pn;
    struct node *ppn;    /* previous pn */

    for (pn = ppn = head; pn != NULL; ppn=pn, pn=pn->next)
        if (pn->key == key)
            break;

    if (pn == NULL)
        return -1;
    ppn->next = pn->next;
    pn->next = NULL;
    free(pn);
}

/* reverse_linklist:  reverse the list */
void reverse_linklist(struct node **head)
{
    struct node *pn, *ppn;
    struct node *npn;    /* next pn */

    ppn = NULL; 
    pn = *head;
    while (pn != NULL) {
        npn = pn->next;
        pn->next = ppn;
        ppn = pn;
        pn = npn;
    }
    *head = ppn;
}

/* isempty_linklist:  if the list is empty, return 1 */
int isempty_linklist(struct node *head)
{
    return head == NULL;
}

/* getlength_linklist:  return length of the list */
int getlength_linklist(struct node *head)
{
    struct node *pn;
    int length;

    for (length=0, pn=head; pn != NULL; pn = pn->next, ++length)
        ;
    return length;
}
