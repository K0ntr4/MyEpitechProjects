//
// Created by Luca on 1/25/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_FRUITNODE_HPP
#define B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_FRUITNODE_HPP

#include "Fruit.hpp"

class FruitNode
{
public:
    FruitNode *prev;
    FruitNode *next;
    Fruit *_fruit;
    explicit FruitNode(Fruit *fruit = nullptr) { this->_fruit = fruit; this->next = nullptr; this->prev =
    nullptr; };
};

#endif //B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_FRUITNODE_HPP
