#include "arrays.h"

namespace arrays
{
    int a[MAXLEN];    /* arrays declared directly in a namespace\
                         are always initialized, in this case (all zero) */
    int len;    /* array's length */

    int b[MAXLEN][5];
    int n;    /* multiArray's length of first dimension */

    std::string mystr;

    enum ARR {GETANDPRINT = 1, SUM, MULTIARRAY, ARRTEMPLATE, CHARARRAY, QUIT = 0};
}

/* arraysCall:  call all arrays functions */
void arrays::arraysCall()
{
    int choose(-1);

    while (choose) {
        printArrayMenu();
        getline(std::cin, mystr);
        std::stringstream(mystr) >> choose;
        switch (choose) {
            case GETANDPRINT:
                arrays::getAndPrint();
                break;

            case SUM:
                arrays::sum();
                break;

            case MULTIARRAY:
                arrays::multiArray();
                break;

            case ARRTEMPLATE:
                arrays::arrayTemplate();
                break;

            case CHARARRAY:
                arrays::charArray();
                break;

            case QUIT:
                std::cout << "Get 0, Quit!\n";
                break;

            default:
                std::cout << "Invalid Input!\n";
                break;
        }
    }
}

/* printArrayMenu:  print namespace array's menu */
void arrays::printArrayMenu()
{
    std::cout << '\n';
    std::cout << "Arrays:\n";
    std::cout << "  1 GETANDPRINT\n";
    std::cout << "  2 SUM\n";
    std::cout << "  3 MULTIARRAY\n";
    std::cout << "  4 ARRTEMPLATE\n";
    std::cout << "  5 CHARARRAY\n";
    std::cout << "  0 QUIT\n";
    std::cout << "  Input: ";
}

/* getAndPrint:  get an array and print it */
void arrays::getAndPrint()
{
    std::cout << "Please input array length: ";
    getline(std::cin, mystr);
    std::stringstream(mystr) >> len;

    std::cout << "Please input array's elements: \n";
    getArrays(a, len);

    std::cout << "You input array:\n";
    printArrays(a, len);
}

/* sum:  test sumArrayElem() */
void arrays::sum()
{
    std::cout << "Please input array length: ";
    getline(std::cin, mystr);
    std::stringstream(mystr) >> len;

    std::cout << "Please input array's elements: \n";
    getArrays(a, len);

    std::cout << "The sum of array's elements: " \
        << sumArrayElem(a, len) << '\n';
}
 
/* printArrays:  print arrays */
void arrays::printArrays(int a[], int n)
{
    int i;

    for (i = 0; i < n; ++i)
        //std::cout << a[i] << (i%3==2 || i==n-1) ? "\n" : " ";
        std::cout << a[i] << " ";

    std::cout << "\n";
}

/* getArrays:  get arrays */
void arrays::getArrays(int a[], int n)
{
    int i;

    for (i = 0; i < n; ++i) {
        getline(std::cin, mystr);
        std::stringstream(mystr) >> a[i];
    }
}

/* sumArrayElem:  return the sum of array's elements */
double arrays::sumArrayElem(int a[], int n)
{
    int i;
    double result(0.0);

    for (i = 0; i < n; ++i)
        result += a[i];

    return result;
}

/* multiArray:  test getMultiArrays() and printMultiArrays() */
void arrays::multiArray()
{
    std::cout << "Please input n: ";
    getline(std::cin, mystr);
    std::stringstream(mystr) >> n;
    std::cout << "Input bidimensional array " << n << "x5:\n";
    getMultiArrays(b, n);

    std::cout << "Output bidimensional array " << n << "x5:\n";
    printMultiArrays(b, n);
}

/* getMultiArrays:  get a n*5 bidimensional array */
void arrays::getMultiArrays(int b[][5], int n)
{
    int i, j;

    for (i = 0; i < n; ++i)
        for (j = 0; j < 5; ++j) {
            getline(std::cin, mystr);
            std::stringstream(mystr) >> b[i][j];
        }
}

/* printMultiArrays:  print n*5 bidimensional array */
void arrays::printMultiArrays(int b[][5], int n)
{
    int i, j;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < 5; ++j)
            std::cout << std::setw(3) << b[i][j] << " ";    /* 'setw(3)'similar to \
                                                               "%3d" in C */
        std::cout << "\n";
    }
}

/* arrayTemplate:  array template input and output */
void arrays::arrayTemplate()
{
    int i;
    std::array<int,3> myarray {10, 20, 30};

    for (i = 0; i < myarray.size(); ++i)
        ++myarray[i];

    for (int elem : myarray)
        std::cout << elem << ' ';

    std::cout << '\n';
}

/* charArray:  character array about strings and NTCS (null-
 * terminated character sequences) */
void arrays::charArray()
{
    /* NTCS */
    char question1[] = "What is your name? ";    /* implicit declaration */
    char answer1[80];    /* explicit declaration */
    char myntcs[] = "some text";

    /* strings */
    std::string question2 = "Where do you live? ";
    std::string answer2;
    std::string mystring = myntcs;

    std::cout << question1;
    std::cin >> answer1;
    std::cout << question2;
    //std::cin >> answer2;
    getline(std::cin, answer2);    /* filter newline */
    getline(std::cin, answer2);

    std::cout << "Hello, " << answer1;
    std::cout << " from " << answer2 << "!\n";

    /* the convertion between c-string and string */
    std::cout << mystring << '\n';    /* printed as a library string */
    std::cout << mystring.c_str() << '\n';    /* printed as a c-string */
}
