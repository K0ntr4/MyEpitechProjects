#include <iostream>
#include "Fruit.hpp"
#include "Lemon.hpp"
#include "Banana.hpp"
#include "FruitBox.hpp"
#include "LittleHand.hpp"

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

int ex03(void)
{
    FruitBox unsorted(5);
    FruitBox bananas(5);
    FruitBox limes(5);
    FruitBox lemons(5);

    std::cout << unsorted.getSize() << std::endl;
    std::cout << unsorted.nbFruits() << std::endl;

    unsorted.putFruit(new Banana());
    unsorted.putFruit(new Lemon());
    unsorted.putFruit(new Lemon());
    unsorted.putFruit(new Banana());

    std::cout << unsorted.getSize() << std::endl;
    std::cout << unsorted.nbFruits() << std::endl;

    Fruit *f = unsorted.pickFruit();

    std::cout << unsorted.getSize() << std::endl;
    std::cout << unsorted.nbFruits() << std::endl;

    std::cout << f->getName() << " " << f->getVitamins() << std::endl;

    *f = *unsorted.pickFruit();

    std::cout << unsorted.getSize() << std::endl;
    std::cout << unsorted.nbFruits() << std::endl;
    std::cout << f->getName() << " " << f->getVitamins() << std::endl;

    unsorted.putFruit(new Banana());
    unsorted.putFruit(new Lemon());

    LittleHand sorter;

    sorter.sortFruitBox(unsorted, lemons, bananas, limes);

    std::cout << unsorted.getSize() << unsorted.nbFruits() << std::endl;
    std::cout << lemons.getSize() << lemons.nbFruits() << std::endl;
    std::cout << bananas.getSize() << bananas.nbFruits() << std::endl;
    std::cout << limes.getSize() << limes.nbFruits() << std::endl;

    return 0;
}

int main() {
    Coconut const *arr[26] = {
    };
    for (int i = 0; i < 25; i++) {
        arr[i] = new Coconut();
    }
    arr[25] = nullptr;

    FruitBox *const *fbArr = LittleHand::organizeCoconut(arr);

    for (int i = 0; fbArr[i]; i++) {
        std::cout << fbArr[i]->getSize() << " " << fbArr[i]->nbFruits() << std::endl;
    };
}
