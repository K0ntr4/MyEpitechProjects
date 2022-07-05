//
// Created by Luca on 1/25/22.
//

#include "LittleHand.hpp"

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
