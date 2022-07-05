#ifndef _HEALTHPOTION_HPP_
    #define _HEALTHPOTION_HPP_

#include "IPotion.hpp"

class HealthPotion : public IPotion {
    private:
        std::string type;
    public:
        std::string getType() const { return this->type; };
        HealthPotion() { this->type = "health"; };
};

#endif
