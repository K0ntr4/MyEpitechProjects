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
