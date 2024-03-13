#include "A.hpp"
#include "B.hpp"

int main()
{
    B b;

    // Start editing here :D
    A &b_as_a = b;
    b_as_a.setMe(10);

    b.setMe(200);
    b.print();
    return 0;
}
