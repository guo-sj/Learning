#include "ch3.h"

/* This file contains code in chapter 3 of <The C Programming Language> */

/* ch3Call:  call all ch3 functions */
void ch3Call()
{
    int choose;

    choose = -1;
    while (choose) {
        ch3PrintMenu();
        scanf("%d", &choose);
        switch (choose) {
            case COUNTDWO:
                countdwo();
                getchar();    /* filter */
                break;

            case MYATOI:
                myatoiCall();
                break;

            case SHELLSORT:
                shellsortCall();
                break;

            case REVERSE:
                reverseCall();
                break;

            case ITOA:
                itoaCall();
                break;

            case QUIT:
                printf("Get 0, quit!\n");
                break;

            default:
                printf("Invalid input, quit.\n");
                break;
        }
    }
}

/* ch3PrintMenu:  print ch3 menu */
void ch3PrintMenu()
{
    printf("\n");
    printf("  ch3:\n");
    printf("  1 COUNTDWO\n");
    printf("  2 MYATOI\n");
    printf("  3 SHELLSORT\n");
    printf("  4 REVERSE\n");
    printf("  5 ITOA\n");
    printf("  0 QUIT\n");
    printf("  Input: ");
}

/* countdwo:  count the occurrences of each digit, white space, 
 * and all other characters, switch case version */
void countdwo()
{
    int i, c, ndigit[10], nwhite, nother;

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c=getchar()) != EOF)
        switch (c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9': 
                ++ndigit[c-'0'];
                break;

            case ' ':
            case '\t':
            case '\n':
                ++nwhite;
                break;

            default:    /* all other characters */
                ++nother;
                break;
        }

    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", nwhite = %d, nother = %d\n", nwhite, nother);
}

/* myatoi:  convert s to integer; version 2 */
int myatoi(char *s)
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); ++i)    /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')    /* skip sign */
        ++i;
    for (n = 0; isdigit(s[i]); ++i)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

/* myatoiCall:  call myatoi() */
void myatoiCall()
{
    char *s1 = "123";
    char *s2 = "-123";
    char *s3 = "  123";

    printf("%-10s%-10s\n", "string", "number");
    printf("%-10s%-10d\n", s1, myatoi(s1));
    printf("%-10s%-10d\n", s2, myatoi(s2));
    printf("%-10s%-10d\n", s3, myatoi(s3));
}

/* shellsortCall: call shellsort() */
void shellsortCall()
{
    int a[8] = {35, 33, 42, 10, 14, 19, 27, 44};

    printf("Before Sort:\n");
    print_array(a, 8);
    shellsort(a, 8);
    printf("After Sort:\n");
    print_array(a, 8);
}

/* shellsort:  sort v[0] ... v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    int dcount;    /* debug count */

    dcount = 0;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; ++i)
            for (j = i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                printf("%d <-> %d\n", v[j], v[j+gap]);  /* debug info */
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;

                /* debug info */
                printf("No.%d: ", ++dcount);  
                print_array(v, n);
            }
}

/* print_array: print a[0] ... a[n-1] */
void print_array(int a[], int n)
{
    int i;

    for (i = 0; i < n; ++i)
        printf("%3d", a[i]);
    printf("\n");
}

/* reverseCall: call reverse() */
void reverseCall()
{
    char s[] = "Hi, Nanjing.";

    printf("Before reverse: %s\n", s);
    reverse(s);
    printf("After reverse: %s\n", s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)     /* record sign */
        n = -n;             /* make n positive */
    i = 0;
    do {                    /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = 0;
    reverse(s);
}

void itoaCall()
{
    int n;
    char s[MAX];

    n = -99;
    itoa(n, s);
    printf("n = %d, s = %s\n", n, s);
}
