//
// Created by Luca on 1/26/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_BUZZ5_HPP
#define B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_BUZZ5_HPP

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(std::string name, const std::string &filename = "buzz.txt");
        void speak(std::string message) const override;
        bool speak_es(const std::string message) override;
};

#endif
