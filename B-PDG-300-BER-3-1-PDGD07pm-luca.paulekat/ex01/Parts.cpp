#include "Parts.hpp"

Parts::Parts(std::string &serial, bool functional, std::string type) {
    this->_serial = serial;
    this->_functional = functional;
    this->_type = type;
}

bool Parts::isFunctional() const{
    return this->_functional;
}

std::string Parts::serial() const{
    return this->_serial;
}

void Parts::informations() const {
    std::string okay = "KO";

    if (this->_functional == true)
        okay = "OK";
    std::cout << "\t[Parts] "<< this->_type << " " << this->_serial << " status : " << okay << std::endl;
}
