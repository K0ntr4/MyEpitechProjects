//
// Created by Luca on 1/26/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_TOYSTORY6_HPP
#define B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_TOYSTORY6_HPP

#include "Toy.hpp"

class ToyStory {
    public:
        static void tellMeAStory(const std::string &filename, Toy &toy1, bool (Toy::*func1)(std::string), Toy &toy2,
                                 bool (Toy::*func2)(std::string));
};

#endif
