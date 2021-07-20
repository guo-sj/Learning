#include "structures.h"

namespace structures
{
    std::string mystr;
    enum STRUCTURE {DATA_STRUCTURES = 1, QUIT = 0};
}

/* structuresCall:  call all structures functions */
void structures::structuresCall()
{
    int choose (-1);

    while (choose) {
        printStructuresMenu();
        getline(std::cin, mystr);
        std::stringstream(mystr) >> choose;

        switch (choose) {
            case DATA_STRUCTURES:
                dataStructure();
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

/* printStructuresMenu:  print structures menu */
void structures::printStructuresMenu()
{
    std::cout << '\n';
    std::cout << "Structures:\n";
    std::cout << "  1 DATA_STRUCTURES\n";
    std::cout << "  0 QUIT\n";
    std::cout << "  Input: ";
}

/* dataStructure:  practice of structures */
void structures::dataStructure()
{
    ;
}
