//
// Created by Luca on 1/24/22.
//

#ifndef _POWERPOTION_HPP_
    #define _POWERPOTION_HPP_

#include "IPotion.hpp"

class PowerPotion : public IPotion {
    private:
        std::string type;
    public:
        std::string getType() const { return this->type; };
        PowerPotion() { this->type = "power"; };
};

#endif
