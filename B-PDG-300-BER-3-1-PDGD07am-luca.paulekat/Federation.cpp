#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std:: string name, short maxWarp) {
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_location = this->_home;

    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::Ship(int length, int width, std:: string name, short maxWarp, int torpedo) {
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_location = this->_home;
    this->_photonTorpedo = torpedo;

    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
    if (this->_photonTorpedo > 0)
        std::cout << "Weapons are set: " << this->_photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship() {
    this->_length = 289;
    this->_width = 132;
    this->_name = "Entreprise";
    this->_maxWarp = 6;
    this->_location = this->_home;

    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
    this->core = core;
}

void Federation::Starfleet::Ship::checkCore() {
    std::string stability;

    if (this->core->_coreReactor->_stability == true)
        stability = "stable";
    else
        stability = "unstable";
    std::cout << "USS " << this->_name << ": The core is " << stability << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain) {
    std::cout << captain->getName() << ": I\'m glad to be the captain of the USS " << this->_name << "." << std::endl;
    this->_captain = captain;
}

bool Federation::Starfleet::Ship::move(int warp , Destination d) {
    if (warp < this->_maxWarp && d != this->_location && this->core->_coreReactor->_stability == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp) {
    if (warp < this->_maxWarp && this->_location != this->_home && this->core->_coreReactor->_stability == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d) {
    if (this->core->_coreReactor->_stability == true && d != this->_location) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move() {
    if (this->core->_coreReactor->_stability == true && this->_location != this->_home) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

int Federation::Starfleet::Ship::getShield () {
    return this->_shield;
}

void Federation::Starfleet::Ship::setShield(int shield) {
    this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo () {
    return this->_photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo) {
    this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target) {
    int torpedoes = 1;

    if (_photonTorpedo - torpedoes <= 0) {
        std::cout << this->_name << ": No enough torpedoes to fire , " << this->_captain->getName() << "!" << std::endl;
        return;
    }
    this->_photonTorpedo -= torpedoes;
    target->_shield -= 50 * torpedoes;
    std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    if (_photonTorpedo <= 0) {
        std::cout << this->_name << ": No more torpedo to fire , " << this->_captain->getName() << "!" << std::endl;
    }
}

void Federation::Starfleet::Ship::fire(int torpedoes , Borg::Ship *target) {
    if (_photonTorpedo - torpedoes <= 0) {
        std::cout << this->_name << ": No enough torpedoes to fire , " << this->_captain->getName() << "!" << std::endl;
        return;
    }
    this->_photonTorpedo -= torpedoes;
    target->_shield -= 50 * torpedoes;
    std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining.";
    if (_photonTorpedo <= 0) {
        std::cout << this->_name << ": No more torpedo to fire , " << this->_captain->getName() << "!" << std::endl;
    }
}

Federation::Ship::Ship(int length, int width, std:: string name) {
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_location = this->_home;

    std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
    std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
    std::cout << this->_name << ": The core is set." << std::endl;
    this->core = core;
}

void Federation::Ship::checkCore() {
    std::string stability;

    if (this->core->_coreReactor->_stability == true)
        stability = "stable";
    else
        stability = "unstable";
    std::cout << this->_name << ": The core is " << stability << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp , Destination d) {
    if (warp < this->_maxWarp && d != this->_location && this->core->_coreReactor->_stability == true) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp) {
    if (warp < this->_maxWarp && this->_location != this->_home && this->core->_coreReactor->_stability == true) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d) {
    if (this->core->_coreReactor->_stability == true && d != this->_location) {
        this->_location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move() {
    if (this->core->_coreReactor->_stability == true && this->_location != this->_home) {
        this->_location = this->_home;
        return true;
    }
    return false;
}

Federation::Starfleet::Captain::Captain(std::string name) {
    this->_name = name;
}

std::string Federation::Starfleet::Captain::getName() {
    return this->_name;
}

int Federation::Starfleet::Captain::getAge() {
    return this->_age;
}

void Federation::Starfleet::Captain::setAge(int age) {
    this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name) {
    std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
    this->_name = name;
}

WarpSystem::Core *Federation::Ship::getCore() {
    return this->core;
}