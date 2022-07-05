#include "Peasant.hpp"

Peasant::Peasant(std::string name, unsigned int power) {
    this->name = name;
    if (power <= 100)
        this->power = power;
    else
        this->power = 100;
    this->health = 100;
    std::cout << this->name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant() {
    std::cout << this->name << " is back to his crops." << std::endl;
}

std::string Peasant::getName() const {
    return std::string(this->name);
}

int Peasant::getPower() const {
    return int(this->power);
}

int Peasant::getHp() const {
    return int(this->health);
}

int Peasant::attack() {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->power < 10) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    }
    this->power -= 10;
    std::cout << this->name <<  " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special() {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return 0;
    }
    if (this->getPower() < 0) {
        std::cout << this->name << " is out of power." << std::endl;
        return 0;
    }
    this->power -= 0;
    std::cout << this->name <<  " doesn\'t know any special move." << std::endl;
    return 0;
}

void Peasant::rest() {
    if (this->health == 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        return;
    }
    std::cout << this->name <<  " takes a nap." << std::endl;
    if (this->power + 30 <= 100)
        this->power += 30;
    else
        this->power = 100;
}

void Peasant::damage(int damage) {
    if (this->getHp() - damage <= 0) {
        std::cout << this->name << " is out of combat." << std::endl;
        this->health = 0;
        return;
    }
    this->health -= damage;
    std::cout << this->name << " takes " << damage << " damage." << std::endl;
}

void Peasant::drink(const IPotion &potion) {
    if (potion.getType() == "health") {
        if (this->health + 50 > 100)
            this->health = 100;
        else
            this->health += 50;
    } else if (potion.getType() == "poison") {
        if (this->getHp() - 50 < 0)
            this->health = 0;
        else
            this->health -= 50;
    } else if (potion.getType() == "power") {
        if (this->power + 50 > 100)
            this->power = 100;
        else
            this->power += 50;
    } else {
        ;
    }
    std::cout << this->name << " drinks a mysterious potion." << std::endl;
}

void Peasant::drink(const HealthPotion &potion) {
    HealthPotion pot = potion;
    if (this->health + 50 > 100)
        this->health = 100;
    else
        this->health += 50;
    std::cout << this->name << " feels rejuvenated." << std::endl;
}

void Peasant::drink(const PoisonPotion &potion) {
    PoisonPotion pot = potion;
    if (this->getHp() - 50 < 0)
        this->health = 0;
    else
        this->health -= 50;
    std::cout << this->name << " has been poisoned." << std::endl;
}

void Peasant::drink(const PowerPotion &potion) {
    PowerPotion pot = potion;
    if (this->power + 50 > 100)
        this->power = 100;
    else
        this->power += 50;
    std::cout << this->name << "\'s power is restored." << std::endl;
}
