#include "SickKoala.hpp"

void SickKoala::poke() {
    std::cout << "Mr." << name << ": Gooeeeeerrk !!" << std::endl;
}

bool SickKoala::takeDrug(std::string str) {
    if (str == "Mars") {
        std::cout << "Mr." << name << ": Mars, and it kreogs!" << std::endl;
        return true;
    } else if (str == "Kinder") {
        std::cout << "Mr." << name << ": There is a toy inside!" << std::endl;
        return true;
    } else {
        std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
        return false;
    }
}

void SickKoala::overDrive(std::string str) {
    str = std::regex_replace (str, std::regex ("Kreog!"),"1337!");
    std::cout << "Mr." << name << ": " << str << std::endl;
}

std::string SickKoala::getName() {
    return name;
}