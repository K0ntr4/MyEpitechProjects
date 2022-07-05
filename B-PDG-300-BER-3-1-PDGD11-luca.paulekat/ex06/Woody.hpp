//
// Created by Luca on 1/26/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_WOODY6_HPP
#define B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_WOODY6_HPP

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(std::string name, const std::string &filename = "woody.txt");
        bool speak(const std::string message) override;
};

#endif
