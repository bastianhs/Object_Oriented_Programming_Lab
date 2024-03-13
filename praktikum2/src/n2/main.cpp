#include "Invoker.hpp"
#include "Axe.hpp"

int main()
{
    Invoker inv1 = Invoker(10, 1000);
    inv1.useSkill();

    Hero *inv2_as_hero = new Invoker(inv1);

    inv2_as_hero->heal(1);

    Invoker *inv3 = new Invoker(50, 200);
    inv3->move(10, 25);

    *inv3 = inv1;

    Axe *axe1 = new Axe(200, 10);
    axe1->move(2, 20);
    axe1->heal(10);

    Axe *axe2 = new Axe(*axe1);

    Axe axe3 = *axe1 + *axe2;

    axe1->useSkill();
    axe3.useSkill();

    delete axe1;

    return 0;
}
