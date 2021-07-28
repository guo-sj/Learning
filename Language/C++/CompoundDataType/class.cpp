#include "class.h"

namespace myClass {
    class Rectangle {
        int width, height;    /* default private */

        public:
        Rectangle();    /* the default constructor */
        Rectangle(int, int);    /* constructor */
        int area(void)
        {
            return width * height;
        }
    };
}

/* Rectangle:  the default constructor */
myClass::Rectangle::Rectangle()
{
    width = 5;
    height = 5;
}

/* Rectangle:  constructor without return types, even a void */
myClass::Rectangle::Rectangle(int x, int y)
{
    width = x;
    height = y;
}

void myClass::callRectangleFunction()
{
    Rectangle rect(3, 4);    /* Rectangle is a type, which maybe 
                          the most important property of a class */
    //Rectangle rectb(5, 6);
    Rectangle rectb;    /* the default constructor called 
                           without an empty set of parentheses */

    std::cout << "rect's area: " << rect.area() << "\n";

    std::cout << "rectb's area: " << rectb.area() << "\n";

}


