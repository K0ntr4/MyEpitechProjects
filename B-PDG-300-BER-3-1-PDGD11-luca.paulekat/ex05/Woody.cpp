//
// Created by Luca on 1/26/22.
//

#include "Woody.hpp"

Woody::Woody(std::string name, const std::string &filename) {
    this->type = WOODY;
    this->name = std::move(name);
    this->picture.getPictureFromFile(filename);
}

void Woody::speak(std::string message) const {
    std::cout << "WOODY: " << this->name << " \"" << message << "\"" << std::endl;
}