//
// Created by Luca on 1/27/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_ALGORITHM_HPP
#define B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_ALGORITHM_HPP

template <typename T>
void swap(T& a, T& b) {
    T c = b;
    b = a;
    a = c;
}

template <typename T>
T min(T a, T b) {
    if (a < b)
        return a;
    return b;
}

template <typename T>
T max(T a, T b) {
    if (b < a)
        return a;
    return b;
}

template <typename T>
T clamp(T a, T b, T c) {
    if ((b < a && a < c) || (c < a && a < b))
        return a;
    else if ((a < b && b < c) || (c < b && b < a))
        return b;
    else if ((b < c && c < a) || (a < c && c < b))
        return c;
    return a;
}

#endif //B_PDG_300_BER_3_1_PDGD12_LUCA_PAULEKAT_ALGORITHM_HPP
