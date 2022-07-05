#ifndef _PRIEST_HPP_
    #define _PRIEST_HPP_

#include "Enchanter.hpp"

class Priest : public Enchanter {
    public:
        Priest(std::string name, int power) : Peasant(name, power), Enchanter
        (name, power) {
            std::cout << this->name << " enters in the order." << std::endl;
        };
        ~Priest() override;
        void rest() override;
};

#endif
