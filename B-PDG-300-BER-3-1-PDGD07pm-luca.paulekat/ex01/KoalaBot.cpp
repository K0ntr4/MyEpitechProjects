#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) {
    this->_serial = serial;
}

KoalaBot::~KoalaBot() = default;

void KoalaBot::setParts(const Arms &part) {
    this->_arms = part;
}

void KoalaBot::setParts(const Legs &part) {
    this->_legs = part;
}

void KoalaBot::setParts(const Head &part) {
    this->_head = part;
}

Arms& KoalaBot::swapParts(const Arms &part) {
    Arms& cpy = this->_arms;
    this->_arms = part;
    return cpy;
}

Legs& KoalaBot::swapParts(const Legs &part) {
    Legs& cpy = this->_legs;
    this->_legs = part;
    return cpy;
}

Head& KoalaBot::swapParts(const Head &part) {
    Head& cpy = this->_head;
    this->_head = part;
    return cpy;
}

void KoalaBot::informations() const {
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status() const {
    if (this->_arms._functional == true && this->_legs._functional == true && this->_head._functional == true)
        return true;
    return false;
}