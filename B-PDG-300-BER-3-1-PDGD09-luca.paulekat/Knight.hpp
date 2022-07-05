#ifndef _KNIGHT_HPP_
    #define _KNIGHT_HPP_

#include "Peasant.hpp"

class Knight : virtual public Peasant {
    public:
        Knight(std::string name, int power) : Peasant(name, power) {
            std::cout << this->name << " vows to protect the kingdom." << std::endl;
        };
        ~Knight() override;
        int attack () override;
        int special () override;
        void rest() override;
};

#endif
