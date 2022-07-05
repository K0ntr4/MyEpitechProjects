//
// Created by Luca on 1/26/22.
//

#include "Buzz.hpp"

#include <utility>

Buzz::Buzz(std::string name, const std::string &filename) {
    this->type = BUZZ;
    this->name = std::move(name);
    this->picture.getPictureFromFile(filename);
}

bool Buzz::speak(const std::string message) {
    std::cout << "BUZZ: " << this->name << " \"" << message << "\"" << std::endl;
    return true;
}

bool Buzz::speak_es(const std::string message) {
    std::cout << "BUZZ: " << this->name << " senorita " << " \"" << message << "\"" << " senorita" << std::endl;

    return true;
}
