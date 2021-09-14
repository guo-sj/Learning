#include "arrayOperation.h"

/* traverse_array:  print all the array elements one by one */
void traverse_array(int a[], int length)
{
    int i;

    for (i = 0; i < length; ++i)
        printf(" %d", a[i]);
    printf("\n");
}

/* call_traverse_array:  test traverse_array() */
void call_traverse_array(int a[], int length)
{
    traverse_array(a, length);
}

/* insert_array:  adds an element at the given index, index commences at 0 */
void insert_array(int a[], int *length, int elem, int index)
{
    int i;

    for (i = *length - 1; i >= index; --i)
        a[i+1] = a[i];
    a[++i] = elem;
    *length += 1;
}

/* call_insert_array:  test insert_array() */
void call_insert_array(int a[], int *length)
{
    printf("Insert element: 10, index 3\n");
    insert_array(a, length, 10, 3);
    traverse_array(a, *length);
}

/* delete_array:  deletes an index element at the given array */
void delete_array(int a[], int *length, int index)
{
    int i;

    for (i = index; i < *length - 1; ++i)
        a[i] = a[i+1];
    *length -= 1;
}

void call_delete_array(int a[], int *length)
{
    printf("delete index: 3\n");
    delete_array(a, length, 3);
    traverse_array(a, *length);
}

/* search_array:  searches an element using the given the value */
int search_array(int a[], int length, int value)
{
    int i;

    for (i = 0; i < length; ++i)
        if (a[i] == value)
            return i;
    return -1;
}

/* call_search_array:  test search_array */
void call_search_array(int a[], int length)
{
    printf("Search element: 8\n");
    printf("8's index is %d\n", search_array(a, length, 8));
    printf("Search element: 9\n");
    printf("9's index is %d\n", search_array(a, length, 9));
}

/* update_array:  update an element at the given index */
void update_array(int a[], int index, int value)
{
    a[index] = value;
}

/* call_update_array:  test update_array() */
void call_update_array(int a[], int length)
{
    printf("Update index: 3, element: 10\n");
    update_array(a, 3, 10);
}

/* call_array_operation:  test all array operation */
void call_array_operation()
{
    int choose;
    int a[10] = {1, 3, 5, 7, 8};
    int length = 5;

    choose = -1;
    while (choose) {
        print_array_menu();
        scanf("%d", &choose);

        switch (choose) {
            case TRAVERSE_ARRAY:
                call_traverse_array(a, length);
                break;

            case INSERT_ARRAY:
                call_insert_array(a, &length);
                break;

            case DELETE_ARRAY:
                call_delete_array(a, &length);
                break;

            case SEARCH_ARRAY:
                call_search_array(a, length);
                break;

            case UPDATE_ARRAY:
                call_update_array(a, length);
                break;

            default:
                break;
        }
    }
}

/* print_array_menu: print array related menu */
void print_array_menu()
{
    printf("\n");
    printf("array menu:\n");
    printf("1 traverse_array\n");
    printf("2 insert_array\n");
    printf("3 delete_array\n");
    printf("4 search_array\n");
    printf("5 update_array\n");
    printf("0 quit\n");
    printf("Input: ");
}
