#include <iostream>
#include <string>
#include <sstream>    /* for std::stringstream */
#include <iomanip>    /* for std::setw */
#include <new>        /* for std::new and std::delete */

#define MAXLEN 100

namespace pointers
{
    void pointersCall();
    void printPointersMenu();
    void declaringPointers();
    void pointersAndArrays();
    template <class T>
        void myArrayCopy(T s[], T t[]);
    void myArrayCopyCall();
    void ipAllCall();
    template <class T>
        void printAll(const T *start, const T *stop);
    template <class T>
        void incrementAll(T *start, T *stop);
    void constPointers();
    void increaser(void *data, int psize);
    void increaserCall();
    void nullptrCall();
    void functionPointers();
    double addition(int a, int b);
    double subtraction(int a, int b);
    double multiply(int a, int b);
    double division(int a, int b);
    double operation(int x, int y, double (*functocall)(int, int));
    void newAndDelete();
}
