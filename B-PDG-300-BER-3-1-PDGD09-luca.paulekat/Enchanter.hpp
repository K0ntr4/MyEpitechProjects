#ifndef _ENCHANTER_HPP_
    #define _ENCHANTER_HPP_

#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
    public:
        Enchanter(std::string name, int power) : Peasant(name, power) {
            std::cout << this->name << " learns magic from his spellbook." << std::endl;
        };
        ~Enchanter();
        int attack () override;
        int special () override;
        void rest() override;
};

#endif
