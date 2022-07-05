#include "Paladin.hpp"

Paladin::~Paladin() {
    std::cout << this->name << " is blessed." << std::endl;
}

int Paladin::attack() {
    return Knight::attack();
}

int Paladin::special() {
    return Enchanter::special();
}

void Paladin::rest() {
    Priest::rest();
}
