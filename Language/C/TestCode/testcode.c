#include <stdio.h>
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
