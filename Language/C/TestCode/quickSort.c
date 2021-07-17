#include "quickSort.h"

/* TODO:
 *   1  loop version partition 
 *   2  decreased version quick sort */

/* quickSortCall:  call all functions about quick sort */
void quickSortCall()
{
    int *a, len;

    printf("Input array's len: ");
    scanf("%d", &len);
    getArray(&a, len);
    if (a == NULL) {
        printf("getArray:  alloc failed!\n");
        return ;
    }

    printf("Before sorting: ");
    displayArray(a, len);
    printLine(50);

    quickSort(a, len, 0, len-1);    /* quick sort */

    printLine(50);
    printf("After sorting: ");
    displayArray(a, len);

    freeArray(a);
}

/* getArray:  make p point to int array of 'len' size, if alloc fail, p point to NULL */
void getArray(int **p, int len)
{
    int i;

    *p = calloc((size_t)len, sizeof(int));    /* alloc array */
    //*p = malloc(sizeof(int)*len);    /* alloc array */
    if (*p == NULL)
        return;

    printf("Please input %d element of array:\n", len);
    for (i = 0; i < len; ++i) {
        printf("%3d: ", i);
        scanf("%d", *p+i);
    }
}

/* freeArray:  free heap space of array */
void freeArray(int *p)
{
    free(p);    /* free only accept pointer which is returned by alloc
                   function (malloc(), calloc(), realloc()) */
}

/* displayArray:  display array's all elements */
void displayArray(int a[], int n)
{
    int i;

    printf("[ ");
    for (i = 0; i < n; ++i)
        printf("%3d", a[i]);

    printf(" ]\n");
}

/* printLine:  print decorated line */
void printLine(int len)
{
    while (len) {
        printf("=");
        --len;
    }

    printf("\n");
}

/* swap:  swap a[s1] and a[s2] */
void swap(int a[], int s1, int s2)
{
    int t;

    t = a[s1];
    a[s1] = a[s2];
    a[s2] = t;
}

/* quickSort:  the practice of algorithms of quick sort */
void quickSort(int a[], int len, int left, int right)
{
    int pivot;
    int patitionPoint;

    if (left >= right)
        return ;

    pivot = a[right];
    patitionPoint = partition(a, len, left, right, pivot);
    quickSort(a, len, left, patitionPoint-1);
    quickSort(a, len, patitionPoint+1, right);

}

/* partition:  finish once partition in quick sort */
int partition(int a[], int len, int left, int right, int povit)
{
    int leftPointer, rightPointer;

    leftPointer = left - 1;
    rightPointer = right;

    while (true) {
        while (a[++leftPointer] < povit)
            ;
        while (rightPointer>0 && a[--rightPointer]>povit)
            ;

        if (leftPointer >= rightPointer)
            break;
        else {
            printf("item swapped: %d, %d\n", a[leftPointer], a[rightPointer]);
            swap(a, leftPointer, rightPointer);
        }
    }

    printf("povit swapped: %d, %d\n", a[leftPointer], a[right]);
    swap(a, leftPointer, right);
    displayArray(a, len);

    return leftPointer;    /* return povit's subscript */
}


