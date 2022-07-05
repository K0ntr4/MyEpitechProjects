//
// Created by Luca on 1/25/22.
//

#include "SimplePtr.hpp"
#include <memory>

SimplePtr::SimplePtr(BaseComponent *rawPtr) {
    this->_rawPtr = rawPtr;
}

SimplePtr::~SimplePtr() {
    delete this->_rawPtr;
}

BaseComponent *SimplePtr::get() const {
    return this->_rawPtr;
}
