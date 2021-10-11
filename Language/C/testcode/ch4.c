#include "ch4.h"

enum ch4 {
    FINDPATTERN = 1,
    RUDI_CALCU,
    QUIT = 0,
};

void ch4_call()
{
    int choose;

    choose = -1;
    while (choose) {
        ch4_print_menu();
        scanf("%d", &choose);
        switch (choose) {
            case FINDPATTERN:
                findpattern();
                break;

            case RUDI_CALCU:
                rudi_calcu();
                break;

            default:    /* get 0, quit */
                break;
        }
    }
    return;
}

/* ch4_print_menu:  print ch4's menu */
void ch4_print_menu()
{
    printf("\n");
    printf("  ch4:\n");
    printf("  1 FINDPATTERN\n");
    printf("  2 RUDI_CALCU\n");
    //printf("  3 SHELLSORT\n");
    //printf("  4 REVERSE\n");
    //printf("  5 ITOA\n");
    //printf("  6 TRIM\n");
    printf("  0 QUIT\n");
    printf("  Input: ");
}

/* findpattern:  find all lines matching pattern */
int findpattern()
{
    char line[MAX];
    char pattern[] = "ould";
    int found = 0;

    while (mygetline(line, MAX) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            ++found;
        }

    return found;
}

/* strindex:  return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; ++i) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; ++j, ++k)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}

/* mygetline:  get line to s, return length */
int mygetline(char s[], int len)
{
    int c, i;

    i = 0;
    while (--len > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

/* myatof:  convert string s to double, my version */
double myatof(char s[])
{
    int i, sign;
    double val, power;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i]=='-' || s[i]=='+')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        ++i;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

/* rudi_calcu:  rudimentary calculator */
int rudi_calcu()
{
    double sum, myatof(char []);    /* declare the func myatof() */
    char line[MAX];
    int mygetline(char line[], int len);

    sum = 0;
    while (mygetline(line, MAX) > 0)
        printf("\t%g\n", sum += myatof(line));
    return 0;
}
