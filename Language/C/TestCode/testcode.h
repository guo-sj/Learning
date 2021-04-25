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

#endif
