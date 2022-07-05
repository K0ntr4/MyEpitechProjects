//
// Created by Luca on 1/27/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_SHAREDPOINTER_HPP
#define B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_SHAREDPOINTER_HPP

#include <memory>
#include <unordered_map>

template <typename T>
class SharedPointer {
private:
    T *ptr;
    std::unordered_map <T *, int> *counter;
public:
    explicit SharedPointer(T *p) {
        this->ptr = p;
        this->counter = new std::unordered_map <T *, int>;
        (*this->counter)[this->ptr] = 1;
    };
    explicit SharedPointer() {
        this->ptr = nullptr;
        this->counter = new std::unordered_map <T *, int>;
    };
    SharedPointer(SharedPointer& shared) {
        this->ptr = shared.get();
        this->counter = shared.getCounter();
        this->incr_counter();
    };
    SharedPointer &operator=(T *p) {
        this->decr_counter();
        if ((*this->counter)[this->ptr] == 0)
            delete ptr;
        this->ptr = p;
        this->incr_counter();
        return *this;
    };
    SharedPointer &operator=(SharedPointer& shared) {
        this->decr_counter();
        if ((*this->counter)[this->ptr] == 0)
            delete ptr;
        this->ptr = shared.get();
        this->counter = shared.getCounter();
        this->incr_counter();
        return *this;
    };
    T *get() const{
        return this->ptr;
    };
    void reset() {
        this->decr_counter();
        if ((*this->counter)[this->ptr] == 0)
            delete ptr;
        ptr = nullptr;
    };
    ~SharedPointer() {
        this->decr_counter();
        if ((*this->counter)[this->ptr] == 0)
            delete ptr;
    };
    T* operator->() const {
        return this->ptr;
    };
    void incr_counter() { (*this->counter)[this->ptr] += 1; };
    void decr_counter() { (*this->counter)[this->ptr] -= 1; };
    std::unordered_map<T *, int>* getCounter() { return this->counter; };
};

#endif //B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_SHAREDPOINTER_HPP
