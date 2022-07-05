#ifndef _PALADIN_HPP_
#define _PALADIN_HPP_

#include "Knight.hpp"
#include "Priest.hpp"
#include "Peasant.hpp"

class Paladin : public Knight, public Priest {
    public:
        Paladin(std::string name, int power) : Peasant(name, power), Knight(name, power), Priest(name, power) {
            std::cout << this->name << " fights for the light." << std::endl;
        };
        ~Paladin() override;
        int attack () override;
        int special () override;
        void rest() override;
};

#endif
