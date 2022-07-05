//
// Created by Luca on 1/27/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_UNIQUEPOINTER_HPP
#define B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_UNIQUEPOINTER_HPP

#include <memory>

template <typename T>
class UniquePointer {
private:
    T *ptr;
public:
    explicit UniquePointer(T *p) { this->ptr = p; };
    explicit UniquePointer() { this->ptr = nullptr; };
    UniquePointer &operator=(T *p) {
        delete ptr;
        this->ptr = p;
        return *this;
    };
    T *get() const{
        return this->ptr;
    };
    void reset() {
        delete ptr;
        ptr = nullptr;
    };
    ~UniquePointer() {
        delete ptr;
    };
    T* operator->() const {
        return this->ptr;
    };
};

#endif //B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_UNIQUEPOINTER_HPP
