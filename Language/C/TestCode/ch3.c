#include "ch3.h"

/* This file contains code in chapter 3 of  <The C Programming Language>.*/

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
    printf("  1 COUNTDWO\n");
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


