/* The code of chapter Program Structure */
#include <iostream>
#include <string>
#include <sstream>    /* for stringstream */
#include <cstdlib>    /* for EXIT_SUCCESS and EXIT_FAILURE */
#include "programStructure.h"
#include "header.h"

using namespace std;

int main()
{
    int choose (-1);
    string mystr;

    while (choose) {
        printmenu(MAIN);
        getline(cin, mystr);
        stringstream(mystr) >> choose;

        switch (choose) {
            case IF:
                if_else::if_else();
                break;

            case LOOP:
                loop::loop_call();
                break;

            case DUPLICATE:
                duplicate::duplicate_call();
                break;

            case CAT:
                cat::cat_call();
                break;

            case DIVIDE:
                divide::divide_call();
                break;

            case ODD:
                odd_even::odd_even_call();
                break;

            case FACTORIAL:
                factorial::factorial_call();
                break;

            case OVERLOADS:
                overloads::overloads_call();
                break;

            case NAMESPACE:
                namespace mns = mynamespace;    /* namespace aliases */
                //mynamespace::mynamespace_call();
                mns::mynamespace_call();
                break;

            case QUIT:
                cout << "Get 0, quit.\n";
                break;

            default:
                break;
        }
    }

    return EXIT_SUCCESS;
}

/* printmenu:  print menu list for functions */
void printmenu(int c)
{
    switch (c) {
        case MAIN:
            cout << "\n";
            cout << "main:\n";
            cout << "  1 if_else \n";
            cout << "  2 loop \n";
            cout << "  3 duplicate \n";
            cout << "  4 concatenate \n";
            cout << "  5 divide \n";
            cout << "  6 odd and even \n";
            cout << "  7 factorial \n";
            cout << "  8 functions overloads \n";
            cout << "  9 namespace \n";
            cout << "  0 quit \n";
            cout << "  Input:";
            break;

        case LOOP:
            cout << "\n";
            cout << "loop:\n";
            cout << "  1 while \n";
            cout << "  2 do_while \n";
            cout << "  3 typical_for \n";
            cout << "  4 range_based_for \n";
            cout << "  5 goto \n";
            cout << "  0 quit \n";
            cout << "  Input:";
            break;

        case OVERLOADS:
            cout << "\n";
            cout << "functions overloads:\n";
            cout << "  1 two_operate \n";
            cout << "  2 template sum \n";
            cout << "  3 template are_equal \n";
            cout << "  4 template fixed_multiply \n";
           /* cout << "  5 goto \n"; */
            cout << "  0 quit \n";
            cout << "  Input:";
            break;

        default:
            cout << "printmenu: Invalid input.\n";
            break;
    }
}

