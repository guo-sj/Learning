#include "array/basicOperation.h"

enum main {
    ARRAY = 1,
};

void print_main_menu();

int main()
{
    int choose;

    choose = -1;
    while (choose) {
        print_main_menu();
        scanf("%d", &choose);

        switch (choose) {
            case ARRAY:
                call_array_operation();
                break;

            default:
                break;
        }
    }
}

void print_main_menu()
{
    printf("\n");
    printf("main menu:\n");
    printf("1 ARRAY\n");
    printf("0 QUIT\n");
    printf("Input: ");
}
