#include "A.hpp"

int main()
{
    A x('1');
    A y('2');
    A a = x;
    a = y;
    a.show();
    return 0;
}