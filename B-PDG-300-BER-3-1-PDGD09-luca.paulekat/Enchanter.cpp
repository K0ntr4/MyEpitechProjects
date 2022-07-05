#include "Enchanter.hpp"

Enchanter::~Enchanter() {
    std::cout << this->name << " closes his spellbook." << std::endl;
}

int Enchanter::attack () {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->getPower() < 0) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    }
    this->power -= 0;
    std::cout << this->name <<  " doesn\'t know how to fight." << std::endl;
    return 0;
}

int Enchanter::special () {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->power < 50) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    }
    this->power -= 50;
    std::cout << this->name <<  " casts a fireball." << std::endl;
    return 99;
}

void Enchanter::rest() {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return;
    }
    std::cout << this->name <<  " meditates." << std::endl;
    this->power = 100;
}
