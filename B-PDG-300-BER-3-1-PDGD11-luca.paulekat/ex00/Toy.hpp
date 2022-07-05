//
// Created by Luca on 1/26/22.
//

#ifndef B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_TOY0_HPP
#define B_PDG_300_BER_3_1_PDGD11_LUCA_PAULEKAT_TOY0_HPP

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType { BASIC_TOY, ALIEN };
        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(const std:: string &file);
        std::string getAscii() const;
        Toy();
        Toy(ToyType type, std::string name, const std::string &filename);
    private:
        std::string name;
        ToyType type;
        Picture picture;

};

#endif
