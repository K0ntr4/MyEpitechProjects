//
// Created by Luca on 1/25/22.
//

#include "RefPtr.hpp"
#include <memory>

RefPtr::RefPtr(BaseComponent *rawPtr) {
    this->_rawPtr = std::auto_ptr<BaseComponent *>(rawPtr);
}

RefPtr::~RefPtr() {
    ;
}

BaseComponent *RefPtr::get() const {
    return this->_rawPtr;
}

RefPtr::RefPtr(RefPtr const &other) {
    this->_rawPtr = other._rawPtr;
}

RefPtr& RefPtr::operator=(RefPtr const &other) {
    this->_rawPtr = other._rawPtr;
    return (RefPtr&)other;
}