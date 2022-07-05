//
// Created by Luca on 1/25/22.
//

#include "FruitBox.hpp"
#include "../ex01/FruitBox.hpp"

int FruitBox::nbFruits() const {
    FruitNode *n = this->head();
    int i = 0;

    while (n && n->next) {
        if (n->_fruit != nullptr)
            i++;
        n = n->next;
    }
    if (n->_fruit != nullptr)
        i++;
    return i;
}

FruitNode *FruitBox::head() const {
    FruitNode *n = this->node;
    while (n && n->prev)
        n = n->prev;
    return n;
}

bool FruitBox::putFruit(Fruit *f) {
    FruitNode *n = this->head();
    FruitNode *cpy = this->head();

    if (n == nullptr)
        return false;
    while (cpy->next) {
        if (cpy->_fruit == f)
            return false;
        cpy = cpy->next;
    }
    while (n->next) {
        if (n->_fruit == nullptr) {
            n->_fruit = f;
            return true;
        }
        n = n->next;
    }
    if (n->_fruit != nullptr)
        return false;
    n->_fruit = f;
    return true;
}

FruitBox::FruitBox(int size) {
    this->node = new FruitNode(nullptr);
    for (int i = 0; i < size - 1; i++) {
        this->node->next = new FruitNode(nullptr);
        this->node->next->prev = this->node;
        this->node = this->node->next;
    }
    this->node = this->head();
}

Fruit *FruitBox::pickFruit() {
    FruitNode *n = this->head();
    Fruit *fruit = nullptr;

    if (n->_fruit != nullptr) {
        fruit = n->_fruit;
        n->_fruit = nullptr;
        return fruit;
    }
    while (n) {
        if (n->_fruit != nullptr) {
            fruit = n->_fruit;
            n->_fruit = nullptr;
            return fruit;
        }
        n = n->next;
    }
    return nullptr;
}

int FruitBox::getSize() {
    FruitNode *n = this->head();
    int i = 0;

    while (n && n->next) {
        n = n->next;
        i++;
    }
    return i;
}

FruitNode *FruitBox::getNode() {
    return this->node;
}
