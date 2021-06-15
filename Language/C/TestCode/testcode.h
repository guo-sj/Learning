#ifndef _TESTCODE_H
#define _TESTCODE_H

#define FD      "/dev/ttyUSB0"
#define MAXLEN  100

/* return signal */
#define OK      0
#define ERR     1

/* print macro */
#define dprint(var, converchar)  printf(#var ": %"#converchar"\n", var)
#define print(info)              printf(#info "\n")

/* function names */
#define MAIN                1
#define TESTFLOAT           2

/* test constant */
#define INTEGERDECIMAL      '\x7'
#define INTEGEROCTAL        0100
#define INTEGERHEX          0x40
#define NUMBER              "number"
#define DECIMAL             "decimal"
#define OCTAL               "octal"
#define HEXADECIMAL         "hexadecimal"
#define CHARACTER           "character"

/* test bell */
#define BELL                '\x7'

/* test enum */
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, 
    JUL, AUG, SEP, OCT, NOV, DEC } myMonths;
/* function declration */
void printinfo(int funcname);
int testextern();
int testarrayaddr();
int testsprintf();
int testfloat();
int testdouble();
int testTypeCast();
int testStringConstant();
void myStrcpy1(char *dest, char *sour);
void myStrcpy2(char *dest, char *sour);
void myStrcpy3(char *dest, char *sour);
int myStrcmpA(char *s, char *t);
int myStrcmpP(char *s, char *t);
void printPricision();
void testConstant();
void testBell();
void bell();
void testEnum();
void testConst();
void testConversion();

#endif
