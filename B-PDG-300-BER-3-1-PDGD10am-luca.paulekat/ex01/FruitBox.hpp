//
// Created by Luca on 1/25/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_FRUITBOX_HPP
#define B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_FRUITBOX_HPP

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
private:
    FruitNode *node;
public:
    FruitNode *getNode();
    int nbFruits() const;
    FruitNode *head() const;
    bool putFruit(Fruit *f);
    explicit FruitBox(int size);
    Fruit *pickFruit();
    int getSize();
};

#endif //B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_FRUITBOX_HPP
