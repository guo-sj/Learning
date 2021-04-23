#include <stdio.h>
#include <string.h>
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
