#include <iostream>
#include "Fruit.hpp"
#include "Lemon.hpp"
#include "Banana.hpp"
#include "FruitBox.hpp"

int ex00(void)
{
    Lemon l;
    Banana b;
    std::cout << l.getVitamins () << std::endl;
    std::cout << b.getVitamins () << std::endl;
    std::cout << l.getName () << std::endl;
    std::cout << b.getName () << std::endl;
    Fruit& f = l;
    std::cout << f.getVitamins () << std::endl;
    std::cout << f.getName () << std::endl;
    return 0;
}

int main() {
    FruitBox lemons(5);

    lemons.putFruit(new Banana());
    lemons.putFruit(new Lemon());
    lemons.putFruit(new Lemon());

    std::cout << lemons.pickFruit()->getName() << std::endl;
    std::cout << lemons.pickFruit()->getName() << std::endl;
    std::cout << lemons.pickFruit()->getName() << std::endl;


    return 0;
}
