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
