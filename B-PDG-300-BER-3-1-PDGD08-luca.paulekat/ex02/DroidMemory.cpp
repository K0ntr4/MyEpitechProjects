#include "DroidMemory.hpp"

DroidMemory::DroidMemory() {
    this->setExp(0);
    this->setFingerprint(random());
}

DroidMemory::DroidMemory(const DroidMemory& droid) {
    this->setExp(droid.getExp());
    this->setFingerprint(random());
}

size_t DroidMemory::getFingerprint() const{
    return this->Fingerprint;
}

void DroidMemory::setFingerprint(size_t fingerprint) {
    this->Fingerprint = fingerprint;
}

size_t DroidMemory::getExp() const{
    return this->Exp;
}

void DroidMemory::setExp(size_t exp) {
    this->Exp = exp;
}

void DroidMemory::operator<<(const DroidMemory& second) {
    this->Exp += second.getExp();
    this->Fingerprint = (this->Fingerprint ^ second.getFingerprint());
}

void DroidMemory::operator<<( const size_t& exp) {
    this->Exp += exp;
    this->Fingerprint = (this->Fingerprint ^ exp);
}

void DroidMemory::operator>>(DroidMemory& second) {
    second.Exp += this->Exp;
    second.Fingerprint = (second.Fingerprint ^ this->getFingerprint());
}

void DroidMemory::operator>>(size_t& exp) {
    exp += this->Exp;
    exp = (exp ^ this->getFingerprint());
}

void DroidMemory::operator+=(const size_t& exp) {
    this->Exp += exp;
    this->Fingerprint = (this->Fingerprint ^ exp);
}

DroidMemory DroidMemory::operator+=(const DroidMemory& second) {
    this->Exp += second.getExp();
    this->Fingerprint = (this->Fingerprint ^ second.getFingerprint());
    return *this;
}

DroidMemory DroidMemory::operator+(const size_t& exp) {
    DroidMemory new_mem;
    new_mem.setExp(exp);
    new_mem.setFingerprint(exp ^ this->getFingerprint());
    return new_mem;
}

DroidMemory DroidMemory::operator+(const DroidMemory& second) {
    DroidMemory new_mem;
    new_mem.setExp(this->getExp() + second.getExp());
    new_mem.setFingerprint((second.getFingerprint() ^ this->getFingerprint()));
    return new_mem;
}

std::ostream& operator<<(std::ostream& os, const DroidMemory& droid) {
    os << "DroidMemory \'" << droid.getFingerprint() << "\', " << droid.getExp();
    return os;
}

void DroidMemory::operator=(const DroidMemory& second) {
    this->Exp = second.getExp();
    this->Fingerprint = second.getFingerprint();
}

bool DroidMemory::operator==(const DroidMemory& second) {
    if (this->Exp != second.getExp() || this->Fingerprint != second.getFingerprint())
        return false;
    return true;
}

bool DroidMemory::operator<(const DroidMemory& second) {
    if (this->Exp < second.getExp())
        return true;
    return false;
}

bool DroidMemory::operator<=(const DroidMemory& second) {
    if (this->Exp <= second.getExp())
        return true;
    return false;
}

bool DroidMemory::operator>=(const DroidMemory& second) {
    if (this->Exp >= second.getExp())
        return true;
    return false;
}

bool DroidMemory::operator==(const size_t& exp) {
    if (this->Exp != exp || this->Fingerprint != exp)
        return false;
    return true;
}

bool DroidMemory::operator<(const size_t& exp) {
    if (this->Exp < exp)
        return true;
    return false;
}

bool DroidMemory::operator<=(const size_t& exp) {
    if (this->Exp <= exp)
        return true;
    return false;
}

bool DroidMemory::operator>=(const size_t& exp) {
    if (this->Exp >= exp)
        return true;
    return false;
}
