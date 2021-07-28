#include "class.h"

namespace myClass {
    class Rectangle {
        int width, height;    /* default private */

        public:
        Rectangle();    /* the default constructor */
        Rectangle(int, int);    /* constructor */
        int area(void)   /* function seen as an inline function */
        {
            return width * height;
        }
    };

    class Circle {
        double radius;
        const double pi = 3.14159265;

        public:
        Circle(double r) : radius(r) {}    /* member initialization */
        Circle()    /* default constructor */
        {
            radius = 3;
        }

        double circum()    /* calculate circum */
        {
            return 2*radius*pi;
        }

        double area()    /* calculate area */
        {
            return (radius * radius * pi);
        }
    };

    class Cylinder {
        Circle base;
        double height;

        public:
        Cylinder(double r, double h) : base(r), height(h) {}    /* member initialization */
        double volume()    /* calculate volume */
        {
            return base.area() * height;
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

/* callRectangleFunction:  test class Rectangle's functions */
void myClass::callRectangleFunction()
{
    Rectangle rect(3, 4);    /* Rectangle is a type, which maybe 
                          the most important property of a class */
    //Rectangle rectb(5, 6);
    Rectangle rectb;    /* the default constructor called 
                           without an empty set of parentheses */

    Rectangle rectc {};    /* uniform init */
    std::cout << "rect's area: " << rect.area() << "\n";

    std::cout << "rectb's area: " << rectb.area() << "\n";
    std::cout << "rectc's area: " << rectc.area() << "\n";

}

/* callCircleFunction:  test class Circle's function */
void myClass::callCircleFunction()
{
    Circle foo (10.0);    /* functional form */
    Circle bar = 20.0;    /* assignment init */
    Circle baz {30.0};    /* uniform init */
    Circle qux = {40.0};    /* POD-like */

    std::cout << "foo's circumference: " << foo.circum() << std::endl;
}

void myClass::callCylinderFunction()
{
    Cylinder foo (10, 20);

    std::cout << "foo's volume: " << foo.volume() << '\n';
}
