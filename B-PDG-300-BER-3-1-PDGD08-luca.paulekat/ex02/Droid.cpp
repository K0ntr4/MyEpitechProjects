#include "Droid.hpp"

Droid::Droid(std::string serial) : Attack(25), Toughness(15) {
    std::string *status = new std::string;

    *status = "Standing by";
    this->ID = serial;
    this->Energy = 50;
    this->Status = status;
    this->BattleData->setExp(0);
    std::cout << "Droid \'" << this->ID << "\' Activated" << std::endl;
}

Droid *Droid::copy(std::string serial) {
    Droid *copy = new Droid(serial);

    copy->setId(this->getId());
    copy->setStatus(this->getStatus());
    copy->setEnergy(this->getEnergy());
    return copy;
}

Droid::~Droid() {
    std::cout << "Droid \'" << this->ID << "\' Destroyed" << std::endl;
}

Droid::Droid(const Droid& second) : Attack(25), Toughness(15){
    this->Energy = 50;
    this->setId(second.getId());
    this->setBattleData(second.getBattleData());
    this->setStatus(second.getStatus());
    std::cout << "Droid \'" << this->getId() << "\' Activated, Memory Dumped" << std::endl;
}

std::string Droid::getId() const {
    return this->ID;
}

void Droid::setId(std::string serial) {
    this->ID = serial;
}

size_t Droid::getEnergy() const {
    return this->Energy;
}

void Droid::setEnergy(size_t energy) {
    this->Energy = energy;
}

size_t Droid::getAttack() const {
    return this->Attack;
}

size_t Droid::getToughness() const {
    return this->Toughness;
}

std::string *Droid::getStatus() const {
    return this->Status;
}

void Droid::setStatus(std::string *status) {
    this->Status = status;
    this->Energy -= 10;
}

bool Droid::operator==(const Droid& second) {
    if(*this->Status != *second.getStatus())
        return false;
    return true;
};

void Droid::operator<<(size_t& energy) {
    int dif = 100 - this->Energy;
    if (dif > 0 && dif <= 100) {
        this->Energy += dif;
        energy -= dif;
    }
}

void Droid::operator<<(Droid& second) {
    int dif = second.Energy - this->Energy;
    if (dif > 0 && dif <= 100) {
        this->Energy += dif;
        second.Energy -= dif;
    }
}

void Droid::operator=(const Droid& second) {
    this->setId(second.getId());
    this->setStatus(second.getStatus());
    this->setBattleData(second.getBattleData());
}

std::ostream& operator<<(std::ostream& os, const Droid &droid) {
    os << "Droid \'" << droid.getId() << "\', " << *droid.getStatus() << ", " << droid.getEnergy();
    return os;
}

DroidMemory *Droid::getBattleData() const {
    return this->BattleData;
}

void Droid::setBattleData(DroidMemory *mem) {
    this->BattleData = mem;
}

bool Droid::operator()(const std::string *task, size_t exp) {
    std::string task_name = *task;

    this->Energy -= 10;
    if (this->Energy <= 0) {
        std::string *battery = new std::string("Battery Low");
        this->Energy = 0;
        this->Status = battery;
        return false;
    }
    if (exp > this->getBattleData()->getExp()) {
        std::string *failed = new std::string(task_name.append(" - Failed!"));
        this->Status = failed;
        this->BattleData->setExp(this->BattleData->getExp() + exp);
        return false;
    }
    this->BattleData->setExp(this->BattleData->getExp() + exp / 2);
    std::string *completed = new std::string(task_name.append(" - Completed!"));
    this->Status = completed;
    return true;

}