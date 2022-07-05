//
// Created by Luca on 1/27/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_ARRAY_HPP
#define B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_ARRAY_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <ostream>

template <typename T, size_t S>
class Array {
private:
    T arr[S];
public:
    Array():arr{} {};
    template < typename U >
    Array <U , S > convert (const std::function<U(const T&)>& converter) const {
        Array <U, S> new_arr;
        for (size_t i = 0; i < S; i++)
            new_arr[i] = converter(arr[i]);
        return new_arr;
    };
    const T& operator[](const size_t ind) const {
        if (ind >= S)
            throw std::out_of_range("Out of range");
        return this->arr[ind];
    };
    T& operator[](size_t ind) {
        if (ind >= S)
            throw std::out_of_range("Out of range");
        return this->arr[ind];
    };
    [[nodiscard]] std :: size_t size() const { return S; };
    void forEach (const std::function<void(const T&)>& task) const {
        for (size_t i = 0; i < S; i++)
            task(arr[i]);
    };
};

template<typename T, size_t S>
std::ostream& operator<<(std::ostream& os, const Array<T, S> array) {
    size_t i = 0;

    os << "[";
    while (i < array.size() - 1) {
        os << array[i] << ", ";
        i++;
    }
    os << array[i] << "]";
    return os;
}

#endif //B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_ARRAY_HPP
