//
// Created by Luca on 1/26/22.
//

#include "Toy.hpp"

Toy::ToyType Toy::getType() const {
    return this->type;
}

std::string Toy::getName() const {
    return this->name;
}

void Toy::setName(std::string name) {
    this->name = name;
}

bool Toy::setAscii(const std::string &file) {
    if (!this->picture.getPictureFromFile(file)) {
        this->error.type = Error::PICTURE;
        return false;
    }
    return true;
}

std::string Toy::getAscii() const {
    return this->picture.data;
}

Toy::Toy() {
    this->type = BASIC_TOY;
    this->name = "toy";
    this->picture.data = "";
}

Toy::Toy(Toy::ToyType type, std::string name, const std::string &filename) {
    this->type = type;
    this->name = std::move(name);
    this->picture.getPictureFromFile(filename);
}

Toy::Toy(const Toy &other) {
    this->name = std::string(other.getName());
    this->type = Toy::ToyType(other.getType());
    this->picture.data = std::string(other.getAscii());
}

Toy& Toy::operator=(const Toy &other) noexcept {
    this->name = std::string(other.getName());
    this->type = Toy::ToyType(other.getType());
    this->picture = other.picture;
    return *this;
}

bool Toy::speak(const std::string message) {
    std::cout << this->name << " \"" << message << "\"" << std::endl;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Toy &toy) {
    os << toy.getName() << std::endl;
    os << toy.getAscii() << std::endl;
    return os;
}

Toy& Toy::operator<<(const std::string str) {
    this->picture.data = str;
    return *this;
}

bool Toy::speak_es(const std::string message) {
    std::string *str = new std::string (message);
    delete str;
    this->error.type = Error::SPEAK;
    return false;
}

std::string Toy::Error::what() const {
    if (this->where() == "setAscii")
        return "bad new illustration";
    else if (this->where() == "speak_es")
        return "wrong mode";
    else
        return "";
}

std::string Toy::Error::where() const {
    if (this->type == SPEAK)
        return "speak_es";
    else if (this->type == PICTURE)
        return "setAscii";
    else
        return "";
}

Toy::Error::Error(ErrorType err) {
    this->type = err;
}

Toy::Error Toy::getLastError() {
    return this->error;
}