#include "Knight.hpp"

Knight::~Knight() {
    std::cout << this->name << " takes off his armor." << std::endl;
}

int Knight::attack () {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->power < 10) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    }
    this->power -= 10;
    std::cout << this->name <<  " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special () {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->power < 30) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    }
    this->power -= 30;
    std::cout << this->name <<  " impales his enemy." << std::endl;
    return 50;
}

void Knight::rest() {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return;
    }
    std::cout << this->name <<  " eats." << std::endl;
    if (this->power + 50 <= 100)
        this->power += 50;
    else
        this->power = 100;
}
