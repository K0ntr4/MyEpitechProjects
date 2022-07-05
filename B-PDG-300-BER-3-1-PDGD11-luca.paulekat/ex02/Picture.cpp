//
// Created by Luca on 1/26/22.
//

#include "Picture.hpp"

Picture::Picture(const std::string &file) {
    getPictureFromFile(file);
}

Picture::Picture() {
    this->data = "";
}

bool Picture::getPictureFromFile(const std::string &file) {
    std::ifstream f(file, std::ios::in);
    std::stringstream buffer;

    if (!f) {
        this->data = "ERROR";
        return false;
    }
    buffer << f.rdbuf();
    this->data = buffer.str();
    return true;
}

Picture::Picture(const Picture &other) {
    this->data = std::string(other.data);
}

Picture& Picture::operator=(const Picture &other) noexcept {
    this->data = std::string(other.data);
    return *this;
}
