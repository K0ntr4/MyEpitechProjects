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
    return this->picture.getPictureFromFile(file);
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

void Toy::speak(std::string message) const {
    std::cout << this->name << " \"" << message << "\"" << std::endl;
}
