//
// Created by Luca on 1/25/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_FRUIT_HPP
#define B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_FRUIT_HPP

#include <string>

class Fruit {
    protected:
        int _vitamins;
        std::string _name;
    public:
        virtual std::string getName() const;
        int getVitamins() const;
};

#endif //B_PDG_300_BER_3_1_PDGD10AM_LUCA_PAULEKAT_FRUIT_HPP
