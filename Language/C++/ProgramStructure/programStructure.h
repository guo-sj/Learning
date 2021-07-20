#include <string>
#include <iostream>
using namespace std;

enum mainSwitch {IF = 1, LOOP, DUPLICATE, CAT, DIVIDE, ODD, FACTORIAL, \
    OVERLOADS, NAMESPACE, QUIT = 0};
enum printmenuSwitch {MAIN = 0};
enum loopSwitch {WHILE = 1, DO_WHILE, TYPICAL_FOR, RANGE_BASED_FOR, \
    GOTO};
enum overloadsSwitch {TWO_OPERATE = 1, TEMPLATE_SUM, TEMPLATE_ARE_EQUAL, \
    TEMPLATE_FIXED_MULTIPLY};

void printmenu(int c);

namespace if_else
{
    int x(0), y(0);
    string mystr;

    /* if_else */
    void if_else(void)
    {
        cout << "Enter x:";
        getline(cin, mystr);
        stringstream(mystr) >> x;

        cout << "Enter y:";
        getline(cin, mystr);
        stringstream(mystr) >> y;

        if (x >= y) 
            cout << "x >= y\n";
        else
            cout << "x < y\n";
    }
}

namespace loop
{

    /* loop */
    void loop(int c)
    {
        int n(10), i(10), j(10);
        string str;
        switch (c) {
            case WHILE:
                while (n > 0) {
                    cout << n << ", ";
                    --n;
                }
                cout << "liftoff!\n";
                break;

            case DO_WHILE:
                do {
                    cout << "Enter text: ";
                    getline(cin, str);
                    cout << "You enterd: " << str << '\n';
                } while (str != "goodbye");
                break;

            case TYPICAL_FOR:
                for (; i > 0; i--) {
                    /* if (i == 5)
                       continue; */

                    cout << i << ", ";

                    /*if (i == 3) {
                      cout << "Countdown aborted!\n";
                      break;
                      } */
                }
                cout << "liftoff!\n";
                break;

            case RANGE_BASED_FOR:
                cout << "Enter text: ";
                getline(cin, str);
                for (char x : str)
                    //for (auto x : str)
                    cout << "[" << x << "]";
                cout << "\n";
                break;

            case GOTO:
mylabel:
                cout << j << ", ";
                --j;
                if (j > 0) 
                    goto mylabel;
                cout << "liftoff!\n";
                break;

            case QUIT:
                cout << "Get 0, quit.\n";
                break;

            default:
                break;

        }
    }

    void loop_call()
    {
        int c (-1);
        string mystr;
        while (c) {
            printmenu(LOOP);
            getline(cin, mystr);
            stringstream(mystr) >> c;
            loop::loop(c);
        }
    }

}

namespace duplicate
{
    /* duplicate:  duplicates the value, c++ like version */
    void duplicate(int &a, int &b, int &c)
    {
        a *= 2;
        b *= 2;
        c *= 2;
    }

    /* myduplicate:  duplicates the value, c like version */
    void myduplicate(int *a, int *b, int *c)
    {
        *a *= 2;
        *b *= 2;
        *c *= 2;
    }

    void duplicate_call()
    {
        int a(2), b(3), c(4);
        cout << "Before duplicating:\n";
        cout << "a: " << a << ", b: " \
            << b << ", c: " << c << '\n';
        //duplicate(a, b, c);
        myduplicate(&a, &b, &c);
        cout << "After duplicating:\n";
        cout << "a: " << a << ", b: " \
            << b << ", c: " << c << '\n';
    }

}

namespace cat
{
    /* concatenate:  concatenate string
     * Note: add keyword 'const' to provide functionality 
     * similar to passing arguments by value, but with an
     * incresed efficiency for parameters of large type */
    string concatenate(const string &a, const string &b)
    {
        return a+b;
    }

    /* inline function */
    inline string concat(const string &a, const string &b)
    {
        return a+b;
    }

    void cat_call()
    {
        string fir_str, sec_str;
        cout << "Enter first string: ";
        getline(cin, fir_str);
        cout << "Enter second string: ";
        getline(cin, sec_str);
        cout << "Well, their concatenation: " \
            //<< concatenate(fir_str, sec_str);
            << concat(fir_str, sec_str);
        ;
    }

}

namespace divide
{
    int divide(int a = 2, int b = 2);    /* default parameter */
    void divide_call()
    {
        int a(0), b(0);
        string mystr;

        cout << "divide:\n";
        cout << "Enter a:";
        getline(cin, mystr);
        stringstream(mystr) >> a;
        cout << "Enter b:";
        getline(cin, mystr);
        stringstream(mystr) >> b;
        cout << "a and b are default, a/b: " << divide() << '\n';
        //cout << "a is default, a/b: " << divide(a, b) << '\n';
        cout << "b is default, a/b: " << divide(a) << '\n';
        cout << "a and b are not default, a/b: " << divide(a, b) << '\n';
    } 

    /* default parameter */
    int divide(int a, int b)
    {
        int r;

        r = a/b;
        return r;
    }

}

namespace odd_even
{
    void even(int x);
    void odd(int x);

    void odd_even_call()
    {
        int i(0);
        string mystr;

        do {
            cout << "Please, enter number (0 to exit): ";
            getline(cin, mystr);
            stringstream(mystr) >> i;
            odd(i);
        } while (i != 0);
    }

    /* odd: varify odd number */
    void odd(int x)
    {
        if ((x%2) != 0)
            cout << "It is odd.\n";
        else
            even(x);
    }

    /* even: varify even number */
    void even(int x)
    {
        if ((x%2) == 0)
            cout << "It is even.\n";
        else
            odd(x);
    }

}

namespace factorial
{
    double factorial_r(long a);
    double factorial_l(long a);

    void factorial_call()
    {
        long a(0);
        string mystr;

        do {
            cout << "Please, enter number (0 to exit): ";
            getline(cin, mystr);
            stringstream(mystr) >> a;
            cout << "factorial_r:  " << a << "! = " << factorial_r(a) << "\n";
            cout << "factorial_l:  " << a << "! = " << factorial_l(a) << "\n";
        } while (a != 0);
    }

    /* factorial_r:  recursivity version */
    double factorial_r(long a)
    {
        if (a > 1)
            return a * factorial_r(a-1);
        else
            return 1;
    }

    /* factorial_l:  loop version */
    double factorial_l(long a)
    {
        double i;

        for (i = 1; a > 1; --a)
            i *= a;

        return i;
    }

}

namespace overloads
{
    void function_overloads(int c);
    int operate(int a, int b);
    double operate(double a, double b);
    template <class T> T sum(T a, T b);
    template <class T, class U> bool are_equal(T a, U b);
    template <typename T, int N> T fixed_multiply(T val);

    void overloads_call()
    {
        int c(-1);
        string mystr;

        while (c) {
            printmenu(OVERLOADS);
            getline(cin, mystr);
            stringstream(mystr) >> c;
            function_overloads(c);
        }
    }

    /* ------------------------function-overloads------------------------ */
    void function_overloads(int c)
    {
        int a, b, k;
        double f, g, h;
        string mystr;

        switch (c) {
            case TWO_OPERATE:
                cout << "Enter a, b: ";
                getline(cin, mystr);
                stringstream(mystr) >> a >> b;
                cout << "operate of int: " << operate(a, b) << '\n';
                cout << "operate of double: " << operate((double)a, (double)b) << '\n';
                break;

            case TEMPLATE_SUM:
                cout << "Enter a, b (int): ";
                getline(cin, mystr);
                stringstream(mystr) >> a >> b;
                k = sum<int>(a, b);
                //k = sum(a, b);
                cout << "a + b: " << k << '\n';

                cout << "Enter f, g (double): ";
                getline(cin, mystr);
                stringstream(mystr) >> f >> g;
                h = sum<double>(f, g);
                cout << "f + g: " << h << '\n';

                cout << sum<string>("hello, ", "world!\n");    /* compound data type \
                                                                  can overloads as well */
                break;

            case TEMPLATE_ARE_EQUAL:
                //cout << are_equal(20, 10.0) << '\n';
                cout << are_equal<int, double>(20, 10.0) << '\n';
                break;

            case TEMPLATE_FIXED_MULTIPLY:
                cout << fixed_multiply<int, 3>(10) << '\n';
                break;

            case QUIT:
                cout << "Get 0, quit.\n";
                break;

            default:
                break;
        }
    }

    int operate(int a, int b)
    {
        return a+b;
    }

    double operate(double a, double b)
    {
        return a/b;
    }

    template <class T>
        T sum(T a, T b)
        {
            T result;
            result = a + b;

            return result;
        }

    template <class T, class U>
        bool are_equal(T a, U b)
        {
            return a==b;
        }

    template <typename T, int N>
        T fixed_multiply(T val)
        {
            return N * val;
        }
    /* ------------------------function-overloads------------------------ */
}

