#include <string>
#include <iostream>
using namespace std;

/* anonymous namespace */
namespace
{
    void func()
    {
        std::cout << "Hello, I'm anonymous namespace.\n";
    }

    int x;   /* static storge */
}

namespace Test
{
    namespace old_ns
    {
        std::string Func() 
        {
            return std::string("Hello from old");
        }
    }

    inline namespace new_ns    /* the inline keyword must be applied to the first \
                                   declaration of the namespace in a compilation unit */
    {
        std::string Func()
        {
            return std::string("Hello from new");
        }
    }

}

namespace mynamespace
{
    namespace foo
    {
        int value()
        {
            return 5;
        }
    }

    namespace bar
    {
        const double pi (3.1416);

        double value()
        {
            return 2*pi;
        }
    }

    namespace first
    {
        int x(5), y(10);
    }

    namespace second
    {
        double x(3.1416), y(2.7183);
    }

    void mynamespace_call()
    {
        cout << foo::value() << '\n';
        cout << bar::value() << '\n';
        cout << bar::pi << '\n';
        {
            using first::x;
            using second::y;
            cout << x << '\n';
            cout << y << '\n';
            cout << first::y << '\n';
            cout << second::x << '\n';
        }
        {
            using namespace first;
            cout << "x: " << x << "\n";
            cout << "y: " << y << "\n";
        }
        {
            using namespace Test;
            string s = Test::Func();
            std::cout << s << std::endl;    /* Hello from new */
            string t = old_ns::Func();
            std::cout << t << std::endl;    /* Hello from old */
        }
        {
            func();
        }
        {
            int y;    /* automatic storge */
            
            std::cout << "x: " << x << '\n';
            std::cout << "y: " << y << '\n';
        }
    }

}

