//
// Created by Luca on 1/25/22.
//

#include "LittleHand.hpp"

int getArrLength(const Coconut *const *coconuts) {
    int i = 0;

    while (coconuts[i]) {
        i++;
    }
    return i - 1;
}

void split(FruitNode *node, FruitBox &lemons, FruitBox &bananas, FruitBox &limes) {
    Lemon *lemon = dynamic_cast<Lemon *>(node->_fruit);
    Banana *banana = dynamic_cast<Banana *>(node->_fruit);
    Lime *lime = dynamic_cast<Lime *>(node->_fruit);
    if (lemon) {
        lemons.putFruit(node->_fruit);
        node->_fruit = nullptr;
    } else if (banana) {
        bananas.putFruit(node->_fruit);
        node->_fruit = nullptr;
    } else if (lime) {
        limes.putFruit(node->_fruit);
        node->_fruit = nullptr;
    } else {
        ;
    }
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes) {
    FruitNode *node = unsorted.getNode();

    while (node && node->next) {
        split (node, lemons, bananas, limes);
        node = node->next;
    }
    split (node, lemons, bananas, limes);
}

FruitBox *const *LittleHand::organizeCoconut(const Coconut *const *coconuts) {
    int n = getArrLength(coconuts);
    int j = 0;
    FruitBox **boxes = new FruitBox *[n/6 + 1];

    for (int i = 0; i <= n/6; i++) {
        boxes[i] = new FruitBox(6);
        while (coconuts[j] && j < (i + 1) * 6) {
            boxes[i]->putFruit((Fruit *) coconuts[j]);
            j++;
        }
    }
    boxes[n/6 + 1] = nullptr;
    return boxes;
}
