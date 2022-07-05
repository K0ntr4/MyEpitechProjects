//
// Created by Luca on 1/25/22.
//

#include "Fruit.hpp"

#include <utility>
#include "Lemon.hpp"

int Fruit::getVitamins() const {
    return this->_vitamins;
}

std::string Fruit::getName() const {
    return this->_name;
}
