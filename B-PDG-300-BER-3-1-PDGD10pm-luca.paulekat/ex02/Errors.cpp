//
// Created by Luca on 1/25/22.
//

#include "Errors.hpp"

std::string const &NasaError::getComponent() const {
    return this->_component;
}

NasaError::NasaError(const std::string &message, const std::string &component) {
    this->_component = component;
    this->_message = message;
}
