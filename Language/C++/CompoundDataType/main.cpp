#include "main.h"

int main()
{
    int choose (-1);
    std::string mystr;

    while (choose) {
        printMenu();
        getline(std::cin, mystr);
        std::stringstream(mystr) >> choose;

        switch (choose) {
            case ARRAYS:
                arrays::arraysCall();
                break;

            case POINTERS:
                pointers::pointersCall();
                break;

            case STRUCTURES:
                structures::structuresCall();
                break;

            case QUIT:
                std::cout << "Get 0, Quit!\n";
                break;

            default:
                std::cout << "Invalid Input!\n";
                break;
        }
    }

    return 0;
}

void printMenu()
{
    std::cout << '\n';
    std::cout << "Main:\n";
    std::cout << "  1 ARRAYS\n";
    std::cout << "  2 POINTERS\n";
    std::cout << "  3 STRUCTURES\n";
    std::cout << "  0 QUIT\n";
    std::cout << "  Input: ";
}
