//
// Created by Luca on 1/25/22.
//

#include "Mixer.hpp"

void Mixer::plugMixer() {
    this->_plugged = true;
}

int Mixer::mix(FruitBox &fruits) const {
    FruitNode *node = fruits.head();
    int vitamins = 0;

    while (node && node->next) {
        if (node->_fruit != nullptr)
            vitamins += node->_fruit->getVitamins();
        node = node->next;
    }
    return vitamins;
}
