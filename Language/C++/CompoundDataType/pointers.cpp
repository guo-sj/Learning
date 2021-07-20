#include "pointers.h"

namespace pointers
{
    std::string mystr;

    enum POINTER {DECLARING_POINTERS = 1, POINTERS_AND_ARRAYS,\
        MY_ARRAY_COPY_CALL, IP_ALL_CALL, CONST_POINTERS, \
        INCREACER_CALL, NULLPTR_CALL, FUNCTION_POINTERS, \
        NEW_AND_DELETE, QUIT = 0};
}

/* pointersCall:  call all pointers functions */
void pointers::pointersCall()
{
    int choose (-1);

    while (choose) {
        printPointersMenu();
        getline(std::cin, mystr);
        std::stringstream(mystr) >> choose;

        switch (choose) {
            case DECLARING_POINTERS:
                declaringPointers();
                break;

            case POINTERS_AND_ARRAYS:
                pointersAndArrays();
                break;

            case MY_ARRAY_COPY_CALL:
                myArrayCopyCall();
                break;

            case IP_ALL_CALL:
                ipAllCall();
                break;

            case CONST_POINTERS:
                constPointers();
                break;

            case INCREACER_CALL:
                increaserCall();
                break;

            case NULLPTR_CALL:
                nullptrCall();
                break;

            case FUNCTION_POINTERS:
                functionPointers();
                break;

            case NEW_AND_DELETE:
                newAndDelete();
                break;

            case QUIT:
                std::cout << "Get 0, Quit!\n";
                break;

            default:
                std::cout << "Invalid Input!\n";
                break;
        }
    }
    ;
}

/* printPointersMenu:  print pointers menu */
void pointers::printPointersMenu()
{
    std::cout << '\n';
    std::cout << "Pointers:\n";
    std::cout << "  1 DECLARING_POINTERS\n";
    std::cout << "  2 POINTERS_AND_ARRAYS\n";
    std::cout << "  3 MY_ARRAY_COPY_CALL\n";
    std::cout << "  4 IP_ALL_CALL\n";
    std::cout << "  5 CONST_POINTERS\n";
    std::cout << "  6 INCREACER_CALL\n";
    std::cout << "  7 NULLPTR_CALL\n";
    std::cout << "  8 FUNCTION_POINTERS\n";
    std::cout << "  9 NEW_AND_DELETE\n";
    std::cout << "  0 QUIT\n";
    std::cout << "  Input: ";
}

/* declaringPointers:  practice of declaring pointers */
void pointers::declaringPointers()
{
    int firstvalue(5), secondvalue(15);
    int *p1, *p2;

    p1 = &firstvalue;
    p2 = &secondvalue;
    *p1 = 10;
    *p2 = *p1;    /* secondvalue == 10 */
    p1 = p2;
    *p1 = 20;    /* secondvalue == 20 */

    std::cout << "firstvalue is " << firstvalue << '\n';
    std::cout << "secondvalue is " << secondvalue << '\n';
}

/* pointersAndArrays:  practice of pointers and arrays */
void pointers::pointersAndArrays()
{
    int numbers[5];
    int *p;
    int i;

    p = numbers;
    //numbers = p;    /* arrays cannot be assigned new address */
    //*p++ = 10;    /* numbers[0] == 10 */
    *++p = 10;
    //p++;
    *p = 20;    /* numbers[1] == 20 */
    p = &numbers[2];
    *p = 30;    /* numbers[2] == 30 */
    p = numbers + 3;
    *p = 40;    /* numbers[3] == 40 */
    p = numbers;
    *(p+4) = 50;    /* numbers[4] == 50 */

    for (i = 0; i < 5; ++i)
        std::cout << *(p+i) << ", ";

    std::cout << '\n';
}

/* myArrayCopy:  copy array s to t 
 * NOTE:  type 'char' only and for template practice */
template <class T> 
void pointers::myArrayCopy(T s[], T t[])
{
    while (*t++ = *s++)    /* postfix operator has higher precedence than prefix one */
        ;
}

/* myArrayCopyCall: call myArrayCopy */
void pointers::myArrayCopyCall()
{
    char s[] = "THIS IS S\n";
    char t[MAXLEN];
    int i;

    myArrayCopy<char>(s, t);

    for (i = 0; t[i] != '\n'; ++i)
        std::cout << t[i];
    std::cout << "'s COPY\n";
}

/* ipAllCall:  call incrementAll and printAll */
void pointers::ipAllCall()
{
    int a[] = {10, 20, 30};
    const char *p = "Hello";

    incrementAll<int>(a, a+3);
    printAll<int>(a, a+3);

    printAll<char>(p, p+5);
}

/* incrementAll:  increment element from 'start' to 'stop' */
template <class T>
void pointers::incrementAll(T *start, T *stop)
{
    while (start != stop) {
        ++*start;
        ++start;
    }
}

/* printAll:  print element from 'start' to 'stop' */
template <class T>
void pointers::printAll
(const T *start, const T *stop)    /* const pointer to non-const T */
{
    while (start != stop)
        std::cout << *start++ << '\n';
}

/* constPointer:  some practice of const pointers */
void pointers::constPointers()
{
    int x(0);
    int *p1 = &x;    /* non-const pointer to non-const int */
    const int *p2 = &x;    /* non-const pointer to const int */
    int const *p5 = &x;    /* also non-const pointer to const int */
    int * const p3 = &x;    /* const pointer to non-const int */
    const int * const p4 = &x;    /* const pointer to const int */
}

/* increaserCall:  call increaser */
void pointers::increaserCall()
{
    char a;
    int b;

    a = 'x';
    b = 1602;
    increaser(&a, sizeof(a));
    increaser(&b, sizeof(b));

    std::cout << std::setw(5) << "a" << std::setw(5) << "b" << "\n";
    std::cout << std::setw(5) << a << std::setw(5) << b << '\n';
}

/* increaser:  increase 'data' which type is determined by 'psize' */
void pointers::increaser(void *data, int psize)
{
    switch (psize) {
        case sizeof(char):
            {
                char *pchar;
                pchar = (char *)data;
                ++(*pchar);
            }
            break;

        case sizeof(int):
            {
                int *pint;
                pint = (int *)data;
                ++(*pint);
            }
            break;

        default:
            std::cout << "Invalid data type!\n";
            break;
    }
}

/* nullptrCall:  some practice of null pointer */
void pointers::nullptrCall()
{
    char *p1, *p2;

    p1 = nullptr;
    p2 = 0;

    std::cout << ((p1==p2) ? \
                     "nullptr == 0" : "nullptr != 0");
    std::cout << '\n';
}

/* functionPointers:  some practice of function pointers */
void pointers::functionPointers()
{
    int m, n;
    int i;
    double (*minus)(int, int) = subtraction;    /* function pointers are declared with same syntax
                                                as a regular function declaration, except that 
                                                the name of the function is enclosed between '()'
                                                and an '*' is inserted before the name */
    double (*asmd[])(int, int) = {    /* function pointers arrays */
        addition,
        subtraction,
        multiply,
        division,    /* trailing comma */
    };

    for (i = 0; i < 4; ++i)
        std::cout << operation(4, 8, asmd[i]) << '\n';
}

/* operation:  perform a operation */
double pointers::operation(int x, int y, double (*functocall)(int, int))
{
    return functocall(x, y);
}

/* addition:  return a+b */
double pointers::addition(int a, int b)
{
    return (double)(a+b);
}

/* subtraction: return a-b */
double pointers::subtraction(int a, int b)
{
    return (double)(a-b);
}

/* multiply: return a*b */
double pointers::multiply(int a, int b)
{
    return (double)(a*b);
}

/* division: return a/b */
double pointers::division(int a, int b)
{
    return (double)(a/b);
}

/* newAndDelete:  some practice of new and delete operators */
void pointers::newAndDelete()
{
    long int n, i;
    int *p;
    std::string mystr;

    std::cout << "How many numbers would you like to type? ";
    getline(std::cin, mystr);
    std::stringstream(mystr) >> n;

    //int a[n];    /* array could dynamic alloc as well */
    //p = a;
    p = new (std::nothrow) int[n];
    if (!p) {
        std::cout << "Error: memory could not be allocated\n";
        return ;
    }

    std::cout << "Input " << n << " number, delimited by newline:\n";
    for (i = 0; i < n; ++i) {
        getline(std::cin, mystr);
        std::stringstream(mystr) >> p[i];
    }

    std::cout << "You have entered: \n";
    for (i = 0; i < n; ++i)
        std::cout << std::setw(5) << \
            p[i] << ((i%3==2 || i==n-1) ? "\n" : "");
    delete[] p;
}
