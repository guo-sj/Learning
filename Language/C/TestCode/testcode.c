#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "testcode.h"
#include "testextern.h"

int main()
{
    int choose;

    choose = -1;

    while (choose != 0) {
        printinfo(MAIN);
        scanf("%d", &choose);

        switch(choose) {
            case 1:
                testextern();
                break;

            case 2:
                testarrayaddr();
                break;

            case 3:
                testsprintf();
                break;

            case 4:
                testfloat();
                break;

            case 5:
                testdouble();
                break;

            case 6:
                testTypeCast();
                break;

            case 7:
                testStringConstant();
                break;

            case 8:
                {
                    char dest1[50] = "";                   // for myStrcpy1
                    char sour1[50] = "Now it is time!";    // for myStrcpy1
                    char dest2[50] = "";                   // for myStrcpy2
                    char sour2[50] = "Now it is time!";    // for myStrcpy2
                    char dest3[50] = "";                   // for myStrcpy3
                    char sour3[50] = "Now it is time!";    // for myStrcpy3

                    printf("myStrcpy1:\n");
                    myStrcpy1(dest1, sour1);
                    printf("source string: %s\n", sour1);
                    printf("After copy... ...\n");
                    printf("destination string: %s\n\n\n", dest1);

                    printf("myStrcpy2:\n");
                    myStrcpy2(dest2, sour2);
                    printf("source string: %s\n", sour2);
                    printf("After copy... ...\n");
                    printf("destination string: %s\n\n\n", dest2);

                    printf("myStrcpy3:\n");
                    myStrcpy3(dest3, sour3);
                    printf("source string: %s\n", sour3);
                    printf("After copy... ...\n");
                    printf("destination string: %s\n", dest3);
                }
                break;

            case 9:
                {
                    char s[50] = "Happy";
                    char t[50] = "Birthday";

                    printf("myStrcmpA:    %d\n", myStrcmpA(s, t));
                    printf("myStrcmpP:    %d\n", myStrcmpP(s, t));
                }
                break;

            case 10:
                printPricision();
                break;

            case 11:
                testConstant();
                break;

            case 12:
                testBell();
                break;

            case 13:
                testEnum();
                break;

            case 14:
                testEnum();
                break;

            case 15:
                testConversion();
                break;

            case 16:
                testRandom();
                break;

            case 17:
                testIncrementAndDecrementOperator();
                break;

            case 18:    // TODO: get bug when type EOF
                {
                    char s[MAXLEN];
                    int c;

                    getchar();    // filter '\n'
                    while (mygetline(s, MAXLEN) > 0) {
                        printf("input c: ");
                        c = getchar();
                        getchar();    // filter '\n'
                        squeeze(s, c);
                        printf("%s", s);
                    }

                    getchar();
                }
                break;

            case 19:
                {
                    char s[MAXLEN], t[MAXLEN];

                    getchar();    /* filter '\n' */
                    if (mygetline(s, MAXLEN) > 0 && mygetline(t, MAXLEN) > 0)
                        myStrcat(s, t);
                    printf("%s", s);
                }
                break;

            case 20:
                testBitwiseOperators();
                break;

            case 21:
                {
                    unsigned x;
                    int p, n;

                    printf("Please input :x p n\n");
                    scanf("%x%d%d", &x, &p, &n);
                    printf("(x >> (p+1-n)) & ~(~0 << n) = 0x%x", getbits(x, p, n));
                }
                break;

            case 22:
                {
                    unsigned n, i;
                    int a[MAXLEN];
                    int c;

                    printf("Input n: ");
                    scanf("%d", &n);

                    printf("Input a: ");
                    for (i = 0; i < n; ++i)
                        scanf("%d", &a[i]);

                    formatPrint_1(a, n);
                }
                break;
                
            case 23:
                formatPrint_2(10);
                formatPrint_2(1);
                break;

            case 24:
                precedence();
                break;

            default:
                break;
        }
    }
}

void printinfo(int funcname)
{
    switch (funcname) {
        case MAIN:
            printf("\n");
            printf("Input 1, testextern\n");
            printf("      2, testarrayaddr\n");
            printf("      3, testsprintf\n");
            printf("      4, testfloat\n");
            printf("      5, testdouble\n");
            printf("      6, testTypeCast\n");
            printf("      7, testStringConstant\n");
            printf("      8, myStrcpy1, myStrcpy2, myStrcpy3\n");
            printf("      9, myStrcmpA, myStrcmpP\n");
            printf("      10, printPricision\n");
            printf("      11, test constant\n");
            printf("      12, test bell\n");
            printf("      13, test enum\n");
            printf("      14, test const\n");
            printf("      15, test conversion\n");
            printf("      16, test pseudo-random number generator\n");
            printf("      17, test Increment and decrement operator\n");
            printf("      18, squeeze\n");
            printf("      19, test myStrcat\n");
            printf("      20, test bitwise operators\n");
            printf("      21, test getbits\n");
            printf("      22, formatPrint_1\n");
            printf("      23, formatPrint_2\n");
            printf("      24, precedence\n");
            printf("      0, quit\n");
            printf("Input:");
            break;

        case TESTFLOAT:
            printf("\n");
            printf("Input 1, 04.4f\n");
            printf("      2, 04.2f\n");
            printf("      3, 02.2f\n");
            printf("      4, 2.1f\n");
            printf("      5, f\n");
            printf("      6, float type size\n");
            printf("      0, quit\n");
            printf("Input:");
            break;

        default:
            break;
    }
}

int testextern()
{
    dprint(te, d);

    return OK;
}

int testarrayaddr()
{
    char c[MAXLEN] = {0};
    char *p;

    p = c;

    print(c << );
    scanf("%s", c);
    dprint(c, s);

    return OK;
}

int testsprintf()
{
    int user;
    char acTmp[5] = "";
    unsigned short usNNNN;

    printf("\n - Please input user:\n\n\t user << ");
    scanf("%d", &user);
    usNNNN = (unsigned short)user;
    sprintf(acTmp, "%04hu", usNNNN);

    dprint(usNNNN, hd);
    dprint(acTmp, s);

    return OK;
}

int testfloat()
{
    int choose;
    float flt;
    char fc[MAXLEN] = "";

    choose = -1;

    print(Please input:\n\n\t flt <<);
    scanf("%f", &flt);

    while (choose != 0) {
        printinfo(TESTFLOAT);
        scanf("%d", &choose);

        switch(choose) {
            case 1:
                dprint(flt, 04.4f);
                sprintf(fc, "%04.4f", flt);
                dprint(fc, s);
                break;

            case 2:
                dprint(flt, 04.2f);
                sprintf(fc, "%04.2f", flt);
                dprint(fc, s);
                break;

            case 3:
                dprint(flt, 02.2f);
                sprintf(fc, "%02.2f", flt);
                dprint(fc, s);
                break;

            case 4:
                dprint(flt, 2.1f);
                sprintf(fc, "%2.1f", flt);
                dprint(fc, s);
                break;

            case 5:
                dprint(flt, f);
                sprintf(fc, "%07.1f", flt);
                dprint(fc, s);
                break;

            case 6:
                dprint(sizeof(flt), lu);
                break;

            default:
                break;
        }
    }
    return OK;
}

/* test double size */
int testdouble()
{
    double d;
    size_t n;

    d = 0.0;
    n = sizeof(d);
    printf("double size:");
    dprint(n, lu);

    return OK;
}

/* unsigned int -> int */
int testTypeCast()
{
    unsigned int ui;
    int i;

    ui = 0xffffffff;
    i = (int)ui;
    dprint(ui, u);
    dprint(i, d);

    return OK;
}

/* test string constant */
int testStringConstant()
{
    char *pmessage;

    pmessage = "now is the time";

    printf("%s", pmessage);

    return OK;
}

/* myStrcpy1: my implement of standard lib function strcpy, version 1 */
void myStrcpy1(char *dest, char *sour)
{
    while ((*dest = *sour) != '\0') {
        dest++;
        sour++;
    }
}

/* myStrcpy2: my implement of standard lib function strcpy, version 2 */
void myStrcpy2(char *dest, char *sour)
{
    while ((*dest++ = *sour++) != '\0')
        ;
}

/* myStrcpy3: my implement of standard lib function strcpy, version 3 */
void myStrcpy3(char *dest, char *sour)
{
    while (*dest++ = *sour++)
        ;
}

/* myStrcmpA: my implement of standard lib function strcmp, array version */
int myStrcmpA(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;

    return s[i] - t[i];
}

/* myStrcmpP: my implement of standard lib function strcmp, pointer version */
int myStrcmpP(char *s, char *t)
{
    //while (*s++ == *t++)
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;

    return *s - *t;
}

/* printPricision: test pricision of 'printf' */
void printPricision()
{
    int i;
    float f;
    char *s = "Hello, World";

    i = 777;
    f = 555.555;

    printf("%10.4d\n", i);
    printf("%10.2f\n", f);
    printf("%10.10s\n", s);
}

/* test constant */
void testConstant()
{
    printf("%-13s%-13s%-13s%-13s%-13s\n", NUMBER, DECIMAL, OCTAL, HEXADECIMAL, CHARACTER);
    printf("%-13d%-13d0%-12o0x%-11x8%-13c\n", INTEGERDECIMAL, INTEGERDECIMAL, INTEGERDECIMAL, INTEGERDECIMAL, INTEGERDECIMAL);
    printf("0%-12o%-13d0%-12o0x%-11x%-13c\n", INTEGEROCTAL, INTEGEROCTAL, INTEGEROCTAL, INTEGEROCTAL, INTEGEROCTAL);
    printf("0x%-11x%-13d0%-12o0x%-11x%-13c\n", INTEGERHEX, INTEGERHEX, INTEGERHEX, INTEGERHEX, INTEGERHEX);
}

/* test bell('\a')*/
void testBell()
{
    int i;

    for (i = 0; i < 5; i++)
        if (i%2)
            printf("%c", BELL);
        else
            printf("no bell\n");
}

/* bell */
void bell()
{
    printf("%c", BELL);
}

/* test enum */
void testEnum()
{
    printf("%-13s%-13s\n", "MONTH", "VALUE");
    printf("%-13s%-13d\n", "JAN", JAN);
    printf("%-13s%-13d\n", "FEB", FEB);
    printf("%-13s%-13d\n", "MAR", MAR);
    printf("%-13s%-13d\n", "APR", APR);
    printf("%-13s%-13d\n", "MAY", MAY);
}

/* test const variable */
void testConst()
{
    //const int c = 77;
    int c = 77;

    c = c - 7;
    printf("77 - 7 = %d\n", c);
}

/* test type conversion */
void testConversion()
{
    long int i;
    unsigned int ui;
    unsigned long int uli;

    i = -1;
    ui = 1;
    uli = 1;
    
    printf("-1L < 1 is %s\n", i < ui ? "True" : "False");
    printf("-1L > 1UL is %s\n", i > uli ? "True" : "False");
}

/* test pseudo-random number generator */
void testRandom()
{
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%-7d\n", rand());
        if (!((i+1)%5))
            printf("\n");
    }

}

/* test increment and decrement operator */
void testIncrementAndDecrementOperator()
{
    int n;

    scanf("%d", &n);
    printf("n++:%3d    --n:%3d    ++n:%3d\n", n++, --n, ++n);
}

/* squeeze:  delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* mygetline: get a line from standard input */
int mygetline(char s[], int len)
{
    int c, i;

    for (i=0; i<len-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

/* myStrcat: concatenate t to end of s; s must be big enough */
void myStrcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]))
        ;
}

/* test bitwise operators */
void testBitwiseOperators()
{
    int x;

    x = 0x62;
    printf("x = 0x62, x & ~03 = 0x%x\n", x & ~003);
}

/* getbits:  get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n) & ~(~0 << n));
}

/* formatPrint_1: print n elements of an array, 
 * 10 per line, with each column separated by
 * one blank, and with each line (including 
 * the last) terminated by a newline */
void formatPrint_1(int a[], unsigned n)
{
    int i;

    for (i = 0; i < n; ++i)
        printf("%6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
}

/* formatPrint_2: print format output */
void formatPrint_2(unsigned n)
{
    printf("You have %d item%s\n", n, (n == 1) ? "" : "s");
}

/* precedence: test the precedence of c */
void precedence()
{
    int n, x, i;
    int a[5] = {1, 2, 3, 4, 5};

    n = 3;

    x = n++ + --n;    /* x = 3 + 3 */

    printf("x: %d\n", x);
    printf("%d %d\n", ++n, (int)n*n);    /* n*n evaluated first, ++n last */

    for (i = 0; i < 5; ++i) {
        a[i] = i++;
        printf("%d  %d\n", a[i], i);
    
}
