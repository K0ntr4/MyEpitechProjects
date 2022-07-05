#ifndef _POISONPOTION_HPP_
    #define _POISONPOTION_HPP_

#include "IPotion.hpp"

class PoisonPotion : public IPotion {
    private:
        std::string type;
    public:
        std::string getType() const { return this->type; };
        PoisonPotion() { this->type = "poison"; };
};

#endif
