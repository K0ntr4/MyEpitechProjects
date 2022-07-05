#include "Borg.hpp"
#include "Federation.hpp"

Borg::Ship::Ship() {
    this->_location = this->_home;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int weaponFrequency) {
    this->_location = this->_home;
    this->_weaponFrequency = weaponFrequency;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int weaponFrequency, short repair) {
    this->_location = this->_home;
    this->_weaponFrequency = weaponFrequency;
    this->_repair = repair;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

void Borg::Ship::setupCore(WarpSystem::Core *core) {
    this->core = core;
}

void Borg::Ship::checkCore() {
    std::string stability;

    if (this->core->_coreReactor->_stability == true)
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;
}

bool Borg::Ship::move(int warp , Destination d) {
    if (warp < this->_maxWarp && d != this->_location && this->core->_coreReactor->_stability == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move(int warp) {
    if (warp < this->_maxWarp && this->_location != this->_home && this->core->_coreReactor->_stability == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

bool Borg::Ship::move(Destination d) {
    if (this->core->_coreReactor->_stability == true && d != this->_location) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Borg::Ship::move() {
    if (this->core->_coreReactor->_stability == true && this->_location != this->_home) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

int Borg::Ship::getShield () {
    return this->_shield;
}

void Borg::Ship::setShield(int shield) {
    this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency () {
    return this->_weaponFrequency;
}

void Borg::Ship::setWeaponFrequency(int frequency) {
    this->_weaponFrequency = frequency;
}

short Borg::Ship::getRepair () {
    return this->_repair;
}

void Borg::Ship::setRepair(short repair) {
    this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target) {
    target->_shield -= this->_weaponFrequency;
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target) {
    WarpSystem::Core *core = target->getCore();

    core->_coreReactor->_stability = false;
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair() {
    if (this->_repair <= 0) {
        std::cout << "Energy cells depleted , shield weakening." << std::endl;
        return;
    }
    this->_repair -= 1;
    this->_shield = 100;
    std::cout << "Begin shield re-initialisation ... Done. Awaiting further instructions." << std::endl;

}