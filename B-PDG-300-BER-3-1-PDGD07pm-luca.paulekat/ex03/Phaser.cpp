#include "Phaser.hpp"

Phaser::Phaser(int maxAmmo, AmmoType type) {
    this->_maxAmmo = maxAmmo;
    this->_defaultType = type;
    std::vector <AmmoType> mag = {type};

    for (int i = 0; i < maxAmmo; i++) {
        mag.push_back(type);
    }
    this->_mag = mag;
}

Phaser::~Phaser() = default;

void Phaser::fire() {
    if (this->_mag.size() == 1) {
        std::cout << "Clip empty, please reload" << std::endl;
        return;
    }
    if (this->_mag[0] == REGULAR)
        std::cout << this->sounds->Regular << std::endl;
    if (this->_mag[0] == PLASMA)
        std::cout << this->sounds->Plasma << std::endl;
    if (this->_mag[0] == ROCKET)
        std::cout << this->sounds->Rocket << std::endl;
    this->_mag.erase(this->_mag.begin());
}

void Phaser::ejectClip () {
    this->_mag.clear();
}

void Phaser::changeType(AmmoType newType) {
    std::string type = "regular";

    if (newType == PLASMA)
        type = "plasma";
    if (newType == ROCKET)
        type = "rocket";
    std::cout << "Switching ammo to type: " << type << std::endl;
    this->_defaultType = newType;
}

void Phaser::reload () {
    for (unsigned int i = 0; i <= this->_maxAmmo; i++) {
        this->_mag[i] = this->_defaultType;
    }
    std::cout << "Reloading ..." << std::endl;
}

void Phaser::addAmmo(AmmoType type) {
    if (this->_mag.size() == this->_maxAmmo) {
        std::cout << "Clip full" << std::endl;
        return;
    }
    this->_mag.push_back(type);
}

int Phaser::getCurrentAmmos() {
    return this->_mag.size();
}