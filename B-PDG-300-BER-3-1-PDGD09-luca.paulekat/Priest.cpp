//
// Created by Luca on 1/24/22.
//

#include "Priest.hpp"

Priest::~Priest() {
    std::cout << this->name << " finds peace." << std::endl;
}

void Priest::rest() {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return;
    }
    std::cout << this->name <<  " prays." << std::endl;
    this->power = 100;
    this->health = 100;
}
